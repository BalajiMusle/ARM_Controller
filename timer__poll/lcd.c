#include "lcd.h"

void lcd_init(void)
{
	// make all port pins as output
	LCD_CTRL_GPIO->FIODIR |= BV(LCD_RS) | BV(LCD_EN) | BV(LCD_RW);	
	LCD_DATA_GPIO->FIODIR |= BV(LCD_D4) | BV(LCD_D5) | BV(LCD_D6) | BV(LCD_D7);	
	SW_DELAY_MS(200);
	// init lcd - 4-bit mode, display on, clear display, entry mode incr addr
	lcd_write_byte(LCD_CMD, LCD_BIT4_LINE2_FONT5x8);
	lcd_write_byte(LCD_CMD, LCD_DISPLAY_ON);
	lcd_write_byte(LCD_CMD, LCD_CLEAR);
	lcd_write_byte(LCD_CMD, LCD_ENTRY_INCADDR);
}
void lcd_write(uint8_t line, const char *str)
{
	int i;
	// set line start addr
	lcd_write_byte(LCD_CMD, line);
	// write all chars one by one
	for(i=0; str[i]!='\0'; i++)
		lcd_write_byte(LCD_DATA, str[i]);
}
void lcd_write_byte(uint8_t rs_flag, uint8_t val)
{
	uint8_t high, low;
	high = val >> 4;
	low = val & 0x0F;
	// for data RS=1, for cmd RS=0.
	if(rs_flag == LCD_DATA)
		LCD_CTRL_GPIO->FIOSET = BV(LCD_RS);
	else
		LCD_CTRL_GPIO->FIOCLR = BV(LCD_RS);
	// for write : RW=0
	LCD_CTRL_GPIO->FIOCLR = BV(LCD_RW);
	// write high nibble
	lcd_write_nibble(high);
	// write low nibble
	lcd_write_nibble(low);
	// busy wait
	lcd_busy_wait();
	SW_DELAY_MS(3);
}
void lcd_write_nibble(uint8_t nibble)
{
	// write nibble on LCD_D4 to LCD_D7
	LCD_DATA_GPIO->FIOCLR = BV(LCD_D4) | BV(LCD_D5) | BV(LCD_D6) | BV(LCD_D7);	
	LCD_DATA_GPIO->FIOSET = (uint32_t)nibble << LCD_D4;
	// falling edge on LCD_EN
	LCD_CTRL_GPIO->FIOSET = BV(LCD_EN);
	SW_DELAY_MS(1);
	LCD_CTRL_GPIO->FIOCLR = BV(LCD_EN);
}
void lcd_busy_wait(void)
{
	// to read BF, RS=0, RW=1, EN=1
	LCD_CTRL_GPIO->FIOCLR = BV(LCD_RS);
	LCD_CTRL_GPIO->FIOSET = BV(LCD_RW) | BV(LCD_EN);
	// make LCD_BF pin as input
	LCD_DATA_GPIO->FIODIR &= ~BV(LCD_BF);
	// read BF & wait while it is 1
	while(LCD_DATA_GPIO->FIOPIN & BV(LCD_BF));
	// make LCD_BF pin as output
	LCD_DATA_GPIO->FIODIR |= BV(LCD_BF);
	// after read EN=0
	LCD_CTRL_GPIO->FIOCLR = BV(LCD_EN);
}






