#include "LPC17xx.h"
#include "buzzer.h"
#include "eint.h"

int main()
{
	SystemInit();
	buzzer_init();
	eint2_init();
	buzzer_beep(1000);
	while(1)
	{
		while(!switch_released);

		      buzzer_beep(1000);
			  switch_released = 0;
	}

	return 0;
}

