#include "buzzer.h"

buzzer::buzzer()
{
	// make buzzer pin as output pin
	BUZZER_GPIO->FIODIR |= BV(BUZZER);
	// buzzer off
	off();
}

void buzzer::set_state(bool state)
{
	if(state)
		on();
	else
		off();
}

bool buzzer::get_state()
{
	return this->state;
}

void buzzer::on()
{
	this->state = true;
	// buzzer on -> make buzzer pin low
	BUZZER_GPIO->FIOCLR = BV(BUZZER);
}

void buzzer::off()
{
	this->state = false;
	// buzzer off -> make buzzer pin high
	BUZZER_GPIO->FIOSET |= BV(BUZZER);
}

void buzzer::beep(uint32_t delay_ms)
{
	// buzzer on
	on();
	// delay ms
	SW_DELAY_MS(delay_ms);
	// buzzer off
	off();
}

