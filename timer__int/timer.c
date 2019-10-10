#include"timer.h"

volatile int timer0_intr_flag = 0;
void timer_init(uint32_t ms)
{
	uint32_t cnt;
	LPC_TIM0->CTCR = CTCR_TIMER_VAL;
	LPC_TIM0->TCR = BV(TCR_RESET);
	LPC_TIM0->PR = PR_VAL-1;
	cnt = (PCLK/1000)*ms/PR_VAL;
	LPC_TIM0->MR0=cnt-1;
	LPC_TIM0->MCR = BV (MCR_MR0I)| BV (MCR_MR0R);
	NVIC_EnableIRQ(TIMER0_IRQn);
	LPC_TIM0->TCR = BV(TCR_EN);
}

void TIMER0_IRQHandler(void)
{

LPC_TIM0->IR |= BV(IR_MR0);
timer0_intr_flag = 1;
}
