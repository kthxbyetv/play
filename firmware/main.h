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

// Pins used for the LEDs and the button
#define IR_LED PB0
#define ACT_LED PB3
#define BUTTON PB2

// Time between codes, in microseconds
#define CODES_DELAY 25000