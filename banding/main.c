#include "LPC17xx.h"
#include "led.h"

int main()
{
	SystemInit();
	led_init();
	while(1)
	{
		led_blink(100);
		SW_DELAY_MS(100);
	}
	return 0;
}	
	
