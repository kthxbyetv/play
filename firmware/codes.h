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

#define NUM_ELEM(x) (sizeof (x) / sizeof (*(x)))
#define freq_to_timerval(x) ((F_CPU / x - 1)/ 2)

struct IrCode {
  uint8_t timer_val;
  uint8_t numpairs;
  uint8_t bitcompression;
  uint16_t const *times;
  uint8_t codes[];
};