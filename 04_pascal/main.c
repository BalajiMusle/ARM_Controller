#include <stdio.h>
#include "pascal.h"

#ifndef CNT
	#define CNT 4
#endif

int main()
{
	int cnt=CNT;
	pascal(cnt);
	return 0;	
}

