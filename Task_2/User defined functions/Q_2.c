//Build the basic management application by your own choice using functions.
#include<stdio.h>
struct employee
{
	int id;
	char ename[15];
	int salary;
}s[100];

int main()
{
	int i, n;
	printf("How many employee are there:\n");
	scanf("%d",&n);
	printf("Enter employee details: \n");
	input(n);
	printf("\nNo\tName\tSalary");
	display(n);

}

void input(int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Enter the employee detail %d Id, Name & Salary: \n",i+1);
		scanf("%d %s %d",&s[i].id,&s[i].ename,&s[i].salary);
	}

}

void display(int n)
{
	for(int i=0;i<n;i++)
    {
	  printf("\n%d\t%s\t%d",s[i].id,s[i].ename,s[i].salary);
	}
}
