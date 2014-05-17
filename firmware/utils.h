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

#define NOP __asm__ __volatile__ ("nop")

void delayTenMicroseconds(uint16_t us);
void quickLEDFlash(void);