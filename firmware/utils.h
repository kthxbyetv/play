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

// NOP assembly function
#define NOP __asm__ __volatile__ ("nop")

// Timing value used for the microseconds delay function
#define DELAY_CNT 11

void blinkLED(uint8_t count);
void delay_ten_us(uint16_t us);
void xmitCodeElement(uint16_t on_time, uint16_t off_time, uint8_t is_pwm);