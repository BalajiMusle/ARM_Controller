#include "timer.h"

volatile int timer0_intr_flag = 0;
void timer_init(uint32_t ms)
{
	uint32_t cnt;
	//1. use timer0 as timer (PCLK)
	LPC_TIM0->CTCR = CTCR_TIMER_VAL;
	//2. reset the timer & disable timer
	LPC_TIM0->TCR = BV(TCR_RESET);
	//3. setup prescalar value
	LPC_TIM0->PR = PR_VAL - 1;	
	//4. calculate counter value for given delay
	cnt = (PCLK / 1000) * ms / PR_VAL;
	//5. set value in match regr (MR0)
	LPC_TIM0->MR0 = cnt - 1;
	//6. generate intr and reset timer when match with MR0 -- MCR
	LPC_TIM0->MCR = BV(MCR_MR0I) | BV(MCR_MR0R);
	//7. enable timer intr in NVIC
	NVIC_EnableIRQ(TIMER0_IRQn);
	//8. enable timer
	LPC_TIM0->TCR = BV(TCR_EN);
}

void TIMER0_IRQHandler(void)
{
	//1. clear intr flag from IR
	LPC_TIM0->IR |= BV(IR_MR0);
	//2. set the timer intr flag
	timer0_intr_flag = 1;
}





