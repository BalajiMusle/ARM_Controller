#include "LPC17xx.h"
#include "buzzer.h"

int main()
{
	int i;
	buzzer b;
	for(i=0; i<3; i++)
	{
		b.beep(2000);
		SW_DELAY_MS(2000);
	}
	return 0;
}

