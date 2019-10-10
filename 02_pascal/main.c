#include <stdio.h>
#include "pascal.h"

int main()
{
	int cnt;
	printf("Enter number of lines: ");
	scanf("%d", &cnt);
	pascal(cnt);
	return 0;	
}

/*
Compilation Commands:
	gcc -c main.c
	gcc -c fact.c
	gcc -c combn.c
	gcc -c pascal.c
	gcc -o program.out main.o fact.o combn.o pascal.o
*/
