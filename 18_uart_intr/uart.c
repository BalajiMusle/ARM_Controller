#include <stdio.h>
#include "LPC17xx.h"
#include "uart.h"

static char *tx_string = NULL;
static int tx_index = 0;
static volatile int tx_completed = 1;

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
	//enable tx intr
	LPC_UART3->IER = BV(IER_THRE);
	NVIC_EnableIRQ(UART3_IRQn);
}

void UART3_IRQHandler(void)
{
	uint32_t iir, iid;
	while(((iir = LPC_UART3->IIR) & BV(IIR_PEND)) == 0)
	{
		iid = (iir >> 1) & IIR_IID_MASK;
		switch(iid)
		{
		case IID_THRE:
			if(tx_string[tx_index] == '\0')
			{
				tx_completed = 1;
				tx_string = NULL;
			}
			else
				LPC_UART3->THR = tx_string[tx_index++];
			break;
		case IID_RDA:
		case IID_CTI:
			break;
		case IID_RLS:
			break;
		}
	}
}

void uart_puts(char str[])
{
	while(!tx_completed);
	tx_completed = 0;
	tx_index = 0;
	tx_string = str;
	LPC_UART3->THR = tx_string[tx_index++];
}






