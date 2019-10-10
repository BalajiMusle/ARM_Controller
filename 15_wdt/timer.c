#include "timer.h"

void timer_init(void)
{
	// timer0 is by default powered on.
	// config timer/counter to use internal clock - PCLK -- CTCR
	LPC_TIM->CTCR = 0x00;
	// reset timer -- TCR
	LPC_TIM->TCR = BV(TCR_RST);
	// set up prescalar
	LPC_TIM->PR = PR_Val - 1;
}

void timer_delay(uint32_t ms)
{
	// calc MR regr value for desired delay.
	uint32_t mr = (PCLK / 1000) * ms / PR_Val;
	// set MR0 register.
	LPC_TIM->MR0 = mr - 1;
	// set MCR to stop timer after match.
	LPC_TIM->MCR |= BV(MCR_MR0_I) | BV(MCR_MR0_S) | BV(MCR_MR0_R);
	//LPC_TIM->MCR |= BV(MCR_MR0_S) | BV(MCR_MR0_R);
	// reset & enable the timer -- TCR
	LPC_TIM->TCR = BV(TCR_EN);
	// wait for time completion -- IR
	while((LPC_TIM->IR & BV(IR_MR0))==0);
	// clear IR MR0
	LPC_TIM->IR |= BV(IR_MR0);
}

