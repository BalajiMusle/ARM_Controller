#ifndef __BUZZER_H
#define __BUZZER_H

#define LED		29

#define LED_IODIR 	(*(uint32_t*)0x2009C020)
#define LED_IOSET	(*(uint32_t*)0x2009C038)
#define LED_IOCLR	(*(uint32_t*)0x2009C03C)

void led_init(void);
void led_on(void);
void led_off(void);
void led_blink(uint32_t delay_ms);

#endif
