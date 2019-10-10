#ifndef __UART_H
#define __UART_H

#include "LPC17xx.h"

#define U_LCR LPC_UART3->LCR
#define U_LSR LPC_UART3->LSR
#define U_DLL LPC_UART3->DLL
#define U_DLM LPC_UART3->DLM
#define U_THR LPC_UART3->THR
#define U_RBR LPC_UART3->RBR
#define U_FCR LPC_UART3->FCR

// U_LCR regr bits
#define DLAB		7
#define PARITY		3
#define STOP		2
#define DATALEN0	0
#define DATALEN1	1

// U_LSR regr bits
#define RDR			0
#define THRE		5

// U_FCR regr bits
#define FIFOEN		0

void uart_init(uint32_t baud);
void uart_putchar(char ch);
char uart_getchar(void);
void uart_putstring(char str[]);
void uart_getstring(char str[]);

#endif

