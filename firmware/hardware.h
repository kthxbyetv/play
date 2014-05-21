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

// ACT LED : the LED that blinks when a code is sended
#define LED PB3

// IR LED : the LEDs that sends the IR codes
#define IRLED PB0

// Button : the one that you push to send the codes
#define BUTTON PB2