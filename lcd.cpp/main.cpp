#include "LPC17xx.h"
#include "lcd.h"

int main()
{
	int i;
	lcd lcd1;
	for (i=0;i<15;i++)
	{
		lcd1.shift_display();
	lcd1.write_line1("balaji");
	lcd1.write_line2("musle");
	SW_DELAY_MS(2000);
	}
	 
	 return 0;
}


