#ifndef __UART_H
#define __UART_H

#define PCLK 18000000UL

#define LPC_UART LPC_UART3

enum lcr_bits
{
	LCR_WL0=0, LCR_WL1=1, LCR_STOP=2, LCR_PAREN=3, LCR_DLAB=7

};
enum lsr_bits
{
	LSR_RDR=0,LSR_THRE=5
};
enum fcr_bits
{
	FCR_EN=0, FCR_TX_RST=2, FCR_RX_RST=1, FCR_RX_TRIGO=6,FCR_RX_TRIGO1=7
};

void uart_init(uint32_t baud);
void uart_putch(uint8_t ch);
uint8_t uart_getch(void);
void uart_puts(char str[]);
void uart_gets(char str[]);

#endif

