
#ifndef __EINT_H
#define __EINT_H

#define EINT2 2

void eint2_init(void);
void EINT2_IRQHandler(void);

extern volatile int switch_released;

#endif

