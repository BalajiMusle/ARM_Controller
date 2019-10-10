#include "timer.h"

void timer_init(void)
{
	LPC_TIM0->CTCR = CTCR_TIMER_VAL;
	LPC_TIM0->TCR = BV(TCR_RESET);
	LPC_TIM0->PR = PR_VAL-1;
}
 void timer_delay(uint32_t ms)
 {
	 uint32_t cnt;
	cnt=(PCLK/1000) * ms / PR_VAL;
	LPC_TIM0->MR0 = cnt-1;
	LPC_TIM0->MCR = BV(MCR_MR0I)|BV(MCR_MR0R)|BV(MCR_MR0S);
	LPC_TIM0->TCR = BV (TCR_EN);
	while((LPC_TIM0->IR & BV(IR_MR0)) == 0);
	LPC_TIM0->IR |= BV(IR_MR0);
	LPC_TIM0->TCR= BV(TCR_RESET);

 }
