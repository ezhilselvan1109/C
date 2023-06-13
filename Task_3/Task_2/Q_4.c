//Create a structure called Date and calculate the difference between the two dates.
#include<stdio.h>
struct Date
{
	int day, mon, yr;
};
int leapyear(struct Date d);
int checkdate(struct Date d);
int differ(struct Date dt1,struct Date dt2);
const int md[12]= { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main()
{
	struct Date dt1,dt2;
	int valid,valid1,flag;
	printf("Enter the 1st date as day,month & year: \n");
	scanf("%d%d%d",&dt1.day,&dt1.mon,&dt1.yr);
	printf("Enter the 2nd date as day,month & year: \n");
	scanf("%d%d%d",&dt2.day,&dt2.mon,&dt2.yr);
    printf("The difference between two dates is %d",differ(dt1,dt2));
	return 0;
}

int differ(struct Date dt1,struct Date dt2)
{
	long int n1 = dt1.yr * 365 + dt1.day;
	for (int i = 0; i < dt1.mon - 1; i++)
	{
		n1 =n1+ md[i];
    }
    n1 = n1+leapyear(dt1);

	long int n2 = dt2.yr * 365 + dt2.day;
	for (int i = 0; i < dt2.mon - 1; i++)
	{
		n2 =n2+ md[i];
	}
	n2 = n2+leapyear(dt2);
	return (n2 - n1);
}


int leapyear(struct Date d)
{
	int years = d.yr;
	if(years%4==0)
	{
		return 1;
	}
	else
	{
	    return 0;
	}
}
