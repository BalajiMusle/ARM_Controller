#include "LPC17xx.h"

void buzzer_init(void);
void buzzer_on(void);
void buzzer_off(void);
void buzzer_beep(uint32_t delay_ms);

int main()
{
	int i;
	SystemInit();
	buzzer_init();
	for(i=0; i<3; i++)
	{
		buzzer_beep(2000);
		SW_DELAY_MS(2000);
	}
	while(1);
	return 0;
}

void buzzer_init(void)
{
	// make buzzer pin as output pin
	LPC_GPIO2->FIODIR |= BV(11);
	// buzzer off
	buzzer_off();
}
void buzzer_on(void)
{
	// buzzer on -> make buzzer pin low
	LPC_GPIO2->FIOCLR = BV(11);
}
void buzzer_off(void)
{
	// buzzer off -> make buzzer pin high
	LPC_GPIO2->FIOSET |= BV(11);
}
void buzzer_beep(uint32_t delay_ms)
{
	// buzzer on
	buzzer_on();
	// delay ms
	SW_DELAY_MS(delay_ms);
	// buzzer off
	buzzer_off();
}

