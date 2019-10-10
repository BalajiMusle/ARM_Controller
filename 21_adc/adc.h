#ifndef __ADC_H
#define __ADC_H

#include "LPC17xx.h"

// ADC Power Config
#define PCADC	12
// ADCR bits
#define CR_SEL		0
#define CR_CLKDIV	8
#define CR_PDN		21
#define CR_START	24
// ADGDR bits
#define DR_RESULT	4
#define DR_SEL		24
#define DR_DONE		31
// values
#define ADC_CLKDIV_VAL	(2-1)
#define ADC_CHN		2

void adc_init(void);
uint16_t adc_read(void);

#endif
