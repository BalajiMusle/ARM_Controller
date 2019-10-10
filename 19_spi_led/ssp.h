#ifndef __SSP_H
#define __SSP_H

#include "LPC17xx.h"

#define SSEL	16

#define LPC_SSP	LPC_SSP0

#define DATALEN_Val	8
#define SCR_Val		0
#define CPSR_Val	18

enum sspcr0_bits
{
	CR_FRF0 = 4,
	CR_FRF1 = 5,
	CR_CPOL = 6,
	CR_CPHA = 7,
	CR_SCR = 8
};

enum sspcr1_bits
{
	CR_EN = 1
};

enum sspsr_bits
{
	SR_RXFFNE = 2	
};

void ssp_init(void);
uint16_t ssp_transfer(uint16_t val);

#endif


