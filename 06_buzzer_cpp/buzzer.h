#ifndef __BUZZER_H
#define __BUZZER_H

#include "LPC17xx.h"

#define BUZZER	11
#define BUZZER_GPIO LPC_GPIO2

class buzzer
{
private:
	bool state; //true=ON, false=OFF
public:
	buzzer();
	void set_state(bool state);
	bool get_state();
	void on();
	void off();
	void beep(uint32_t delay_ms);
};

#endif
