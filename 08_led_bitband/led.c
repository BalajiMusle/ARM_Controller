#include "LPC17xx.h"
#include "led.h"

void led_init(void)
{
	LED_IODIR = 1;
	led_off();
}
void led_on(void)
{
	LED_IOSET = 1;
}
void led_off(void)
{
	LED_IOCLR = 1;
}
void led_blink(uint32_t delay_ms)
{
	led_on();
	SW_DELAY_MS(delay_ms);
	led_off();
}

