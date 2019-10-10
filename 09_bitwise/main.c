#include <stdio.h>

#define BV(n) (1<<(n))

int main()
{
	int num = 23;

	// check 4'th bit of num.
	//if(num & 0x10)	
	//if(num & (1<<4))
	if(num & BV(4))
		printf("ON\n");
	else
		printf("OFF\n");

	// clear 4'th bit of num;
	//num = num & ~BV(4);
	num &= ~BV(4);

	// set 4'th bit of num;
	//num = num | BV(4);
	num |= BV(4);
	
	// toggle 4'th bit of num;
	//num = num ^ BV(4);	
	num ^= BV(4);

	// find lower multiple of 4
	//num &= ~3;
	num &= ~(BV(1)|BV(0));
	return 0;	
}





