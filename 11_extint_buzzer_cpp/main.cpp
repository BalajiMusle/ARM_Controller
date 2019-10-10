#include "LPC17xx.h"
#include "buzzer.h"
#include "eint.h"

int main()
{
	buzzer b;
	eint2 e;
	b.beep(1000);
	while(1)
	{
		while(!eint2::get_switch_released());
		b.beep(1000);
		eint2::set_switch_released(0);
	}
	return 0;
}

