#include "LPC17xx.h"
#include "eint.h"
#include "buzzer.h"

void eint2_init(void)
{
	//1. select P2.12 as EINT2: PINSEL4[25:24] = 01
	LPC_PINCON->PINSEL4 &= ~(BV(25) | BV(24));
	LPC_PINCON->PINSEL4 |= BV(24);
	//2. set EINT2 as edge trigger: EXTMODE[2] = 1
	LPC_SC->EXTMODE |= BV(EINT2);
	//3. set EINT2 as rising edge: EXTPOLAR[2] = 1
	LPC_SC->EXTPOLAR |= BV(EINT2);
	//4. enable intr from EINT2: EXTINT[2] = 1
	LPC_SC->EXTINT |= BV(EINT2);
	//5. NVIC_EnableIRQ(EINT2_IRQn);
	NVIC_EnableIRQ(EINT2_IRQn);
}

void EINT2_IRQHandler(void)
{
	//1. clear intr flag: EXTINT[2] = 1
	LPC_SC->EXTINT |= BV(EINT2);
	//2. buzzer_beep();
	buzzer_beep(2000);
}

