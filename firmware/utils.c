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

void xmitCodeElement(uint16_t on_time, uint16_t off_time, uint8_t is_pwm) {
	// Reset the timers so they are aligned + clean timer flags
	TCNT0 = 0;
	TIFR = 0;

	if(is_pwm) {
		// Turn on PWM timer
		TCCR0A =_BV(COM0A0) | _BV(WGM01);
		TCCR0B = _BV(CS00);
	} else {
		PORTB |= _BV(IRLED);
	}
	
	delay_ten_us(on_time);

	// Turn off PWM timer
	TCCR0A = 0;
	TCCR0B = 0;
	
	PORTB &= ~_BV(IRLED);

	delay_ten_us(off_time);
}