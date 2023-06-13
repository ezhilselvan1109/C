//Write a program to illustrate padding in structure with an example.
#include <stdio.h>

struct Student
{
    double Id;
    char Name[15];
    float Salary;
}s;
int main()
{
    printf("\nThe size of the Structure is %d",sizeof(s));
    return 0;
}
