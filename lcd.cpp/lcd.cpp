#include "lcd.h"

lcd::lcd(void)
{
	LCD_CTRL_LINE->FIODIR |=BV(LCD_RS)|BV(LCD_RW)|BV(LCD_EN);
	LCD_DATA_LINE->FIODIR |=BV(LCD_D4)|BV(LCD_D5)|BV(LCD_D6)|BV(LCD_D7);
	SW_DELAY_MS(200);
	write_byte(LCD_CMD, LCD_BIT4_LINE2_FONT5x8);
	write_byte(LCD_CMD, LCD_DISPLAY_ON);
	write_byte(LCD_CMD, LCD_CLEAR);
	write_byte(LCD_CMD, LCD_ENTRY_INCADDR);

}
void lcd::write(uint8_t line, const char *str)
{
	int i;
	write_command( line);
	for(i=0;str[i]!='\0';i++)
		write_char( str[i]);

}

void lcd::write_byte(uint8_t rs_flag, uint8_t val)
{
	uint8_t high,low;
	high=val>>4;
	low=val & 0x0F;
	if(rs_flag==LCD_DATA)
		LCD_CTRL_LINE->FIOSET=BV(LCD_RS);
	else
		LCD_CTRL_LINE->FIOCLR=BV(LCD_RS);
	LCD_CTRL_LINE->FIOCLR=BV(LCD_RW);
    write_nibble(high);
	write_nibble(low);
	busy_wait();
	SW_DELAY_MS(3);
}

void lcd::write_nibble(uint8_t nibble)
{
	LCD_DATA_LINE->FIOCLR = BV (LCD_D4)|BV(LCD_D5)|BV(LCD_D6)|BV(LCD_D7);
	LCD_DATA_LINE->FIOSET=(uint32_t)nibble<<LCD_D4;
	LCD_CTRL_LINE->FIOSET=BV(LCD_EN);
	SW_DELAY_MS(1);
	LCD_CTRL_LINE->FIOCLR=BV(LCD_EN);

}
void lcd::busy_wait(void)
{
	LCD_CTRL_LINE->FIOCLR=BV(LCD_RS);
	LCD_CTRL_LINE->FIOSET=BV(LCD_EN )|BV(LCD_RW);
	LCD_DATA_LINE->FIODIR&=~BV(LCD_BF);
	while(LCD_DATA_LINE->FIOPIN&BV(LCD_BF));
	LCD_DATA_LINE->FIODIR |=BV(LCD_BF);
	LCD_CTRL_LINE->FIOCLR =BV(LCD_EN);
}


