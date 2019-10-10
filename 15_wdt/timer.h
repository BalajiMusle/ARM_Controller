#ifndef __TIMER_H
#define __TIMER_H

#include "LPC17xx.h"

#define LPC_TIM		LPC_TIM0

#define PCLK		18000000U
#define PR_Val		18

enum timer_tcr_bits
{
	TCR_EN=0,
	TCR_RST=1
};

enum timer_mcr_bits
{
	MCR_MR0_I=0,	
	MCR_MR0_R=1,	
	MCR_MR0_S=2,	
	MCR_MR1_I=3,	
	MCR_MR1_R=4,	
	MCR_MR1_S=5,	
	MCR_MR2_I=6,	
	MCR_MR2_R=7,	
	MCR_MR2_S=8,	
	MCR_MR3_I=9,	
	MCR_MR3_R=10,	
	MCR_MR3_S=11	
};

enum timer_ir_bits
{
	IR_MR0=0,
	IR_MR1=1,
	IR_MR2=2,
	IR_MR3=3
};

void timer_init(void);
void timer_delay(uint32_t ms);

#endif



