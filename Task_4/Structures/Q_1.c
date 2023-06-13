/*
Write a structure to store the names, salary and hours of work per day of 10 employees in a company. Write a program to increase the salary depending on the number of hours of work per day as follows and then print the name of all the employees along with their final salaries.
Hours of work per day	8	10	>=12
Increase in salary	$50	$100	$150
*/
#include<stdio.h>

struct company{
    char name[15];
    int salary;
    int hours;
}employee[10];

static int n;
int main()
{
	int i;
	printf("No of Employees :\n");
	scanf("%d",&n);
	printf("Enter employee details: \n");
	input(n);
	printf("Basic Salary :100 \n");
	for(i=0;i<n;i++){
        int hour=employee[i].hours;
        employee[i].salary=calculate_salary(hour);
	}
	printf("\nName\tHours\tSalary");
	display(n);

}

void input();
void display();

void input(int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nEnter the employee detail %d Name and Hours: \n",i+1);
		scanf("%s %d",&employee[i].name,&employee[i].hours);
	}

}

int calculate_salary(int h){
    int ans=0;
    if(8<h && h<10){
        ans=100+50;
    }else if(10<=h && h<12){
        ans=100+100;
    }else if(h>=12){
        ans=100+150;
    }else if(h<=8){
        ans=100;
    }
    return ans;
}
void display(int n)
{
	for(int i=0;i<n;i++)
    {
	  printf("\n%s\t%d\t%d",employee[i].name,employee[i].hours,employee[i].salary);
	}
}
