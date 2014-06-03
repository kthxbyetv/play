/*
kthxbyetv (play) firmware
coded by kthxbyetv team

based on the code of :
* Mitch Altman
* Limor Fried
* Kevin Timmerman
* Damien Good
* Furrtek

Distributed under Creative Commons 2.5 -- Attib & Share Alike
*/

#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include "hardware.h"
#include "utils.c"
#include "codes.c"

// We want to count the number of clicks on the button
volatile char clicks = 0;

uint8_t read_bits(uint8_t count, uint8_t *bitsleft_r, uint8_t *bits_r, PGM_P *code_ptr) {
	uint8_t i, tmp = 0;

	// we need to read back count bytes
	for(i = 0; i < count; i++) {
		// check if the 8-bit buffer we have has run out
		if(*bitsleft_r == 0) {
			// in which case we read a new byte in
			*bits_r = pgm_read_byte((*code_ptr)++);

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
	// The button is pressed, we count one click more
	clicks++;

	// To debounce, we wait a little.
	// When there will be bounces, the interrupt will wait and not increment
	delay_ten_us(25000);
}

int main(void) {
	// Variables initialisation
	uint16_t ontime, offtime;
	uint8_t i, k, ti,
	// Such buffers
	bitsleft_r, bits_r;
	PGM_P code_ptr;

	// Clearing watchdog's flags and disabling it
	MCUSR = 0;
	WDTCR = _BV(WDCE) | _BV(WDE);
	WDTCR = 0;

	// Set ACT LED and IR LED pins as outputs
	DDRB = _BV(LED) | _BV(IRLED);

	// Set up a pullup on the pin which is connected to the button
	PORTB = _BV(BUTTON);

	// Set an interrupt on INT0 (which is PB2)
	GIMSK = _BV(INT0);

	// Turn on interrupts
	sei();

	for(;;) {
		// A little delay, otherwise it won't work and the CPU will return in sleep mode immediately
		delay_ten_us(5000);

		// Turn on the watchdog with a 1 second long timeout
		wdt_enable(WDTO_8S);

		// Clear the clicks counter
		clicks = 0;

		for(i = 0; i < NUM_ELEM(powerCodes); i++) {
			// Check the interrupt
			if(clicks != 0)
				break;

			// Reset our watchdog timer, so it won't reset the AVR while sending a code
			wdt_reset();

			// Getting the address of our code
			code_ptr = (PGM_P)pgm_read_word(powerCodes+i);

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
			code_ptr += 2;

			// Flush remaining bits, so that the code starts
			// with a fresh set of 8 bits. That's a lot of bites.
			bitsleft_r = 0;

			for(k = 0; k < numpairs; k++) {
				// Read the next 'n' bits as indicated by the compression variable
				// The multiply by 4 because there are 2 timing numbers per pair
				// and each timing number is one word long, so 4 bytes total!
				// Pointers > globals, bitch
				ti = (read_bits(bitcompression, &bitsleft_r, &bits_r, &code_ptr)) * 4;

				// read the onTime and offTime from the program memory
				ontime = pgm_read_word(time_ptr+ti);	// read word 1 - ontime
				offtime = pgm_read_word(time_ptr+ti+2);	// read word 2 - offtime

				// transmit this codeElement (ontime and offtime)
				xmitCodeElement(ontime, offtime, (freq != 0));
			}

			// Visible indication that a code has been output.
			blinkLED(1);

			// Delay 250 milliseconds before transmitting next POWER code
			delay_ten_us(25000);
		}
		// We are done, no need for a watchdog timer anymore
		wdt_disable();

		// If we pressed the button one time, we reset, otherwise we enter into sleep mode
		if(clicks != 1) {
			// Flash the visible LED on PB0 4 times to indicate that we're done
			blinkLED(4);

			// Put the CPU into sleep mode
			MCUCR = _BV(SM1) | _BV(SE);
			sleep_cpu();
		}
		// The clicks counter is reseted at the beginning of the loop
	}
}
