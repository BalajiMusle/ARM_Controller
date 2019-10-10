
#include "LPC17xx.h"
#include "led.h"

int main()
{
	SystemInit();
	led_init();
	while(1)
	{
		led_blink(2000);
		SW_DELAY_MS(2000);
	}
	return 0;
}
