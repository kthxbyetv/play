// Lets us calculate the size of the NA/EU databases
#define NUM_ELEM(x) (sizeof (x) / sizeof (*(x)));

// Makes the codes more readable. the OCRA is actually
// programmed in terms of 'periods' not 'freqs' - that
// is, the inverse!
#define freq_to_timerval(x) ((F_CPU / x - 1)/ 2)

#define PULSE_CODE 0

// The structure of compressed code entries
struct IrCode {
  uint8_t timer_val;
  uint8_t numpairs;
  uint8_t bitcompression;
  uint16_t const *times;
  uint8_t codes[];
};

void xmitCodeElement(uint16_t ontime, uint16_t offtime, uint8_t PWM_code );
void tvbgone_sleep( void );
void delay_ten_us(uint16_t us);
