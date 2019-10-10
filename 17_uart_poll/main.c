
#include <string.h>
#include "LPC17xx.h"
#include "uart.h"

int main()
{
	char str[32];
	SystemInit();
	uart_init(9600);	
	uart_puts("Sunbeam DESD -- UART Demo ...\r\n");
	uart_puts("Enter a string : \r\n");
	while(1)
	{
		uart_gets(str);
		strupr(str);
		uart_puts(str);
	}
	return 0;
}
