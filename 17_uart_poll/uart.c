#include "LPC17xx.h"
#include "uart.h"

void uart_init(uint32_t baud)
{
	uint16_t dl;
	//enable uart3 pin functions -- PINSEL0[1:0]=10, PINSEL[3:2]=10
	LPC_PINCON->PINSEL0 &= ~(BV(3) | BV(2) | BV(1) | BV(0));
	LPC_PINCON->PINSEL0 |= (BV(3) | BV(1));
	//enable fifo: FCR
	LPC_UART3->FCR = BV(FCR_EN);
	//uart config: LCR : 8N1 --> 8-bit data, no parity, 1 stop bit
	LPC_UART3->LCR = BV(LCR_DLAB) | BV(LCR_WL1) | BV(LCR_WL0);
	//set baud rate: calc baud and set divisor latch (DLL, DLM)
	dl = (PCLK >> 4) / baud;
	LPC_UART3->DLL = dl & 0x00FF;
	LPC_UART3->DLM = dl >> 8;
	//enable uart -- disable dlab
	LPC_UART3->LCR &= ~BV(LCR_DLAB);
}
void uart_putch(uint8_t ch)
{
	// write a char in THR
	LPC_UART3->THR = ch;
	// wait for char transmission
	while((LPC_UART3->LSR & BV(LSR_THRE)) == 0);
}
uint8_t uart_getch(void)
{
	uint8_t ch;
	// wait for data receive
	while((LPC_UART3->LSR & BV(LSR_RDR)) == 0);
	// read the data
	ch = LPC_UART3->RBR;
	// return data
	return ch;
}
void uart_puts(char str[])
{
	int i;
	// send data char by char
	for(i=0; str[i]!='\0'; i++)
		uart_putch(str[i]);
}
void uart_gets(char str[])
{
	int i=0;
	char ch;
	// receive data char by char
	do {
		ch = uart_getch();
		str[i++] = ch;
	} while(ch != '\r');
	str[i++] = '\n';
	str[i] = '\0';
}






