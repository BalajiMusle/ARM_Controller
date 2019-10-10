#include "LPC17xx.h"
#include "lcd.h"
#include "adc.h"
#include <stdio.h>

int main()
{
   char str[18];
   int res;
   SystemInit();
   lcd_init();
   lcd_puts(LCD_LINE1, "ADC DEMO");
   adc_init();
   while(1)
   {
       res = adc_read();
       sprintf(str, "RESULT : %04d", res);
       lcd_puts(LCD_LINE2, str);
       SW_DELAY_MS(1000);
   }   
}

