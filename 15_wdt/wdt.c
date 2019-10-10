#include "wdt.h"
#include "lcd.h"
#include <stdio.h>
#define WDT_PRESCALAR	4

void wdt_init(uint32_t ms)
{
	uint32_t reload;
	LPC_WDT->WDCLKSEL = BV(WDCLKSEL_SEL0);	// Set CLK src to PCLK
	reload = (PCLK / 1000 /  WDT_PRESCALAR) * ms;
	LPC_WDT->WDTC = reload;
	LPC_WDT->WDMOD = BV(WDMOD_EN) | BV(WDMOD_RESET);		// Enabled and Reset
	wdt_feed();
}

void wdt_feed(void)
{
	LPC_WDT->WDFEED = 0xAA;
	LPC_WDT->WDFEED = 0x55;
}

void wdt_check(void)
{
	if (LPC_WDT->WDMOD & BV(WDMOD_TOF))
	{
		lcd_puts(LCD_LINE2, "WDT Reset");
		LPC_WDT->WDMOD &= ~BV(WDMOD_TOF);
		while(1);
	}
}

