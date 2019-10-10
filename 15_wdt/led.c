#include "led.h"

static int state = 0;
void led_init(void)
{
	LED_GPIO->FIODIR |= BV(LED);
	led_off();
}

void led_on(void)
{
	LED_GPIO->FIOSET |= BV(LED);
	state = 1;
}

void led_off(void)
{
	LED_GPIO->FIOCLR |= BV(LED);
	state = 0;
}

void led_toggle(void)
{
	if(state)
		led_off();
	else
		led_on();
}


