#include <stdio.h>

#define BV(n) (1<<(n))

int main()
{
	short num = 9;
	int i;
	for(i=sizeof(num)*8-1; i>=0; i--)
	{
		if(num & BV(i))
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	return 0;	
}





