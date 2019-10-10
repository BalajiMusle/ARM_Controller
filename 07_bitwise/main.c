#include <stdio.h>

int main()
{
	int res, num = 27;
	unsigned int unum;
	
	if(num & 1)
		printf("Odd Number...\n");
	else
		printf("Even Number...\n");
		
	if(num & 3)
		printf("Not Divisible by 4...\n");
	else
		printf("Divisible by 4...\n");

	res = num - (num & 3);
	printf("Lower multiple of 4 = %d\n", res);
	
	res = num & ~3;
	printf("Lower multiple of 4 = %d\n", res);
	
	num = 27;
	res = num << 2;
	printf("%d * 4 = %d\n", num, res);
	
	num = -27;
	res = num << 2;
	printf("%d * 4 = %d\n", num, res);
	
	
	num = 26;
	res = num >> 1;
	printf("%d / 2 = %d\n", num, res);
	
	num = -26;
	res = num >> 1;
	printf("%d / 2 = %d\n", num, res);

	unum = -27;	
	res = unum >> 1;
	printf("(%d) %u >> 1 = %u\n", unum, unum, res);
	
	num = -5;
	//res = -num;	
	res = ~(num - 1);
	printf("num = %d, res = %d\n", num, res);
	return 0;	
}
