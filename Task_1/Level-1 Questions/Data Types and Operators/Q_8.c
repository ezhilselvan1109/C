//Write a C program to show the use of static variable.

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the non static number : ");
    scanf("%d",&n);
    print(n);
    print(n);
    print(n);
    print(n);
    return;
}
int print(int n)
{
    static int num;
    printf("%d %d\n",num++,n++);
}
