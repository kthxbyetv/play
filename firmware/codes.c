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

#include <avr/pgmspace.h>
#include "codes.h"

const uint16_t code_HitachiVPTimes[] PROGMEM = {
	900, 460,
	63, 173,
	63, 63,
	63, 0
};

const struct IrCode code_HitachiVPCode PROGMEM = {
	freq_to_timerval(38000),
	34,
	2,
	code_HitachiVPTimes,
	{
		0x15, 0xAA, 0x59, 0xA9, 0x95, 0x9A, 0xAA, 0x65, 0x70
	}
};


const uint16_t code_TNT1Times[] PROGMEM = {
	896, 448,
	56, 56,
	56, 168,
	56, 0
};

const struct IrCode code_TNT1Code PROGMEM = {
	freq_to_timerval(38000),
	34,
	2,
	code_TNT1Times,
	{
		0x15, 0x55, 0xAA, 0xAA, 0x69, 0x55, 0x56, 0xAA, 0xB0
	}
};

const uint16_t code_CAE33Times[] PROGMEM = {
	860, 406,
	66, 145,
	66, 40,
	66, 2100
};
const struct IrCode code_CAE33Code PROGMEM = {
	freq_to_timerval(38000),
	35,		// # of pairs
	2,		// # of bits per index
	code_CAE33Times,
	{
		0x5A,
		0x99,
		0x56,
		0x6A,
		0xD6,
		0xA6,
		0x55,
		0x9A,
		0xB0
	}
};

const uint16_t code_SX263UTimes[] PROGMEM = {
	839, 425,
	49, 161,
	49, 57,
	49, 2260
};
const struct IrCode code_SX263UCode PROGMEM = {
	freq_to_timerval(38000),
	52,		// # of pairs
	2,		// # of bits per index
	code_SX263UTimes,
	{
		0x16, 0x96, 0x6A, 0xA9, 0xB5, 0xA5, 0x9A, 0xAA, 0x6D, 0x69, 0x66, 0xAA, 0x9B
	}
};

const uint16_t code_V718UTimes[] PROGMEM = {
	840, 422,
	51, 160,
	51, 54,
	51, 1940
};
const struct IrCode code_V718UCode PROGMEM = {
	freq_to_timerval(38000),
	52,		// # of pairs
	2,		// # of bits per index
	code_V718UTimes,
	{
		0x16, 0x99, 0x5A, 0x59, 0xB5, 0xA6, 0x56, 0x96, 0x6D, 0x69, 0x95, 0xA5, 0x9B
	}
};

const uint16_t code_S33Times[] PROGMEM = {
	246, 55,
	124, 56,
	64, 56
};
const struct IrCode code_S33Code PROGMEM = {
	freq_to_timerval(38400),
	13,		// # of pairs
	2,		// # of bits per index
	code_S33Times,
	{
		0x19, 0x9A, 0xAA, 0x10
		// 0001 1001 1001 1010 1010 1010 01
	}
};

const uint16_t code_EUR7623X70Times[] PROGMEM = {
	357, 166,
	54, 121,
	54, 37,
	54, 7440
};
const struct IrCode code_EUR7623X70Code PROGMEM = {
	freq_to_timerval(38400),
	255,		// 296 # of pairs
	2,		// # of bits per index
	code_EUR7623X70Times,
	{
		0x26, 0xaa, 0xaa, 0xa6, 0xaa, 0xa6, 0x69, 0x5a, 0x99, 0x56, 0x9a, 0xaa, 0x79,
		0xaa, 0xaa, 0xa9, 0xaa, 0xa9, 0x9a, 0x56, 0xa6, 0x55, 0xa6, 0xaa, 0x9e, 0x6a,
		0xaa, 0xaa, 0x6a, 0xaa, 0x66, 0x95, 0xa9, 0x95, 0x69, 0xaa, 0xa7
		// 00 100110101010101010101010100110101010101010011001101001010110101001100101010110100110101010101001111001101010101010101010101001101010101010100110011010010101101010011001010101101001101010101010011110011010101010101010101010011010101010101001100110100101011010100110010101011010011010101010100111
	}
};

const struct IrCode code_EUR7914Z20Code PROGMEM = {
	freq_to_timerval(38400),
	52,		// # of pairs
	2,		// # of bits per index
	code_EUR7623X70Times,
	{
		0x19, 0x56, 0x99, 0x95, 0x76, 0x55, 0xa6, 0x65, 0x5d, 0x95, 0x69, 0x99, 0x57
		// 00011001010101101001100110010101011101100101010110100110011001010101110110010101011010011001100101010111
	}
};

const struct IrCode code_N2QAYB000239Code PROGMEM = {
	freq_to_timerval(38400),
	255,		// 296 # of pairs
	2,		// # of bits per index
	code_EUR7623X70Times,
	{
		0x26, 0xaa, 0xaa, 0xa6, 0xaa, 0xaa, 0x6a, 0xaa, 0x99, 0x56, 0x99, 0x56, 0x79,
		0xaa, 0xaa, 0xa9, 0xaa, 0xaa, 0x9a, 0xaa, 0xa6, 0x55, 0xa6, 0x55, 0x9e, 0x6a,
		0xaa, 0xaa, 0x6a, 0xaa, 0xa6, 0xaa, 0xa9, 0x95, 0x69, 0x95, 0x67
		// 00100110101010101010101010100110101010101010101001101010101010101001100101010110100110010101011001111001101010101010101010101001101010101010101010011010101010101010011001010101101001100101010110011110011010101010101010101010011010101010101010100110101010101010100110010101011010011001010101100111
	}
};

const uint16_t code_RC8861Times[] PROGMEM = {
	237, 62,
	118, 61,
	59, 61,
	59, 4480
};
const struct IrCode code_RC8861Code PROGMEM = {
	freq_to_timerval(38400),
	34,		// # of pairs
	2,		// # of bits per index
	code_RC8861Times,
	{
		0x19, 0x9a, 0x6b, 0x66, 0x69, 0xad, 0x99, 0xa6, 0x0b
		// 00011001100110100110101101100110011010011010110110011001101001101011
	}
};

const uint16_t code_RD427ETimes[] PROGMEM = {
	908, 442,
	64, 160,
	64, 47,
	900, 225
};
const struct IrCode code_RD427ECode PROGMEM = {
	freq_to_timerval(38400),
	35,		// # of pairs
	2,		// # of bits per index
	code_RD427ETimes,
	{
		0x2a, 0x5a, 0x9a, 0x65, 0x69, 0x9a, 0x96, 0x65, 0x1f
		// 0010101001011010100110100110010101101001100110101001011001100101011111
	}
};

const uint16_t code_na000Times[] PROGMEM = {
	60, 60,
	60, 2700,
	120, 60,
	240, 60
};
const struct IrCode code_na000Code PROGMEM = {
	freq_to_timerval(38400),
	26,		// # of pairs
	2,		// # of bits per index
	code_na000Times,
	{
		0xE2, 0x20, 0x80, 0x78, 0x88, 0x20, 0x10
	}
};

const uint16_t code_na001Times[] PROGMEM = {
	50, 100,
	50, 200,
	50, 800,
	400, 400
};
const struct IrCode code_na001Code PROGMEM = {
	freq_to_timerval(57143),
	52,		// # of pairs
	2,		// # of bits per index
	code_na001Times,
	{
		0xD5, 0x41, 0x11, 0x00, 0x14, 0x44, 0x6D, 0x54, 0x11, 0x10, 0x01, 0x44, 0x45
	}
};
const uint16_t code_na002Times[] PROGMEM = {
	42, 46,
	42, 133,
	42, 7519,
	347, 176,
	347, 177
};
const struct IrCode code_na002Code PROGMEM = {
	freq_to_timerval(37037),
	100,		// # of pairs
	3,		// # of bits per index
	code_na002Times,
	{
		0x60, 0x80, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x04,
		0x12, 0x48, 0x04, 0x12, 0x48, 0x2A, 0x02, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00,
		0x00, 0x00, 0x80, 0x00, 0x00, 0x10, 0x49, 0x20, 0x10, 0x49, 0x20, 0x80
	}
};
const uint16_t code_na003Times[] PROGMEM = {
	26, 185,
	27, 80,
	27, 185,
	27, 4549
};
const struct IrCode code_na003Code PROGMEM = {
	freq_to_timerval(38610),
	64,		// # of pairs
	2,		// # of bits per index
	code_na003Times,
	{
		0x15, 0x5A, 0x65, 0x67, 0x95, 0x65, 0x9A, 0x9B, 0x95, 0x5A, 0x65, 0x67, 0x95,
		0x65, 0x9A, 0x99
	}
};
const uint16_t code_na004Times[] PROGMEM = {
	55, 57,
	55, 170,
	55, 3949,
	55, 9623,
	56, 0,
	898, 453,
	900, 226
};

const struct IrCode code_na004Code PROGMEM = {
	freq_to_timerval(38610),
	38,		// # of pairs
	3,		// # of bits per index
	code_na004Times,
	{
		0xA0, 0x00, 0x01, 0x04, 0x92, 0x48, 0x20, 0x80, 0x40, 0x04, 0x12, 0x09, 0x2B,
		0x3D, 0x00
	}
};
const uint16_t code_na005Times[] PROGMEM = {
	88, 90,
	88, 91,
	88, 181,
	88, 8976,
	177, 91
};
const struct IrCode code_na005Code PROGMEM = {
	freq_to_timerval(35714),
	24,		// # of pairs
	3,		// # of bits per index
	code_na005Times,
	{
		0x10, 0x92, 0x49, 0x46, 0x33, 0x09, 0x24, 0x94, 0x60
	}
};
const uint16_t code_na006Times[] PROGMEM = {
	50, 62,
	50, 172,
	50, 4541,
	448, 466,
	450, 465
};
const struct IrCode code_na006Code PROGMEM = {
	freq_to_timerval(38462),
	68,		// # of pairs
	3,		// # of bits per index
	code_na006Times,
	{
		0x64, 0x90, 0x00, 0x04, 0x90, 0x00, 0x00, 0x80, 0x00, 0x04, 0x12, 0x49, 0x2A,
		0x12, 0x40, 0x00, 0x12, 0x40, 0x00, 0x02, 0x00, 0x00, 0x10, 0x49, 0x24, 0x90
	}
};
const uint16_t code_na007Times[] PROGMEM = {
	49, 49,
	49, 50,
	49, 410,
	49, 510,
	49, 12107
};
const struct IrCode code_na007Code PROGMEM = {
	freq_to_timerval(39216),
	34,		// # of pairs
	3,		// # of bits per index
	code_na007Times,
	{
		0x09, 0x94, 0x53, 0x29, 0x94, 0xD9, 0x85, 0x32, 0x8A, 0x65, 0x32, 0x9B, 0x20
	}
};
const uint16_t code_na008Times[] PROGMEM = {
	56, 58,
	56, 170,
	56, 4011,
	898, 450,
	900, 449
};
const struct IrCode code_na008Code PROGMEM = {
	freq_to_timerval(38462),
	68,		// # of pairs
	3,		// # of bits per index
	code_na008Times,
	{
		0x64, 0x00, 0x49, 0x00, 0x92, 0x00, 0x20, 0x82, 0x01, 0x04, 0x10, 0x48, 0x2A,
		0x10, 0x01, 0x24, 0x02, 0x48, 0x00, 0x82, 0x08, 0x04, 0x10, 0x41, 0x20, 0x90
	}
};
const uint16_t code_na009Times[] PROGMEM = {
	53, 56,
	53, 171,
	53, 3950,
	53, 9599,
	898, 451,
	900, 226
};
const struct IrCode code_na009Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na009Times,
	{
		0x84, 0x90, 0x00, 0x20, 0x80, 0x08, 0x00, 0x00, 0x09, 0x24, 0x92, 0x40, 0x0A,
		0xBA, 0x40
	}
};
const uint16_t code_na010Times[] PROGMEM = {
	51, 55,
	51, 158,
	51, 2286,
	841, 419
};
const struct IrCode code_na010Code PROGMEM = {
	freq_to_timerval(38462),
	52,		// # of pairs
	2,		// # of bits per index
	code_na010Times,
	{
		0xD4, 0x00, 0x15, 0x10, 0x25, 0x00, 0x05, 0x44, 0x09, 0x40, 0x01, 0x51, 0x01
	}
};

const uint16_t code_eu004Times[] PROGMEM = {
	44, 45,
	44, 131,
	44, 7462,
	346, 176,
	346, 178
};
const struct IrCode code_eu004Code PROGMEM = {
	freq_to_timerval(37037),
	100,		// # of pairs
	3,		// # of bits per index
	code_eu004Times,
	{
		0x60, 0x80, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x04,
		0x12, 0x48, 0x04, 0x12, 0x48, 0x2A, 0x02, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00,
		0x00, 0x00, 0x80, 0x00, 0x00, 0x10, 0x49, 0x20, 0x10, 0x49, 0x20, 0x80
	}
};// Duplicate IR Code? Similar to NA002

const uint16_t code_eu007Times[] PROGMEM = {
	50, 54,
	50, 159,
	50, 2307,
	838, 422
};
const struct IrCode code_eu007Code PROGMEM = {
	freq_to_timerval(38462),
	52,		// # of pairs
	2,		// # of bits per index
	code_eu007Times,
	{
		0xD4, 0x00, 0x15, 0x10, 0x25, 0x00, 0x05, 0x44, 0x09, 0x40, 0x01, 0x51, 0x01
	}
};// Duplicate IR Code? - Similar to NA010

const uint16_t code_eu015Times[] PROGMEM = {
	53, 54,
	53, 156,
	53, 2542,
	851, 425,
	853, 424
};

const struct IrCode code_eu015Code PROGMEM = {
	freq_to_timerval(38462),
	136,		// # of pairs
	3,		// # of bits per index
	code_eu015Times,
	{
		0x60, 0x82, 0x08, 0x24, 0x10, 0x41, 0x00, 0x12, 0x40, 0x04, 0x80, 0x09, 0x2A,
		0x02, 0x08, 0x20, 0x90, 0x41, 0x04, 0x00, 0x49, 0x00, 0x12, 0x00, 0x24, 0xA8,
		0x08, 0x20, 0x82, 0x41, 0x04, 0x10, 0x01, 0x24, 0x00, 0x48, 0x00, 0x92, 0xA0,
		0x20, 0x82, 0x09, 0x04, 0x10, 0x40, 0x04, 0x90, 0x01, 0x20, 0x02, 0x48
	}
};// Duplicate IR Code? - Similar to NA018

const uint16_t code_na011Times[] PROGMEM = {
	55, 55,
	55, 172,
	55, 4039,
	55, 9348,
	56, 0,
	884, 442,
	885, 225
};
const struct IrCode code_na011Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na011Times,
	{
		0xA0, 0x00, 0x41, 0x04, 0x92, 0x08, 0x24, 0x90, 0x40, 0x00, 0x02, 0x09, 0x2B,
		0x3D, 0x00
	}
};
const uint16_t code_na012Times[] PROGMEM = {
	81, 87,
	81, 254,
	81, 3280,
	331, 336,
	331, 337
};
const struct IrCode code_na012Code PROGMEM = {
	freq_to_timerval(38462),
	52,		// # of pairs
	3,		// # of bits per index
	code_na012Times,
	{
		0x64, 0x12, 0x08, 0x24, 0x00, 0x08, 0x20, 0x10, 0x09, 0x2A, 0x10, 0x48, 0x20,
		0x90, 0x00, 0x20, 0x80, 0x40, 0x24, 0x90
	}
};
const uint16_t code_na013Times[] PROGMEM = {
	53, 55,
	53, 167,
	53, 2304,
	53, 9369,
	893, 448,
	895, 447
};
const struct IrCode code_na013Code PROGMEM = {
	freq_to_timerval(38462),
	48,		// # of pairs
	3,		// # of bits per index
	code_na013Times,
	{
		0x80, 0x12, 0x40, 0x04, 0x00, 0x09, 0x00, 0x12, 0x41, 0x24, 0x82, 0x01, 0x00,
		0x10, 0x48, 0x24, 0xAA, 0xE8
	}
};

const struct IrCode code_na014Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na004Times,
	{
		0xA0, 0x00, 0x09, 0x04, 0x92, 0x40, 0x24, 0x80, 0x00, 0x00, 0x12, 0x49, 0x2B,
		0x3D, 0x00
	}
};

const struct IrCode code_na015Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na004Times,
	{
		0xA0, 0x80, 0x01, 0x04, 0x12, 0x48, 0x24, 0x00, 0x00, 0x00, 0x92, 0x49, 0x2B,
		0x3D, 0x00
	}
};
const uint16_t code_na016Times[] PROGMEM = {
	28, 90,
	28, 211,
	28, 2507
};
const struct IrCode code_na016Code PROGMEM = {
	freq_to_timerval(34483),
	34,		// # of pairs
	2,		// # of bits per index
	code_na016Times,
	{
		0x54, 0x04, 0x10, 0x00, 0x95, 0x01, 0x04, 0x00, 0x10
	}
};
const uint16_t code_na017Times[] PROGMEM = {
	56, 57,
	56, 175,
	56, 4150,
	56, 9499,
	898, 227,
	898, 449
};
const struct IrCode code_na017Code PROGMEM = {
	freq_to_timerval(40000),
	38,		// # of pairs
	3,		// # of bits per index
	code_na017Times,
	{
		0xA0, 0x02, 0x48, 0x04, 0x90, 0x01, 0x20, 0x80, 0x40, 0x04, 0x12, 0x09, 0x2A,
		0x38, 0x00
	}
};
const uint16_t code_na018Times[] PROGMEM = {
	51, 55,
	51, 161,
	51, 2566,
	849, 429,
	849, 430
};
const struct IrCode code_na018Code PROGMEM = {
	freq_to_timerval(38462),
	136,		// # of pairs
	3,		// # of bits per index
	code_na018Times,
	{
		0x60, 0x82, 0x08, 0x24, 0x10, 0x41, 0x00, 0x12, 0x40, 0x04, 0x80, 0x09, 0x2A,
		0x02, 0x08, 0x20, 0x90, 0x41, 0x04, 0x00, 0x49, 0x00, 0x12, 0x00, 0x24, 0xA8,
		0x08, 0x20, 0x82, 0x41, 0x04, 0x10, 0x01, 0x24, 0x00, 0x48, 0x00, 0x92, 0xA0,
		0x20, 0x82, 0x09, 0x04, 0x10, 0x40, 0x04, 0x90, 0x01, 0x20, 0x02, 0x48
	}
};
const uint16_t code_na019Times[] PROGMEM = {
	40, 42,
	40, 124,
	40, 4601,
	325, 163,
	326, 163
};
const struct IrCode code_na019Code PROGMEM = {
	freq_to_timerval(38462),
	100,		// # of pairs
	3,		// # of bits per index
	code_na019Times,
	{
		0x60, 0x10, 0x40, 0x04, 0x80, 0x09, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x20,
		0x10, 0x00, 0x20, 0x80, 0x00, 0x0A, 0x00, 0x41, 0x00, 0x12, 0x00, 0x24, 0x00,
		0x00, 0x00, 0x00, 0x40, 0x00, 0x80, 0x40, 0x00, 0x82, 0x00, 0x00, 0x00
	}
};
const uint16_t code_na020Times[] PROGMEM = {
	60, 55,
	60, 163,
	60, 4099,
	60, 9698,
	61, 0,
	898, 461,
	900, 230
};
const struct IrCode code_na020Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na020Times,
	{
		0xA0, 0x10, 0x00, 0x04, 0x82, 0x49, 0x20, 0x02, 0x00, 0x04, 0x90, 0x49, 0x2B,
		0x3D, 0x00
	}
};
const uint16_t code_na021Times[] PROGMEM = {
	48, 52,
	48, 160,
	48, 400,
	48, 2335,
	799, 400
};
const struct IrCode code_na021Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na021Times,
	{
		0x80, 0x10, 0x40, 0x08, 0x82, 0x08, 0x01, 0xC0, 0x08, 0x20, 0x04, 0x41, 0x04,
		0x00, 0x00
	}
};
const uint16_t code_na022Times[] PROGMEM = {
	53, 60,
	53, 175,
	53, 4463,
	53, 9453,
	892, 450,
	895, 225
};
const struct IrCode code_na022Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na022Times,
	{
		0x80, 0x02, 0x40, 0x00, 0x02, 0x40, 0x00, 0x00, 0x01, 0x24, 0x92, 0x48, 0x0A,
		0xBA, 0x00
	}
};

const uint16_t code_epsonTimes[] PROGMEM = {
	902, 445,
	56, 168,
	56, 52,
	56, 2000
};
const struct IrCode code_epsonCode PROGMEM = {
	freq_to_timerval(38000),
	34,		// # of pairs
	2,		// # of bits per index
	code_epsonTimes,
	{
		0x16, 0xAA, 0x59, 0x99, 0xAA, 0x9A, 0x55, 0x65, 0xB0
	}
};

const uint16_t code_eu000Times[] PROGMEM = {
	43, 47,
	43, 91,
	43, 8324,
	88, 47,
	133, 133,
	264, 90,
	264, 91
};
const struct IrCode code_eu000Code PROGMEM = {
	freq_to_timerval(35714),
	40,		// # of pairs
	3,		// # of bits per index
	code_eu000Times,
	{
		0xA4, 0x08, 0x00, 0x00, 0x00, 0x00, 0x64, 0x2C, 0x40, 0x80, 0x00, 0x00, 0x00,
		0x06, 0x41
	}
};
const uint16_t code_eu001Times[] PROGMEM = {
	47, 265,
	51, 54,
	51, 108,
	51, 263,
	51, 2053,
	51, 11647,
	100, 109
};
const struct IrCode code_eu001Code PROGMEM = {
	freq_to_timerval(30303),
	31,		// # of pairs
	3,		// # of bits per index
	code_eu001Times,
	{
		0x04, 0x92, 0x49, 0x26, 0x35, 0x89, 0x24, 0x9A, 0xD6, 0x24, 0x92, 0x48
	}
};
const uint16_t code_eu002Times[] PROGMEM = {
	43, 206,
	46, 204,
	46, 456,
	46, 3488
};
const struct IrCode code_eu002Code PROGMEM = {
	freq_to_timerval(33333),
	26,		// # of pairs
	2,		// # of bits per index
	code_eu002Times,
	{
		0x1A, 0x56, 0xA6, 0xD6, 0x95, 0xA9, 0x90
	}
};

const uint16_t code_eu005Times[] PROGMEM = {
	24, 190,
	25, 80,
	25, 190,
	25, 4199,
	25, 4799
};
const struct IrCode code_eu005Code PROGMEM = {
	freq_to_timerval(38610),
	64,		// # of pairs
	3,		// # of bits per index
	code_eu005Times,
	{
		0x04, 0x92, 0x52, 0x28, 0x92, 0x8C, 0x44, 0x92, 0x89, 0x45, 0x24, 0x53, 0x44,
		0x92, 0x52, 0x28, 0x92, 0x8C, 0x44, 0x92, 0x89, 0x45, 0x24, 0x51
	}
};
const uint16_t code_eu006Times[] PROGMEM = {
	53, 63,
	53, 172,
	53, 4472,
	54, 0,
	455, 468
};
const struct IrCode code_eu006Code PROGMEM = {
	freq_to_timerval(38462),
	68,		// # of pairs
	3,		// # of bits per index
	code_eu006Times,
	{
		0x84, 0x90, 0x00, 0x04, 0x90, 0x00, 0x00, 0x80, 0x00, 0x04, 0x12, 0x49, 0x2A,
		0x12, 0x40, 0x00, 0x12, 0x40, 0x00, 0x02, 0x00, 0x00, 0x10, 0x49, 0x24, 0xB0
	}
};

const struct IrCode code_eu008Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na004Times,
	{
		0xA0, 0x00, 0x41, 0x04, 0x92, 0x08, 0x24, 0x90, 0x40, 0x00, 0x02, 0x09, 0x2B,
		0x3D, 0x00
	}
};

const struct IrCode code_eu011Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na009Times,
	{
		0x84, 0x00, 0x48, 0x04, 0x02, 0x01, 0x04, 0x80, 0x09, 0x00, 0x12, 0x40, 0x2A,
		0xBA, 0x40
	}
};
const uint16_t code_eu012Times[] PROGMEM = {
	46, 206,
	46, 459,
	46, 3447
};
const struct IrCode code_eu012Code PROGMEM = {
	freq_to_timerval(33445),
	26,		// # of pairs
	2,		// # of bits per index
	code_eu012Times,
	{
		0x05, 0x01, 0x51, 0x81, 0x40, 0x54, 0x40
	}
};
const uint16_t code_eu013Times[] PROGMEM = {
	53, 59,
	53, 171,
	53, 2302,
	895, 449
};
const struct IrCode code_eu013Code PROGMEM = {
	freq_to_timerval(38462),
	88,		// # of pairs
	2,		// # of bits per index
	code_eu013Times,
	{
		0xD4, 0x55, 0x00, 0x00, 0x40, 0x15, 0x54, 0x00, 0x01, 0x55, 0x56, 0xD4, 0x55,
		0x00, 0x00, 0x40, 0x15, 0x54, 0x00, 0x01, 0x55, 0x55
	}
};

const uint16_t code_eu016Times[] PROGMEM = {
	28, 92,
	28, 213,
	28, 214,
	28, 2771
};
const struct IrCode code_eu016Code PROGMEM = {
	freq_to_timerval(33333),
	34,		// # of pairs
	2,		// # of bits per index
	code_eu016Times,
	{
		0x68, 0x08, 0x20, 0x00, 0xEA, 0x02, 0x08, 0x00, 0x10
	}
};
const uint16_t code_eu017Times[] PROGMEM = {
	15, 844,
	16, 557,
	16, 844,
	16, 5224
};
const struct IrCode code_eu017Code PROGMEM = {
	freq_to_timerval(33333),
	24,		// # of pairs
	2,		// # of bits per index
	code_eu017Times,
	{
		0x1A, 0x9A, 0x9B, 0x9A, 0x9A, 0x99
	}
};

const struct IrCode code_eu018Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na004Times,
	{
		0xA0, 0x02, 0x48, 0x04, 0x90, 0x01, 0x20, 0x12, 0x40, 0x04, 0x80, 0x09, 0x2B,
		0x3D, 0x00
	}
};
const uint16_t code_eu019Times[] PROGMEM = {
	50, 54,
	50, 158,
	50, 418,
	50, 2443,
	843, 418
};
const struct IrCode code_eu019Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_eu019Times,
	{
		0x80, 0x80, 0x00, 0x08, 0x12, 0x40, 0x01, 0xC0, 0x40, 0x00, 0x04, 0x09, 0x20,
		0x00, 0x00
	}
};
const uint16_t code_eu020Times[] PROGMEM = {
	48, 301,
	48, 651,
	48, 1001,
	48, 3001
};
const struct IrCode code_eu020Code PROGMEM = {
	freq_to_timerval(35714),
	34,		// # of pairs
	2,		// # of bits per index
	code_eu020Times,
	{
		0x22, 0x20, 0x00, 0x01, 0xC8, 0x88, 0x00, 0x00, 0x40
	}
};

const struct IrCode code_eu021Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na009Times,
	{
		0x84, 0x80, 0x00, 0x20, 0x82, 0x49, 0x00, 0x02, 0x00, 0x04, 0x90, 0x49, 0x2A,
		0xBA, 0x40
	}
};

const struct IrCode code_eu022Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na004Times,
	{
		0xA4, 0x80, 0x41, 0x00, 0x12, 0x08, 0x24, 0x90, 0x40, 0x00, 0x02, 0x09, 0x2B,
		0x3D, 0x00
	}
};

const struct IrCode code_eu024Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na004Times,
	{
		0xA0, 0x02, 0x48, 0x04, 0x90, 0x01, 0x20, 0x00, 0x40, 0x04, 0x92, 0x09, 0x2B,
		0x3D, 0x00
	}
};
const uint16_t code_eu025Times[] PROGMEM = {
	49, 52,
	49, 102,
	49, 250,
	49, 252,
	49, 2377,
	49, 12009,
	100, 52,
	100, 102
};
const struct IrCode code_eu025Code PROGMEM = {
	freq_to_timerval(31250),
	21,		// # of pairs
	3,		// # of bits per index
	code_eu025Times,
	{
		0x47, 0x00, 0x23, 0x3C, 0x01, 0x59, 0xE0, 0x04
	}
};
const uint16_t code_eu026Times[] PROGMEM = {
	14, 491,
	14, 743,
	14, 4926
};
const struct IrCode code_eu026Code PROGMEM = {
	freq_to_timerval(38462),
	24,		// # of pairs
	2,		// # of bits per index
	code_eu026Times,
	{
		0x55, 0x40, 0x42, 0x55, 0x40, 0x41
	}
};

const struct IrCode code_eu027Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na004Times,
	{
		0xA0, 0x82, 0x08, 0x24, 0x10, 0x41, 0x04, 0x10, 0x01, 0x20, 0x82, 0x48, 0x0B,
		0x3D, 0x00
	}
};
const uint16_t code_eu028Times[] PROGMEM = {
	47, 267,
	50, 55,
	50, 110,
	50, 265,
	50, 2055,
	50, 12117,
	100, 57
};
const struct IrCode code_eu028Code PROGMEM = {
	freq_to_timerval(30303),
	31,		// # of pairs
	3,		// # of bits per index
	code_eu028Times,
	{
		0x04, 0x92, 0x49, 0x26, 0x34, 0x72, 0x24, 0x9A, 0xD1, 0xC8, 0x92, 0x48
	}
};
const uint16_t code_eu029Times[] PROGMEM = {
	50, 50,
	50, 99,
	50, 251,
	50, 252,
	50, 1445,
	50, 11014,
	102, 49,
	102, 98
};
const struct IrCode code_eu029Code PROGMEM = {
	freq_to_timerval(34483),
	46,		// # of pairs
	3,		// # of bits per index
	code_eu029Times,
	{
		0x47, 0x00, 0x00, 0x00, 0x00, 0x04, 0x64, 0x62, 0x00, 0xE0, 0x00, 0x2B, 0x23,
		0x10, 0x07, 0x00, 0x00, 0x80
	}
};

const struct IrCode code_eu030Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na004Times,
	{
		0xA0, 0x10, 0x00, 0x04, 0x82, 0x49, 0x20, 0x02, 0x00, 0x04, 0x90, 0x49, 0x2B,
		0x3D, 0x00
	}
};// Duplicate IR Code? - Smilar to NA020

const uint16_t code_eu031Times[] PROGMEM = {
	53, 53,
	53, 160,
	53, 1697,
	838, 422
};
const struct IrCode code_eu031Code PROGMEM = {
	freq_to_timerval(38462),
	52,		// # of pairs
	2,		// # of bits per index
	code_eu031Times,
	{
		0xD5, 0x50, 0x15, 0x11, 0x65, 0x54, 0x05, 0x44, 0x59, 0x55, 0x01, 0x51, 0x15
	}
};
const uint16_t code_eu032Times[] PROGMEM = {
	49, 205,
	49, 206,
	49, 456,
	49, 3690
};
const struct IrCode code_eu032Code PROGMEM = {
	freq_to_timerval(33333),
	26,		// # of pairs
	2,		// # of bits per index
	code_eu032Times,
	{
		0x1A, 0x56, 0xA5, 0xD6, 0x95, 0xA9, 0x40
	}
};
const uint16_t code_eu033Times[] PROGMEM = {
	48, 150,
	50, 149,
	50, 347,
	50, 2936
};
const struct IrCode code_eu033Code PROGMEM = {
	freq_to_timerval(38462),
	14,		// # of pairs
	2,		// # of bits per index
	code_eu033Times,
	{
		0x2A, 0x5D, 0xA9, 0x60
	}
};

const struct IrCode code_eu034Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na004Times,
	{
		0xA0, 0x02, 0x40, 0x04, 0x90, 0x09, 0x20, 0x02, 0x00, 0x04, 0x90, 0x49, 0x2B,
		0x3D, 0x00
	}
};

const struct IrCode code_eu036Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na004Times,
	{
		0xA4, 0x00, 0x49, 0x00, 0x92, 0x00, 0x20, 0x02, 0x00, 0x04, 0x90, 0x49, 0x2B,
		0x3D, 0x00
	}
};
const uint16_t code_eu037Times[] PROGMEM = {
	14, 491,
	14, 743,
	14, 5178
};
const struct IrCode code_eu037Code PROGMEM = {
	freq_to_timerval(38462),
	24,		// # of pairs
	2,		// # of bits per index
	code_eu037Times,
	{
		0x45, 0x50, 0x02, 0x45, 0x50, 0x01
	}
};
const uint16_t code_eu038Times[] PROGMEM = {
	3, 1002,
	3, 1495,
	3, 3059
};
const struct IrCode code_eu038Code PROGMEM = {
	0,		// Non-pulsed code
	11,		// # of pairs
	2,		// # of bits per index
	code_eu038Times,
	{
		0x05,	// 0000 0101 0,0,1,1,1,2,0,0,1,1,1,0
		0x60,	// 0110 0000
		0x54	// 0101 0100
	}
};
const uint16_t code_eu039Times[] PROGMEM = {
	13, 445,
	13, 674,
	13, 675,
	13, 4583
};
const struct IrCode code_eu039Code PROGMEM = {
	freq_to_timerval(40161),
	24,		// # of pairs
	2,		// # of bits per index
	code_eu039Times,
	{
		0x6A, 0x82, 0x83, 0xAA, 0x82, 0x81
	}
};
const uint16_t code_eu040Times[] PROGMEM = {
	85, 89,
	85, 264,
	85, 3402,
	347, 350,
	348, 350
};
const struct IrCode code_eu040Code PROGMEM = {
	freq_to_timerval(35714),
	52,		// # of pairs
	3,		// # of bits per index
	code_eu040Times,
	{
		0x60, 0x90, 0x40, 0x20, 0x80, 0x40, 0x20, 0x90, 0x41, 0x2A, 0x02, 0x41, 0x00,
		0x82, 0x01, 0x00, 0x82, 0x41, 0x04, 0x80
	}
};
const uint16_t code_eu041Times[] PROGMEM = {
	46, 300,
	49, 298,
	49, 648,
	49, 997,
	49, 3056
};
const struct IrCode code_eu041Code PROGMEM = {
	freq_to_timerval(33333),
	28,		// # of pairs
	3,		// # of bits per index
	code_eu041Times,
	{
		0x0C, 0xB2, 0xCA, 0x49, 0x13, 0x0B, 0x2C, 0xB2, 0x92, 0x44, 0xB0
	}
};

const struct IrCode code_eu042Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na009Times,
	{
		0x80, 0x00, 0x00, 0x24, 0x92, 0x09, 0x00, 0x82, 0x00, 0x04, 0x10, 0x49, 0x2A,
		0xBA, 0x00
	}
};
const uint16_t code_eu043Times[] PROGMEM = {
	1037, 4216,
	1040, 0
};
const struct IrCode code_eu043Code PROGMEM = {
	freq_to_timerval(41667),
	2,		// # of pairs
	2,		// # of bits per index
	code_eu043Times,
	{
		0x10
	}
};

const struct IrCode code_eu044Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na004Times,
	{
		0xA0, 0x02, 0x01, 0x04, 0x90, 0x48, 0x20, 0x00, 0x00, 0x04, 0x92, 0x49, 0x2B,
		0x3D, 0x00
	}
};
const uint16_t code_eu045Times[] PROGMEM = {
	152, 471,
	154, 156,
	154, 469,
	154, 2947
};
const struct IrCode code_eu045Code PROGMEM = {
	freq_to_timerval(41667),
	10,		// # of pairs
	2,		// # of bits per index
	code_eu045Times,
	{
		0x16, 0xE5, 0x90
	}
};
const uint16_t code_eu046Times[] PROGMEM = {
	15, 493,
	16, 493,
	16, 698,
	16, 1414
};
const struct IrCode code_eu046Code PROGMEM = {
	freq_to_timerval(34602),
	16,		// # of pairs
	2,		// # of bits per index
	code_eu046Times,
	{
		0x16, 0xAB, 0x56, 0xA9
	}
};
const uint16_t code_eu047Times[] PROGMEM = {
	3, 496,
	3, 745,
	3, 1488
};
const struct IrCode code_eu047Code PROGMEM = {
	0,		// Non-pulsed code
	17,		// # of pairs
	2,		// # of bits per index
	code_eu047Times,
	{
		0x41,	//0100 0001 100102
		0x24,	//0010 0100
		0x12,	//0001 0010
		0x41,	//0100 0001
		0x00	//0000 0000
	}
};

const struct IrCode code_eu048Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na009Times,
	{
		0x80, 0x00, 0x00, 0x24, 0x82, 0x49, 0x04, 0x80, 0x40, 0x00, 0x12, 0x09, 0x2A,
		0xBA, 0x00
	}
};
const uint16_t code_eu049Times[] PROGMEM = {
	55, 55,
	55, 167,
	55, 4577,
	55, 9506,
	448, 445,
	450, 444
};
const struct IrCode code_eu049Code PROGMEM = {
	freq_to_timerval(38462),
	40,		// # of pairs
	3,		// # of bits per index
	code_eu049Times,
	{
		0x80, 0x92, 0x00, 0x00, 0x92, 0x00, 0x00, 0x10, 0x40, 0x04, 0x82, 0x09, 0x2A,
		0x97, 0x48
	}
};
const uint16_t code_eu050Times[] PROGMEM = {
	91, 88,
	91, 267,
	91, 3621,
	361, 358,
	361, 359
};
const struct IrCode code_eu050Code PROGMEM = {
	freq_to_timerval(33333),
	48,		// # of pairs
	3,		// # of bits per index
	code_eu050Times,
	{
		0x60, 0x00, 0x00, 0x00, 0x12, 0x49, 0x24, 0x92, 0x42, 0x80, 0x00, 0x00, 0x00,
		0x12, 0x49, 0x24, 0x92, 0x40
	}
};
const uint16_t code_eu051Times[] PROGMEM = {
	84, 88,
	84, 261,
	84, 3360,
	347, 347,
	347, 348
};
const struct IrCode code_eu051Code PROGMEM = {
	freq_to_timerval(38462),
	52,		// # of pairs
	3,		// # of bits per index
	code_eu051Times,
	{
		0x60, 0x82, 0x00, 0x20, 0x80, 0x41, 0x04, 0x90, 0x41, 0x2A, 0x02, 0x08, 0x00,
		0x82, 0x01, 0x04, 0x12, 0x41, 0x04, 0x80
	}
};// Duplicate IR Code? - Similar to NA115

const uint16_t code_eu052Times[] PROGMEM = {
	16, 838,
	17, 558,
	17, 839,
	17, 6328
};
const struct IrCode code_eu052Code PROGMEM = {
	freq_to_timerval(31250),
	24,		// # of pairs
	2,		// # of bits per index
	code_eu052Times,
	{
		0x1A, 0x9A, 0x9B, 0x9A, 0x9A, 0x99
	}
};// Duplicate IR Code? -  Similar to EU017


const struct IrCode code_eu053Code PROGMEM = {
	freq_to_timerval(34483),
	16,		// # of pairs
	2,		// # of bits per index
	code_eu046Times,
	{
		0x26, 0xAB, 0x66, 0xAA
	}
};
const uint16_t code_eu054Times[] PROGMEM = {
	49, 53,
	49, 104,
	49, 262,
	49, 264,
	49, 8030,
	100, 103
};
const struct IrCode code_eu054Code PROGMEM = {
	freq_to_timerval(31250),
	14,		// # of pairs
	3,		// # of bits per index
	code_eu054Times,
	{
		0x40, 0x1A, 0x23, 0x00, 0xD0, 0x80
	}
};

const struct IrCode code_eu057Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na004Times,
	{
		0xA0, 0x00, 0x41, 0x04, 0x92, 0x08, 0x20, 0x02, 0x00, 0x04, 0x90, 0x49, 0x2B,
		0x3D, 0x00
	}
}; // Duplicate IR code - same as EU008

const struct IrCode code_eu058Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na009Times,
	{
		0x80, 0x00, 0x00, 0x24, 0x10, 0x49, 0x00, 0x82, 0x00, 0x04, 0x10, 0x49, 0x2A,
		0xBA, 0x00
	}
};
const uint16_t code_eu059Times[] PROGMEM = {
	310, 613,
	310, 614,
	622, 8312
};
const struct IrCode code_eu059Code PROGMEM = {
	freq_to_timerval(41667),
	4,		// # of pairs
	2,		// # of bits per index
	code_eu059Times,
	{
		0x26
	}
};

const struct IrCode * const EUpowerCodes[] PROGMEM = {
	&code_epsonCode,
	&code_eu000Code,
	&code_HitachiVPCode,
	&code_TNT1Code,
	&code_eu001Code,
	&code_eu002Code,
	&code_epsonCode,
	&code_na000Code,
	&code_HitachiVPCode,
	&code_eu004Code,
	&code_eu005Code,
	&code_eu006Code,
	&code_eu007Code,
	&code_eu008Code,
	&code_na005Code,
	&code_na004Code,
	&code_CAE33Code,
	&code_SX263UCode,
	&code_V718UCode,
	&code_S33Code,
	&code_EUR7623X70Code,
	&code_EUR7914Z20Code,
	&code_N2QAYB000239Code,
	&code_RC8861Code,
	&code_RD427ECode,
	&code_eu011Code,
	&code_eu012Code,
	&code_eu013Code,
	&code_na021Code,
	&code_eu015Code,
	&code_eu016Code,
	&code_eu017Code,
	&code_eu018Code,
	&code_eu019Code,
	&code_eu020Code,
	&code_eu021Code,
	&code_eu022Code,
	&code_na022Code,
	&code_eu024Code,
	&code_eu025Code,
	&code_eu026Code,
	&code_eu027Code,
	&code_eu028Code,
	&code_eu029Code,
	&code_eu030Code,
	&code_eu031Code,
	&code_eu032Code,
	&code_eu033Code,
	&code_eu034Code,
	&code_eu036Code,
	&code_eu037Code,
	&code_eu038Code,
	&code_eu039Code,
	&code_eu040Code,
	&code_eu041Code,
	&code_eu042Code,
	&code_eu043Code,
	&code_eu044Code,
	&code_eu045Code,
	&code_eu046Code,
	&code_eu047Code,
	&code_eu048Code,
	&code_eu049Code,
	&code_eu050Code,
	&code_eu051Code,
	&code_eu052Code,
	&code_eu053Code,
	&code_eu054Code,
	&code_eu057Code,
	&code_eu058Code,
	&code_eu059Code
};

const uint8_t num_EUcodes = NUM_ELEM(EUpowerCodes);
