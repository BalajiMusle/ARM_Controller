#ifndef __WDT_H
#define __WDT_H

#include "LPC17xx.h"

#define PCLK 18000000U

void wdt_init(uint32_t ms);
void wdt_feed(void);
void wdt_check(void);

enum wdmod_bits
{
	WDMOD_EN = 0,
	WDMOD_RESET = 1,
	WDMOD_TOF = 2,
	WDMOD_INT = 3
};

enum wdclksel_bits
{
	WDCLKSEL_SEL0 = 0,
	WDCLKSEL_SEL1 = 1
};

#endif


