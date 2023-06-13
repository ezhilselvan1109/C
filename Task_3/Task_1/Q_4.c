//Write a program to illustrate packing in structure with an example.
#include <stdio.h>
#pragma pack(1)
struct Student
{
    int Id;
    char Name[15];
    float Salary;
}s;
int main()
{
    printf("\nThe size of the Structure is %d",sizeof(s));
    return 0;
}
