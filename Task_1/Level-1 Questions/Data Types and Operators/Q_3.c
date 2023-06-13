//Compare two numbers by using ternary operator.

#include <stdio.h>
int main()
{
        int first, second;
        printf("Enter the first ans second number :\n");
        scanf("%d%d",&first,&second);
        printf("Ans : ");
        first==second ? printf("Equal") : printf("Not Equal") ;
}
