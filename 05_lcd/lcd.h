#ifndef __LCD_H
#define __LCD_H

#include "LPC17xx.h"

#define LCD_DATA_GPIO	LPC_GPIO2
#define LCD_D4	4
#define LCD_D5	5
#define LCD_D6	6
#define LCD_D7	7
#define LCD_BF	LCD_D7

#define LCD_CTRL_GPIO	LPC_GPIO1
#define LCD_EN	22
#define LCD_RW	23
#define LCD_RS	24

#define LCD_CLEAR				0x01
#define LCD_BIT4_LINE2_FONT5x8	0x28
#define LCD_DISPLAY_ON			0x0C
#define LCD_ENTRY_INCADDR		0x06
#define LCD_LINE1				0x80
#define LCD_LINE2				0xC0

#define LCD_DATA	1
#define LCD_CMD		0

void lcd_init(void);
void lcd_write(uint8_t line, const char *str);
void lcd_write_byte(uint8_t rs_flag, uint8_t val);
void lcd_write_nibble(uint8_t nibble);
void lcd_busy_wait(void);

#endif












