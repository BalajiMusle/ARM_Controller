#include "LPC17xx.h"
#include "lcd.h"

int main()
{
	SystemInit();
	lcd_init();
	lcd_write(LCD_LINE1,"balaji");
	lcd_write(LCD_LINE2,"musle");
	while(1);
	return 0;
}


