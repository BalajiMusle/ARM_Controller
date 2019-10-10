#include <stdio.h>
#include "combn.h"
#include "pascal.h"

void pascal(int cnt)
{
	int n, r, t, s;
	for(n=0; n<cnt; n++)
	{
		for(s=0; s<cnt-n-1; s++)
			printf("\t");
		for(r=0; r<=n; r++)
		{
			t = combn(n, r);
			printf("%d\t\t", t);
		}
		printf("\n");
	}
}



