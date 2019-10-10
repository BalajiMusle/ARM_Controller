
#include "LPC17xx.h"
#include "buzzer.h"
#include "eint.h"

int main()
{
	SystemInit();
	buzzer_init();
	eint2_init();
	buzzer_beep(2000);
	while(1);
	return 0;
}
