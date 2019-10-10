#include "lcd.h"

void lcd_init(void)
{
	LCD_CTRL_LINE->FIODIR |=BV(LCD_RS)|BV(LCD_RW)|BV(LCD_EN);
	LCD_DATA_LINE->FIODIR |=BV(LCD_D4)|BV(LCD_D5)|BV(LCD_D6)|BV(LCD_D7);
	SW_DELAY_MS(200);
	lcd_write_byte(LCD_CMD, LCD_BIT4_LINE2_FONT5X8);
	lcd_write_byte(LCD_CMD, LCD_DISP_ON);
	lcd_write_byte(LCD_CMD, LCD_CLR);
	lcd_write_byte(LCD_CMD, LCD_ENTRY_INCADDR);

}
void lcd_write(uint8_t line, const char *str)
{
	int i;
	lcd_write_byte(LCD_CMD, line);
	for(i=0;str[i]!='\0';i++)
		lcd_write_byte(LCD_DATA, str[i]);

}

void lcd_write_byte(uint8_t rs_flag, uint8_t val)
{
	uint8_t high,low;
	high=val>>4;
	low=val & 0x0F;
	if(rs_flag==LCD_DATA)
		LCD_CTRL_LINE->FIOSET=BV(LCD_RS);
	else
		LCD_CTRL_LINE->FIOCLR=BV(LCD_RS);
	LCD_CTRL_LINE->FIOCLR=BV(LCD_RW);
	lcd_write_nibble(high);
	lcd_write_nibble(low);
	lcd_busy_wait();
	SW_DELAY_MS(3);
}

void lcd_write_nibble(uint8_t nibble)
{
	LCD_DATA_LINE->FIOCLR = BV (LCD_D4)|BV(LCD_D5)|BV(LCD_D6)|BV(LCD_D7);
	LCD_DATA_LINE->FIOSET=(uint32_t)nibble<<LCD_D4;
	LCD_CTRL_LINE->FIOSET=BV(LCD_EN);
	SW_DELAY_MS(1);
	LCD_CTRL_LINE->FIOCLR=BV(LCD_EN);

}
void lcd_busy_wait(void)
{
	LCD_CTRL_LINE->FIOCLR=BV(LCD_RS);
	LCD_CTRL_LINE->FIOSET=BV(LCD_EN )|BV(LCD_RW);
	LCD_DATA_LINE->FIODIR&=~BV(LCD_BF);
	while(LCD_DATA_LINE->FIOPIN&BV(LCD_BF));
	LCD_DATA_LINE->FIODIR |=BV(LCD_BF);
	LCD_CTRL_LINE->FIOCLR =BV(LCD_EN);
}


