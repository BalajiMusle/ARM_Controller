
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
		/*
		// non-volatile / optimization enabled
		LDR r7, =switch_released
		LDR r0, [r7]
	loop:
		CMP r0, #0
		BEQ loop
		*/
		/*
		// volatile / optimization disabled
		LDR r7, =switch_released
	loop:
		LDR r0, [r7]
		CMP r0, #0
		BEQ loop
		*/
		buzzer_beep(1000);
		switch_released = 0;
	}
	return 0;
}
