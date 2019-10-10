#include<stdio.h>
typedef struct date
{
	int dd,mm,yyyy;
}DATE;
int main()
{
	DATE d1;
	int arr[12]={31,28,31,30,31,30,31,31,30,31,30,31},no;

	printf("Please enter the date as dd/mm/yyyy this format::\n");
	scanf("%d%*c%d%*c%d",&d1.dd,&d1.mm,&d1.yyyy);
	//printf("%d/%d/%d\n",d1.dd,d1.mm,d1.yyyy);

	if(d1.yyyy%4==0)
	{
		arr[1]=29;
	}
	if(d1.dd>arr[d1.mm-1] || d1.mm>12)
	{
		printf("Invalid date...\n");
	}
	else
	{
		printf("Please enter the no of days u want to add::\n");
		scanf("%d",&no);
		while(no>0)
		{
			while(d1.dd<=arr[d1.mm-1] && no>0)
			{
				d1.dd++;
				no--;
			}
			if((no>0 || (d1.dd==arr[d1.mm-1]+1)) && d1.mm<13)
			{
				d1.mm++;
				d1.dd=1;
			}
			if(d1.mm==13)
			{
				d1.yyyy++;
				d1.mm=1;
				d1.dd=1;
			}

		}
		printf("New date is....\n");
		printf("%d/%d/%d\n",d1.dd,d1.mm,d1.yyyy);
	}
	return 0;
}
