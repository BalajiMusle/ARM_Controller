#include "adc.h"

void adc_init(void)
{
   // power on adc
   LPC_SC->PCONP |= BV(PCADC);
   // pinsel adc P0.2 (AD0.2)
   LPC_PINCON->PINSEL1 &= ~(BV(19)|BV(18));
   LPC_PINCON->PINSEL1 |= BV(18);   
   // init CR: channel, clkdiv, pdn bit
   LPC_ADC->ADCR = BV(ADC_CHN) | (ADC_CLKDIV_VAL << CR_CLKDIV) | BV(CR_PDN);
}

uint16_t adc_read(void)
{
   uint32_t res;
   // start conv
   LPC_ADC->ADCR |= BV(CR_START);
   // wait for result (while done==0)
   do {
       res = LPC_ADC->ADGDR;
   }while((res & BV(DR_DONE))==0);
   // read result & return
   res = res >> DR_RESULT;
   return (res & 0x0FFF);
}

