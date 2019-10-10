#include "timer.h"

void timer_init(void)
{
	//1. use timer0 as timer (PCLK)
	LPC_TIM0->CTCR = CTCR_TIMER_VAL;
	//2. reset the timer & disable timer
	LPC_TIM0->TCR = BV(TCR_RESET);
	//3. setup prescalar value
	LPC_TIM0->PR = PR_VAL - 1;
}

void timer_delay(uint32_t ms)
{
	uint32_t cnt;
	//1. calculate counter value for given delay
	cnt = (PCLK / 1000) * ms / PR_VAL;
	//2. set value in match regr (MR0)
	LPC_TIM0->MR0 = cnt - 1;
	//3. generate intr, reset and stop timer when match with MR0 -- MCR
	LPC_TIM0->MCR = BV(MCR_MR0I) | BV(MCR_MR0R) | BV(MCR_MR0S);
	//4. enable timer
	LPC_TIM0->TCR = BV(TCR_EN);
	//5. wait until interrupt is genrated -- polling IR
	while((LPC_TIM0->IR & BV(IR_MR0)) == 0);
	//6. clear intr flag from IR
	LPC_TIM0->IR |= BV(IR_MR0);
	//7. reset the timer & disable timer
	LPC_TIM0->TCR = BV(TCR_RESET);
}





