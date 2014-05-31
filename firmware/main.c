/*
kthxbyetv (play) firmware
coded by kthxbyetv team

based on the code of :
* Mitch Altman
* Limor Fried
* Kevin Timmerman
* Damien Good
* Furrtek

distributed under Creative Commons 2.5 -- Attib & Share Alike
*/

#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include "hardware.h"
#include "utils.c"
#include "codes.c"

/* No use, because we include codes.c because of the new makefile
extern const PGM_P * const EUpowerCodes[] PROGMEM;
extern const uint8_t num_EUcodes;
*/

PGM_P code_ptr;
volatile unsigned short working = 0;

uint8_t read_bits(uint8_t count, uint8_t *bitsleft_r, uint8_t *bits_r) {
	uint8_t i, tmp = 0;

	// we need to read back count bytes
	for(i = 0; i < count; i++) {
		// check if the 8-bit buffer we have has run out
		if(*bitsleft_r == 0) {
			// in which case we read a new byte in
			*bits_r = pgm_read_byte(code_ptr++);

			// and reset the buffer size (8 bites in a byte)
			*bitsleft_r = 8;
		}

		// remove one bit
		(*bitsleft_r)--;

		// and shift it off of the end of 'bits_r'
		tmp |= ((((*bits_r) >> (*bitsleft_r)) & 1) << (count-1-i));
	}

	// return the selected bits in the LSB part of tmp
	return tmp;
}

ISR(INT0_vect) {
	// Set working to 0, so it will break the loop and sleep the chip
	working = 0;
}

int main(void) {
	// Variables initialisation
	uint16_t ontime, offtime;
	uint8_t i, k, ti;
	// Such buffers
	uint8_t bitsleft_r = 0, bits_r = 0;

	// Clearing watchdogs flags and disabling it
	MCUSR = 0;
	WDTCR = _BV(WDCE) | _BV(WDE);
	WDTCR = 0;

	// Set ACT LED and IR LED pins as outputs
	DDRB = _BV(LED) | _BV(IRLED);

	// Set up a pullup on the pin which is connected to the button
	PORTB = _BV(BUTTON);

	delay_ten_us(6000);

	// Set an interrupt on INT0 (which is PB2)
	GIMSK = _BV(INT0);

	// Turn on the watchdog with a 1 second long timeout
	wdt_enable(WDTO_8S);

	// Turn on interrupts
	sei();

	// We start working, so let's define the variable
	working = 1;
	for(i=0 ; i < num_EUcodes; i++) {
		// Check the interrupt
		if(working == 0)
			break;

		// Reset our watchdog timer, so it won't reset the AVR while sending a code
		wdt_reset();

		// Getting the address of our code
		code_ptr = (PGM_P)pgm_read_word(EUpowerCodes+i);

		// Read the carrier frequency
		const uint8_t freq = pgm_read_byte(code_ptr++);

		// set OCR for Timer1 to output this code's carrier frequency
		OCR0A = freq;

		// Get the number of pairs
		const uint8_t numpairs = pgm_read_byte(code_ptr++);

		// Get the number of bits we use to index into the timer table
		const uint8_t bitcompression = pgm_read_byte(code_ptr++);

		// Get pointer (address in memory) to pulse-times table
		const PGM_P time_ptr = (PGM_P)pgm_read_word(code_ptr);
		code_ptr+=2;

		for (k = 0; k < numpairs; k++) {
			// Read the next 'n' bits as indicated by the compression variable
			// The multiply by 4 because there are 2 timing numbers per pair
			// and each timing number is one word long, so 4 bytes total!
			// Pointer > global, bitch
			ti = (read_bits(bitcompression, &bitsleft_r, &bits_r)) * 4;

			// read the onTime and offTime from the program memory
			ontime = pgm_read_word(time_ptr+ti);  // read word 1 - ontime
			offtime = pgm_read_word(time_ptr+ti+2);  // read word 2 - offtime

			// transmit this codeElement (ontime and offtime)
			xmitCodeElement(ontime, offtime, (freq!=0));
		}

		// Flush remaining bits, so that next code starts
		// with a fresh set of 8 bits. That's a lot of bites.
		bitsleft_r = 0;

		// delay 250 milliseconds before transmitting next POWER code
		delay_ten_us(25000);// TODO : decrease this number to accelerate the process ?

		// visible indication that a code has been output.
		blinkLED(1);
	}
	// My job is done, fuck you all
	working = 0;

	// We are done, no need for a watchdog timer anymore
	wdt_disable();

	// flash the visible LED on PB0 4 times to indicate that we're done
	blinkLED(5);

	// Shut down the timer
	TCCR0A = 0;

	/* CHECK : Is this really necessary ? It's already defined at the beginning of main
	// Setting the pullup on the button
	// PORTB = _BV(BUTTON);
	*/

	// Make sure our watchdog is disabled
	wdt_disable();

	/* CHECK : This too ?
	// Set an interrupt on INT0 (which is PB2)
	// GIMSK = _BV(INT0);
	*/

	// Put the CPU into sleep mode
	MCUCR = _BV(SM1) | _BV(SE);
	sleep_cpu();

	// A little delay, otherwise it won't work and the CPU will return in sleep mode immediately
	delay_ten_us(5000);

	// Reset the AVR when it wakes up
	// To reset the AVR without relying on hardware,
	// we enable the watchdog then launch an endless loop
	// so that the watchdog will detect it and reset the AVR
	wdt_enable(WDTO_15MS);
	for(;;) {}
}
