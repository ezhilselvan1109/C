//Write a program in C to use a pointer to the union data type.


#include <stdio.h>
union EmpAddress
{
char *Name;
char destination[20];
char id[10];
}
employee,*pt=&employee;

int main()
{
    pt->Name="Ezhil Selvan";
 	printf("Name : %s \n",pt->Name);
 	(*pt).destination="QA";
 	printf("Destination : %s \n",(*pt).destination);
 	pt->id="INC3077";
 	printf("Id : %s",pt->id);
	return 0;
}
