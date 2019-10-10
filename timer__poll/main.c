#include <stdio.h>
#include "LPC17xx.h"
#include "lcd.h"
#include "timer.h"
int main()
{
	char str[20];
	int cntr = 0;
	SystemInit();
	lcd_init();
	timer_init();
	lcd_write(LCD_LINE1,"desd balaji");
	while(1)
	{
		sprintf(str, "COUNT :%d   ",++cntr);
		lcd_write(LCD_LINE2, str);
		timer_delay(1000);
	}
	return 0;

}
