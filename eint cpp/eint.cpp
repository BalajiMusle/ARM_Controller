#include "LPC17xx.h"
#include "eint.h"
#include "buzzer.h"

volatile int eint2::switch_released = 0;

eint2::eint()
{

		LPC_PINCON->PINSEL 4 &=~(BV(25)|(24) );
		LPC_PINCON->PINSEL 4 |=(24) ;
		LPC_PINCON->PINSEL 4 =(BV(25)|(24) );
		LPC_PINCON->PINSEL 4 &=~(BV(25)|(24) );
		LPC_PINCON->PINSEL 4 &=~(BV(25)|(24) );
