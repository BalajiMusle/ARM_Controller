
#include "LPC17xx.h"
#include "led.h"

int main()
{
	SystemInit();
	led_init();
	while(1)
	{
		led_blink(1000);
		SW_DELAY_MS(1000);
	}
	return 0;
}
