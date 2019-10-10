#include "buzzer.h"

void buzzer_init(void)
{
	// make buzzer pin as output pin
	BUZZER_GPIO->FIODIR |= BV(BUZZER);
	// buzzer off
	buzzer_off();
}
void buzzer_on(void)
{
	// buzzer on -> make buzzer pin low
	BUZZER_GPIO->FIOCLR = BV(BUZZER);
}
void buzzer_off(void)
{
	// buzzer off -> make buzzer pin high
	BUZZER_GPIO->FIOSET |= BV(BUZZER);
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

