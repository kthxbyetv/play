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
#include <avr/wdt.h>
#include <avr/sleep.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "utils.h"
#include "codes.h"
#include "main.h"

extern const PGM_P *ir_codes[];
extern const uint8_t ir_codes_length;

PGM_P code_ptr;
uint8_t bitsleft_r = 0;
uint8_t bits_r=0;

void sendCodeElement(uint16_t on_time, uint16_t off_time, uint8_t PWM_enabled) {
	// Reset the timer
	TCNT0 = 0;
	TIFR = 0;

	if (PWM_enabled) {
		// Turn on PWM
		TCCR0A =_BV(COM0A0) | _BV(WGM01);
		TCCR0B = _BV(CS00);
	} else {
		// Turn on LED
		PORTB |= _BV(IR_LED);
	}

	delayTenMicroseconds(on_time);

	// Turn off PWM
	TCCR0A = 0;
  	TCCR0B = 0;

  	// Turn off IR LED
  	PORTB &= ~_BV(IR_LED);

  	delayTenMicroseconds(off_time);
}

uint8_t readBits(uint8_t count) {
	uint8_t counter;
	uint8_t tmp = 0;

	for (counter = 0; counter < count; ++counter) {
		// Buffer is empty
		if (bitsleft_r == 0) {
			// Read a new code + reset buffer counter
			bits_r = pgm_read_byte(code_ptr++);
			bitsleft_r = 8;
		}

		// We read 1 bit from the buffer, so we decrease the buffer counter
		bitsleft_r--;

		// We shift the bits
		tmp |= (((bits_r >> (bitsleft_r)) & 1) << (count - 1 - counter));
	}

	return tmp;
}

int main(void) {
	// Variables initialisation
	uint16_t on_time, off_time;

	// Setting ACT and IR LEDs as outputs
	DDRB = _BV(ACT_LED) | _BV(IR_LED);

	//quickLEDFlash();

	// 
	GIMSK = _BV(INT0);

	// Enable watchdog and enable interrupts
	wdt_enable(WDTO_8S);
	sei();

	uint8_t current_code = 0;

	// Playing the codes
	for (current_code = 0; current_code < ir_codes_length; ++current_code) {
		// To keep the watchdog from reseting while sending a code
		wdt_reset();

		code_ptr = (PGM_P)pgm_read_word(ir_codes+current_code);
		
		// Read the code carrier frequency + set it as OCR0A frequency
		const uint8_t freq = pgm_read_byte(code_ptr++);
		OCR0A = freq;
		
		// Read the number of pairs
		const uint8_t numpairs = pgm_read_byte(code_ptr++);
		
		// Read the compression level
		const uint8_t bitcompression = pgm_read_byte(code_ptr++);
		
		// Read the pulse-time table
		const PGM_P time_ptr = (PGM_P)pgm_read_word(code_ptr);
		
		// We have just read two byte, so we have to increment code_ptr
		code_ptr+=2;
		
		for (uint8_t i = 0; i < numpairs; ++i) {
			// Read the next 'n' bits as indicated by the compression variable
			// The multiply by 4 because there are 2 timing numbers per pair
			// and each timing number is one word long, so 4 bytes total!
			uint8_t ti = (readBits(bitcompression)) * 4;
		
			// Both on_time and off_time are two 16 bits informations
			on_time = pgm_read_word(time_ptr+ti);
			off_time = pgm_read_word(time_ptr+ti+2);
		
			// Send the code to the IR leds
			sendCodeElement(on_time,off_time,(freq != 0));
		}
		
		// Flush buffer counter
		bitsleft_r=0;
		
		quickLEDFlash();
		
		// Delay between codes
		delayTenMicroseconds(CODES_DELAY);
	}

	// Disable watchdog
	wdt_disable();

	// Put CPU in sleep mode
	GIMSK = _BV(INT0);
	MCUCR = _BV(SM1) | _BV(SE);
	sleep_cpu();
}

ISR(INT0_vect) {
	// This ISR is responsible of waking up the AVR
	// We enable the watchdog to kill the infinite loop
	wdt_enable(WDTO_15MS);
	for (;;) {}
}