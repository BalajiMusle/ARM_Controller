#include "lcd.h"

void lcd_send_nibble(uint8_t rs_flag, uint8_t data)
{
	// set RS flag: cmd=0, data=1
	if(rs_flag==LCD_CMD)
		LCD_CTRL_CLR = BV(LCD_RS);
	else
		LCD_CTRL_SET |= BV(LCD_RS);
	// set RW=0
	LCD_CTRL_CLR = BV(LCD_RW);
	// write data on lcd data port
	LCD_DATA_CLR = BV(LCD_D4) | BV(LCD_D5) | BV(LCD_D6) | BV(LCD_D7);
	LCD_DATA_SET |= ((uint32_t)data << LCD_D4);
	// send falling edge pulse on EN
	LCD_CTRL_SET |= BV(LCD_EN);
	SW_DELAY_MS(1);
	LCD_CTRL_CLR = BV(LCD_EN);
}

void lcd_busy_wait(void)
{
	// make D7 pin as input
	LCD_DATA_DIR &= ~BV(LCD_D7);
	// RS=0
	LCD_CTRL_CLR = BV(LCD_RS);
	// RW=1, EN=1
	LCD_CTRL_SET |= BV(LCD_RW) | BV(LCD_EN);
	// wait until D7 (Busy Flag) become 0
	while((LCD_DATA_PIN & BV(LCD_D7))!=0);
	// RW=0, EN=0
	LCD_CTRL_CLR = BV(LCD_EN);
	// make D7 pin as output again
	LCD_DATA_DIR |= BV(LCD_D7);	
}
void lcd_send_byte(uint8_t rs_flag, uint8_t data)
{
	uint8_t low = data & 0x0F;
	uint8_t high = data >> 4;
	lcd_send_nibble(rs_flag, high);
	lcd_send_nibble(rs_flag, low);
	lcd_busy_wait();
	SW_DELAY_MS(3);
}
void lcd_init(void)
{
	// set data & ctrl ports as output
	LCD_DATA_DIR |= BV(LCD_D4) | BV(LCD_D5) | BV(LCD_D6) | BV(LCD_D7);
	LCD_CTRL_DIR |= BV(LCD_BL) | BV(LCD_RS) | BV(LCD_EN) | BV(LCD_RW);
	// send 0 on ports
	LCD_DATA_CLR = BV(LCD_D4) | BV(LCD_D5) | BV(LCD_D6) | BV(LCD_D7);
	LCD_CTRL_CLR = BV(LCD_BL) | BV(LCD_RS) | BV(LCD_EN) | BV(LCD_RW);
	SW_DELAY_MS(100);
	// 4-bit, 2-lines, 5x10 font
	lcd_send_byte(LCD_CMD, 0x2C);
	// display on
	lcd_send_byte(LCD_CMD, 0x0C);
	// entry mode set
	lcd_send_byte(LCD_CMD, 0x06);
	// lcd clear
	lcd_send_byte(LCD_CMD, 0x01);
	SW_DELAY_MS(100);
}
void lcd_puts(uint32_t line, char str[])
{
	int i;
	lcd_send_byte(LCD_CMD, line);
	for(i=0; str[i]!='\0'; i++)
		lcd_send_byte(LCD_DATA, str[i]);
}
