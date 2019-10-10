#include "LPC17xx.h"
#include "lcd.h"
int main()
{
	SystemInit();
	lcd_init();
	lcd_write(LCD_LINE1, "DESD @ SUNBEAM");
	lcd_write(LCD_LINE2, "GOD BLESS YOU!");
	while(1);
	return 0;
}

