//Write a program in C to show the usage of pointer to the structure.

#include <stdio.h>
struct EmpAddress
{
char *Name;
char destination[20];
char id[10];
}
employee={"Ezhil Selvan","QA","INC3077"},*pt=&employee;

int main()
{
 	printf("Name : %s \nDestination : %s \nId : %s",pt->Name,(*pt).destination,pt->id);
	return 0;
}
