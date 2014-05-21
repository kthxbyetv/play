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
#include "hardware.h"
#include "utils.h"

void blinkLED(uint8_t count) {
	while(count--) {
		delay_ten_us(15000);
		PORTB |= _BV(LED);
		delay_ten_us(1000);
		PORTB &=~ _BV(LED);
		wdt_reset();
	}
}

void delay_ten_us(uint16_t us) {
	uint8_t timer;
	while (us != 0) {
		for (timer=0; timer <= DELAY_CNT; timer++) {
			NOP;
			NOP;
		}
		NOP;
		us--;
	}
}