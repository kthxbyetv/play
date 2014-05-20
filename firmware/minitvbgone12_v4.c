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
#include "a_v4.h"
#include "util.h"

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
  wdt_enable(WDTO_15MS); // 1 second long timeout
	  for(;;) {} // Watchdog lol
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
  uint16_t ontime, offtime;
  uint8_t j,i,loopgrn;

  //TCCR1 = 0;		   	   // Turn off PWM/freq gen, should be off already
  //TCCR0A = 0;
  //TCCR0B = 0;

  MCUSR = 0;                     // clear watchdog flag
  WDTCR = _BV(WDCE) | _BV(WDE);  // enable WDT disable

  WDTCR = 0;                     // disable WDT while we setup

  //GIMSK = 0;

  DDRB = _BV(LED) | _BV(IRLED);  // set the visible and IR LED pins to outputs
  PORTB = 0b00000110;			 // Pullup

  delay_ten_us(6000);

  if (!bit_is_set(PINB,GRENADE)) setgrenade();

  while(!bit_is_set(PINB,PB2)) {};
	delay_ten_us(6000);

  for (i=0;i<255;i++) {
	delay_ten_us(300);
	if (!bit_is_set(PINB,PB2)) {
		setgrenade();
		break;
	}
  }

  GIMSK = _BV(INT0);

  //delay_ten_us(5000);            // Let everything settle for a bit
  
  
  // turn on watchdog timer immediately, this protects against
  // a 'stuck' system by resetting it
  wdt_enable(WDTO_8S); // 1 second long timeout

	  sei();

for (;;) {

	for(loopgrn=0;loopgrn<grenade+1;loopgrn++) {
      j = num_EUcodes;

	  if (grenade) quickflashLEDx(5);

    // for every POWER code in our collection
	    for(i=0 ; i < j; i++) {   

	      //To keep Watchdog from resetting in middle of code.
	      wdt_reset();

		  code_ptr = (PGM_P)pgm_read_word(EUpowerCodes+i);

	      // Read the carrier frequency from the first byte of code structure
	      const uint8_t freq = pgm_read_byte(code_ptr++);
	      // set OCR for Timer1 to output this POWER code's carrier frequency
	      OCR0A = freq; 
      
	      // Get the number of pairs, the second byte from the code struct
	      const uint8_t numpairs = pgm_read_byte(code_ptr++);

	      // Get the number of bits we use to index into the timer table
	      // This is the third byte of the structure
	      const uint8_t bitcompression = pgm_read_byte(code_ptr++);

	      // Get pointer (address in memory) to pulse-times table
	      // The address is 16-bits (2 byte, 1 word)
	      const PGM_P time_ptr = (PGM_P)pgm_read_word(code_ptr);
	      code_ptr+=2;

	      // For EACH pair in this code....
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

	  // Shut down everything and put the CPU to sleep
	  TCCR0A = 0;           // turn off frequency generator (should be off already)
	  //TCCR0B = 0;           // turn off frequency generator (should be off already)
	  PORTB = 0b00000100;	// Pullup

	  wdt_disable();           // turn off the watchdog (since we want to sleep
	  //delay_ten_us(1000);      // wait 10 millisec

	  GIMSK = _BV(INT0);
	  MCUCR = _BV(SM1) |  _BV(SE);    // power down mode,  SE enables Sleep Modes
	  sleep_cpu();                    // put CPU into Power Down Sleep Mode

	  //quickflashLEDx(4);
  	  wdt_enable(WDTO_15MS); // 1 second long timeout
	  for(;;) {} // Watchdog lol
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
    // for 8MHz we want to delay 80 cycles per 10 microseconds
    // this code is tweaked to give about that amount.
    for (timer=0; timer <= DELAY_CNT; timer++) {
      NOP;
      NOP;
    }
    NOP;
    us--;
  }
}

// This function just flashes the visible LED a couple times, used to
// tell the user what region is selected
void quickflashLEDx( uint8_t x ) {
  while(x--) {
	delay_ten_us(15000);     // 150 millisec delay between flahes
  PORTB |= _BV(LED);   // turn on visible LED at PB0 by pulling pin to ground
  delay_ten_us(1000);   // 30 millisec delay
  PORTB &=~ _BV(LED);    // turn off visible LED at PB0 by pulling pin to +3V
  	wdt_reset();
  }
  //wdt_reset();                // kick the dog
}
