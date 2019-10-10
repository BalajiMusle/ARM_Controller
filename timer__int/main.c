#include <stdio.h>
#include"LPC17xx.h"
#include"lcd.h"
#include"timer.h"
int main()
{
	char str[20];
	int cntr = 0;
	SystemInit();
	lcd_Init();
	timer_Init(1000);
	lcd_write(LCD_LINE1, "desd balaji");
	while(1)
	{
		while(timer0_intr_flag == 0);
		timer0_intr_flag = 0;
		sprintf(str,"COUNT : %d ",++cntr);
		lcd_write(LCD_LINE2,str);
	}
	return 0;
}

