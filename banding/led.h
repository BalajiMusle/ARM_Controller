#ifndef __LED_H
#define __LED_H

#define LED 29

#define LED_IODIR_ADDR (0x2009C020)
#define LED_IOSET_ADDR (0x2009C038)
#define LED_IOCLR_ADDR (0x2009C03C)

#define SRAM_BB_RGN_START (0x20000000)
#define SRAM_BB_ALS_START (0x22000000)

#define SRAM_BBRGN2BBALS(addr,bit) (SRAM_BB_ALS_START +((addr-SRAM_BB_RGN_START)<<5)+(bit<<2))

#define LED_IODIR (*(volatile uint32_t*)SRAM_BBRGN2BBALS(LED_IODIR_ADDR,LED))
#define LED_IOSET (*(volatile uint32_t*)SRAM_BBRGN2BBALS(LED_IOSET_ADDR,LED))
#define LED_IOCLR (*(volatile uint32_t*)SRAM_BBRGN2BBALS(LED_IOCLR_ADDR,LED))

void led_int(void);
void led_on(void);
void led_off(void);
void led_blink(uint32_t delay_ms);

#endif
