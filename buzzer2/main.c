
#include "LPC17xx.h"
#include "buzzer.h"

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
