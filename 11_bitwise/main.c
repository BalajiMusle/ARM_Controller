#include <stdio.h>

int main()
{
	int num1=10, num2=20;
	printf("before swap : num1=%d, num2=%d\n", num1, num2);
	num1 ^= num2;
	num2 ^= num1;
	num1 ^= num2;
	printf("after swap : num1=%d, num2=%d\n", num1, num2);
	return 0;	
}





