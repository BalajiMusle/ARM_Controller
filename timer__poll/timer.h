#ifndef __TIMER_H
#define __TIMER_H


#include "LPC17xx.h"

#define TCR_EN 0
#define TCR_RESET 1 

#define MCR_MR0I 0
#define MCR_MR0R 1
#define MCR_MR0S 2

#define IR_MR0 0

#define PCLK 18000000UL

#define CTCR_TIMER_VAL 0x00000000

#define PR_VAL 18

void timer_init(void);
void timer_delay(uint32_t ms);

#endif

