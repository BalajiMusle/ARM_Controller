#ifndef __LED_H
#define __LED_H
#include "LPC17xx.h"

#define LED_GPIO LPC_GPIO1
#define LED 29

void led_init(void);
void led_on(void);
void led_off(void);
void led_toggle(void);

#endif
