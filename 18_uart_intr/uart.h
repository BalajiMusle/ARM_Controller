#ifndef __UART_H
#define __UART_H

#define PCLK	18000000UL

#define LPC_UART	LPC_UART3

enum lcr_bits
{
	LCR_WL0=0, LCR_WL1=1, LCR_STOP=2, LCR_PAREN=3, LCR_DLAB=7
};

enum lsr_bits
{
	LSR_RDR=0, LSR_THRE=5
};

enum fcr_bits
{
	FCR_EN=0, FCR_TX_RST=2, FCR_RX_RST=1, FCR_RX_TRIG0=6, FCR_RX_TRIG1=7
};

enum ier_bits
{
	IER_RBR=0, IER_THRE=1, IER_RLS=2
};

enum iir_bits
{
	IIR_PEND=0
};

#define IIR_IID_MASK	0x07
#define IID_THRE	0x01
#define IID_RDA		0x02
#define IID_CTI		0x06
#define IID_RLS		0x03

void uart_init(uint32_t baud);
void uart_puts(char str[]);
void UART3_IRQHandler(void);

#endif

