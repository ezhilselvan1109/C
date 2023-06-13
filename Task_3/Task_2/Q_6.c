//Write a c program to read and print an employee’s details like name, employee id, salary using structure.
#include<stdio.h>

struct employee{
    char name[100];
    int id;
    float salary;
}details;

int main(){
    printf("Enter The Employee Details") ;
    scanf("%s %d %f",&details.name,&details.id,&details.salary);
    printf("Employee Name: %s\nId: %d\nSalary: %.2f",details.name,details.id,details.salary);
}
