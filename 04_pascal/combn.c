#include "fact.h"
#include "combn.h"

int combn(int n, int r)
{
	int res;
	res = fact(n) / ( fact(r) * fact(n-r) );
	return res;
}


