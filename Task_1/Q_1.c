// Find the nth bit of a given number.
#include <stdio.h>

int main()
{
    int n , k ;
    printf("Enter the number : ");
    scanf("%d",&n);
    printf("Enter the nth bit number : ");
    scanf("%d",&k);
    printf("Ans: %d",(n>>k-1)&1);
    return 0;
}
