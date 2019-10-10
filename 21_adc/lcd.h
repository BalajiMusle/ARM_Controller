#ifndef __LCD_H
#define __LCD_H

#include "LPC17xx.h"

// Hardware Connections:
//	LCD RS <--> P1.24 
//	LCD RW <--> P1.23
//	LCD EN <--> P1.22
//	LCD BL <--> P1.21
//	LCD D4 <--> P2.4
//	LCD D5 <--> P2.5
//	LCD D6 <--> P2.6
//	LCD D7 <--> P2.7

#define LCD_RS	24
#define LCD_RW	23
#define LCD_EN	22
#define LCD_BL	21

#define LCD_CTRL_DIR	LPC_GPIO1->FIODIR
#define LCD_CTRL_SET	LPC_GPIO1->FIOSET
#define LCD_CTRL_CLR	LPC_GPIO1->FIOCLR
#define LCD_CTRL_PIN	LPC_GPIO1->FIOPIN
#define LCD_CTRL_MSK	LPC_GPIO1->FIOMASK

#define LCD_D4	4
#define LCD_D5	5
#define LCD_D6	6
#define LCD_D7	7

#define LCD_DATA_DIR	LPC_GPIO2->FIODIR
#define LCD_DATA_SET	LPC_GPIO2->FIOSET
#define LCD_DATA_CLR	LPC_GPIO2->FIOCLR
#define LCD_DATA_PIN	LPC_GPIO2->FIOPIN
#define LCD_DATA_MSK	LPC_GPIO2->FIOMASK

#define LCD_CMD			0
#define LCD_DATA		1
// LCD Line1 & Line2 Addresses
#define LCD_LINE1		0x80
#define LCD_LINE2		0xC0

void lcd_send_nibble(uint8_t rs_flag, uint8_t data);
void lcd_busy_wait(void);
void lcd_send_byte(uint8_t rs_flag, uint8_t data);
void lcd_init(void);
void lcd_puts(uint32_t line, char str[]);

#endif
