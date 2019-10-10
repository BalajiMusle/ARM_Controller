#include "LPC17xx.h"
#include "led.h"

void led_init(void)
{
	LED_IODIR |= BV(LED);
	led_off();
}
void led_on(void)
{
	LED_IOSET |= BV(LED);
}
void led_off(void)
{
	LED_IOCLR = BV(LED);
}
void led_blink(uint32_t delay_ms)
{
	led_on();
	SW_DELAY_MS(delay_ms);
	led_off();
}

