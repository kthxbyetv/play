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
#include "a_v4.h"

extern const PGM_P * const EUpowerCodes[] PROGMEM;
extern const uint8_t num_NAcodes, num_EUcodes;

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

uint8_t bitsleft_r = 0;
uint8_t bits_r=0,grenade=0;
PGM_P code_ptr;

// we cant read more than 8 bits at a time so dont try!
uint8_t read_bits(uint8_t count)
{
  uint8_t i;
  uint8_t tmp=0;
  
  // we need to read back count bytes
  for (i=0; i<count; i++) {
    // check if the 8-bit buffer we have has run out
    if (bitsleft_r == 0) {
      // in which case we read a new byte in
      bits_r = pgm_read_byte(code_ptr++);
      // and reset the buffer size (8 bites in a byte)
      bitsleft_r = 8;
    }
    // remove one bit
    bitsleft_r--;
    // and shift it off of the end of 'bits_r'
    tmp |= (((bits_r >> (bitsleft_r)) & 1) << (count-1-i));
  }
  // return the selected bits in the LSB part of tmp
  return tmp; 
}

ISR(INT0_vect) {
	// To reset the AVR without relying on hardware,
	// we enable the watchdog then launch an endless loop
	// so that the watchdog will detect it and reset the AVR
	wdt_enable(WDTO_15MS);
	for(;;) {}
}

void setgrenade(void) {
	uint8_t i;
  	grenade=9;
	quickflashLEDx(5);
  GIMSK = _BV(INT0);
	  sei();
			for (i=0;i<15;i++) {
			  delay_ten_us(65500); // 10s
			  wdt_reset();
		    }
}

int main(void) {
	// Variables initialisation
	uint16_t ontime, offtime;
	uint8_t j,i,loopgrn;

	// Clearing watchdogs flags and disabling it
	MCUSR = 0;
	WDTCR = _BV(WDCE) | _BV(WDE);
	WDTCR = 0;

	// Set ACT LED and IR LED pins as outputs
	DDRB = _BV(LED) | _BV(IRLED);

	// Set up a pullup on the pin which is connected to the button
	PORTB = 0b00000110;

	delay_ten_us(6000);

	while(!bit_is_set(PINB,PB2)) {};
	delay_ten_us(6000);

	for (i=0;i<255;i++) {
		delay_ten_us(300);
		if (!bit_is_set(PINB,PB2)) {
			setgrenade();
			break;
		}
	}

	// Set an interrupt on INT0 (which is PB2)
	GIMSK = _BV(INT0);

	// Turn on the watchdog with a 1 second long timeout
	wdt_enable(WDTO_8S);

	// Turn on interrupts
	sei();

	for (;;) {
		for(loopgrn=0;loopgrn<grenade+1;loopgrn++) {
			j = num_EUcodes;

			if (grenade) quickflashLEDx(5);

			for(i=0 ; i < j; i++) {
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

				for (uint8_t k=0; k<numpairs; k++) {
					uint8_t ti;

					// Read the next 'n' bits as indicated by the compression variable
					// The multiply by 4 because there are 2 timing numbers per pair
					// and each timing number is one word long, so 4 bytes total!
					ti = (read_bits(bitcompression)) * 4;

					// read the onTime and offTime from the program memory
					ontime = pgm_read_word(time_ptr+ti);  // read word 1 - ontime
					offtime = pgm_read_word(time_ptr+ti+2);  // read word 2 - offtime

					// transmit this codeElement (ontime and offtime)
					xmitCodeElement(ontime, offtime, (freq!=0));  
				}

				//Flush remaining bits, so that next code starts
				//with a fresh set of 8 bits.
				bitsleft_r=0;	

				// delay 250 milliseconds before transmitting next POWER code
				delay_ten_us(25000);

				// visible indication that a code has been output.
				if (!grenade) quickflashLEDx(1); 
			}
			
			if (grenade) {
				PORTB = 0b00000110;	// Pullup
				for (i=0;i<44;i++) {
					delay_ten_us(65500); // 29s
					wdt_reset();
				}
			}
		}  

		// We are done, no need for a watchdog timer anymore
		wdt_disable();

		// flash the visible LED on PB0  4 times to indicate that we're done
		quickflashLEDx(10);

		// Shut down the timer
		TCCR0A = 0;

		// Setting the pullup on the button
		PORTB = 0b00000100;

		// Make sure our watchdog is disabled
		wdt_disable();

		// Set an interrupt on INT0 (which is PB2)
		GIMSK = _BV(INT0);

		// Put the CPU into sleep mode
		MCUCR = _BV(SM1) |  _BV(SE);
		sleep_cpu();

		// Reset the AVR when it wakes up
		wdt_enable(WDTO_15MS);
		for(;;) {}
	}
}



/****************************** LED AND DELAY FUNCTIONS ********/


// This function delays the specified number of 10 microseconds
// it is 'hardcoded' and is calibrated by adjusting DELAY_CNT 
// in main.h Unless you are changing the crystal from 8mhz, dont
// mess with this.
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

void quickflashLEDx( uint8_t x ) {
	while(x--) {
		delay_ten_us(15000);
		PORTB |= _BV(LED);
		delay_ten_us(1000);
		PORTB &=~ _BV(LED);
		wdt_reset();
	}
}
