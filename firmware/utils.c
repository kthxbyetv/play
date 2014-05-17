/*
	kthxbyetv (play) firmware
	coded by kthxbyetv team

	based on the code of :
	 * Mitch Altman
	 * Limor Fried
	 * Kevin Timmerman
	 * Damien Good

	distributed under Creative Commons 2.5 -- Attib & Share Alike
*/

#include <avr/io.h>
#include <avr/wdt.h>
#include "main.h"
#include "utils.h"

void quickLEDFlash(void) {
	PORTB |= (1 << ACT_LED);
	delayTenMicroseconds(3000);
	PORTB &= ~(1 << ACT_LED);
}

void delayTenMicroseconds(uint16_t us) {
	uint8_t timer;
	while (us != 0) {
	// for 8MHz we want to delay 80 cycles per 10 microseconds
	for (timer=0; timer <= 11; timer++) {
			NOP;
			NOP;
		}
		NOP;
		us--;
	}
}