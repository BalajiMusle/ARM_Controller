
#include <string.h>
#include "LPC17xx.h"
#include "uart.h"

int main()
{
	SystemInit();
	uart_init(9600);	
	uart_puts("DESD @ SUNBEAM\r\n");
	uart_puts("GOD BLESS YOU!\r\n");
	while(1);
	return 0;
}
