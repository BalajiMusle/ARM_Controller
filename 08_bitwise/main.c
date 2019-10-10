#include <stdio.h>

int main()
{
	int num;
	printf("enter a number : ");
	scanf("%d", &num);
	/*
	printf("%d\n", num);
	while(num != 1)
	{
		if(num % 2 != 0)
			num = num * 3 + 1;
		else
			num = num / 2;
		printf("%d\n", num);
	}
	*/
	printf("%d\n", num);
	while(num ^ 1)
	{
		if(num & 1)
			num = (num << 1) + num + 1;
		else
			num = num >> 1;
		printf("%d\n", num);
	}
	return 0;	
}
