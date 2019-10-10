#include "ssp.h"

void ssp_init(void)
{
	// use P0.15, P0.17, P0.18 as SSP0 pins using PINSEL0 & PINSEL1.
	LPC_PINCON->PINSEL0 &= ~(BV(31) | BV(30));
	LPC_PINCON->PINSEL0 |= BV(31);
	LPC_PINCON->PINSEL1 &= ~(BV(5)|BV(4)|BV(3)|BV(2)|BV(1)|BV(0));
	LPC_PINCON->PINSEL1 |= BV(5) | BV(3);
	// use P0.16 as GPIO to select slave -- dirn output.
	LPC_GPIO0->FIODIR |= BV(SSEL);
	LPC_GPIO0->FIOSET |= BV(SSEL);
	// set up prescalar for ssp
	LPC_SSP->CPSR = CPSR_Val;
	// configure ssp using CR0 & enable using CR1.
	LPC_SSP->CR0 = (DATALEN_Val-1) | BV(CR_CPOL) | BV(CR_CPHA) | (SCR_Val << CR_SCR);
	LPC_SSP->CR1 |= BV(CR_EN);
}

uint16_t ssp_transfer(uint16_t val)
{
	uint16_t temp;
	// enable slave
	LPC_GPIO0->FIOCLR = BV(SSEL);
	// put data in DR regr
	LPC_SSP->DR = val;
	// wait for data transfer
	while((LPC_SSP->SR & BV(SR_RXFFNE))==0);
	temp = LPC_SSP->DR;
	// disable slave
	LPC_GPIO0->FIOSET |= BV(SSEL);
	// read data
	return temp;
}

