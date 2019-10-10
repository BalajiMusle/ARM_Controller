#include "LPC17xx.h"
#include "ssp.h"

int main()
{
	uint16_t data = 0x33;
	SystemInit();
	ssp_init();
	while(1)
	{
		ssp_transfer(data);
		SW_DELAY_MS(1000);
		data = ~data;
	}
}

