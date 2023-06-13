//Build the basic management application by your own choice using functions.
#include<stdio.h>
static int n;
int main()
{
	int i;
	printf("How many employee are there");
	scanf("%d",&n);
	printf("Enter employee details: ");
	input(n);
	printf("\nRNo\tName\tSalary");
	display(n);

}
struct employee
{
	int id;
	char ename[15];
	int salary;
}s[100];

void input();
void display();

void input(int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nEnter the employee detail %d Id, Name & Salary: ",i+1);
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
