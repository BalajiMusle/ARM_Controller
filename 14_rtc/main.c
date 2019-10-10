#include <stdio.h>
#include "LPC17xx.h"
#include "lcd.h"
#include "timer.h"
#include "rtc.h"
int main()
{
	char str[20];
	rtc_t tm = { 0, 0, 20, 14, 3, 2018, 4, 73 };
	SystemInit();
	lcd_init();
	timer_init();
	rtc_init();
	rtc_set(&tm);
	lcd_write(LCD_LINE1, "DESD @ SUNBEAM");
	lcd_write_byte(LCD_CMD, LCD_CLEAR);
	while(1)
	{
		rtc_get(&tm);
		sprintf(str, " %02d-%02d-%04d ", tm.day, tm.month, tm.year);
		lcd_write(LCD_LINE1, str);
		sprintf(str, " %02d:%02d:%02d ", tm.hour, tm.minute, tm.sec);
		lcd_write(LCD_LINE2, str);
		timer_delay(1000);
	}
	return 0;
}

