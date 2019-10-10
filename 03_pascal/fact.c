#include "fact.h"

int fact(int n)
{
	int res=1;
	while(n > 0)
		res = res * n--;
	return res;
}

