#include "uart.h"
#include <stdio.h>

#define PCLK 18000000U

void uart_init(uint32_t baud)
{
	uint16_t divisor;
	// TxD3 is P0.0 and RxD3 is P0.1 --> PINSEL VAL : 10
	LPC_PINCON->PINSEL0 &= ~(BV(0)|BV(1)|BV(2)|BV(3));
	LPC_PINCON->PINSEL0 |= BV(1)|BV(3);
	
	// UART: 8 bit data, 1 stop bit, no parity
	U_LCR = BV(DATALEN0) | BV(DATALEN1);
	
	// baud rate calculation
	// PCLK = SystemCoreClock / 4;
	divisor = (PCLK >> 4) / baud;
	
	// Enable FIFO
	U_FCR = BV(FIFOEN);
	
	// PCLK=18MHz, Baud=9600, then U_DLM=0, U_DLL=117
	// Modify U_DLM and U_DLL (take care of DLAB)
	U_LCR |= BV(DLAB);
	U_DLM = divisor >> 8;
	U_DLL = divisor & 0xFF;
	U_LCR &= ~BV(DLAB);
}
void uart_putchar(char ch)
{
	// wait while last char is tranmitted
	while((U_LSR & BV(THRE))==0);
	// transmit char
	U_THR = ch;
}
char uart_getchar(void)
{
	// wait while char is not recved
	while((U_LSR & BV(RDR))==0);
	// transmit char
	return U_RBR;
}
void uart_putstring(char str[])
{
	uint8_t i;
	for(i=0; str[i]!='\0'; i++)
		uart_putchar(str[i]);
}
void uart_getstring(char str[])
{
	char ch;
	uint8_t i=0;
	do {
		ch = uart_getchar();
		str[i++] = ch;
	} while(ch!='\r');
	str[i++] = '\n';
	str[i] = '\0';
}
