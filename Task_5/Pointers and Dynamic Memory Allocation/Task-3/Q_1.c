//Program to sum of two numbers using pointers.

#include<stdio.h>

int main(){
    int *first,*second,a,b;
    printf("Enter the first number : ");
    scanf("%d",&a);
    printf("Enter the second number : ");
    scanf("%d",&b);
    first=&a;
    second=&b;
    printf("\nAns :%d\n",*first+ *second);
}
