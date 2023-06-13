//Program to clear the specified bit of a number.
#include <stdio.h>

int main()
{
    int n = 5, k;
    printf("Enter the number :\n");
    scanf("%d",&n);
    printf("Enter the specified bit of a number :");
    scanf("%d",&k);
    printf("%d",n & (~(1 << (k - 1))));
}
