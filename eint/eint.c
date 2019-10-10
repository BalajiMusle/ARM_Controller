#include "LPC17xx.h"
#include "eint.h"
#include "buzzer.h"
volatile int switch_released = 0;
void eint2_init(void)
{

	LPC_PINCON->PINSEL4 &=~(BV(25)| BV(24));
	LPC_PINCON->PINSEL4 |= BV (24);
	LPC_SC->EXTMODE |= BV(EINT2);
	LPC_SC->EXTPOLAR |= BV(EINT2);
	LPC_SC->EXTINT |= BV(EINT2);
	NVIC_EnableIRQ(EINT2_IRQn);
}
void EINT2_IRQHandler(void)
{
	LPC_SC->EXTINT |=BV(EINT2);
	buzzer_beep(2000);
}
