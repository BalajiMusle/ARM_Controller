#include "LPC17xx.h"
#include "timer.h"
#include "lcd.h"
#include "led.h"
#include "wdt.h"
#include <stdio.h>

int main()
{
	char str[20];
	int i=0;
	SystemInit();
	lcd_init();
	lcd_puts(LCD_LINE1, "WDT Demo");
	wdt_check();
	led_init();
	timer_init();
	wdt_init(2000);
	while(1)
	{
		led_toggle();
		sprintf(str, "%d   ", i);
		lcd_puts(LCD_LINE2, str);
		i++;
		timer_delay(1000);
		wdt_feed();
	}
}

