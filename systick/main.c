#include <stdio.h>
#include "LPC17xx.h"
#include "lcd.h"

void systick_delay(uint32_t ms);

int main()
{
	char str[20];
	int cntr = 0;
	SystemInit();
	SysTick_Config(72000);
	lcd_init();
	lcd_write(LCD_LINE1, "DESD @ SUNBEAM");
	while(1)
	{
		sprintf(str, "COUNT : %d     ", ++cntr);
		lcd_write(LCD_LINE2, str);
	 	systick_delay(1000);
	}
	return 0;
}

static volatile int counter = 0;

void systick_delay(uint32_t ms)
{
	counter = ms;
	while(counter > 0);
}

void SysTick_Handler(void)
{
	counter--;
}





