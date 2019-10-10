#ifndef __BUZZER_H
#define __BUZZER_H

#include "LPC17xx.h"

#define BUZZER	11
#define BUZZER_GPIO LPC_GPIO2

void buzzer_init(void);
void buzzer_on(void);
void buzzer_off(void);
void buzzer_beep(uint32_t delay_ms);

#endif
