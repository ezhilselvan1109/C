//Write a program by using Bitwise operators (left and right shift).

#include<stdio.h>
int main()
{
    int left,right;
    printf("Enter the left and right number :\n");
    scanf("%d%d",&left,&right);
    printf("%d << %d = %d\n", left,right,left<<right);
    printf("%d >> %d = %d\n", left,right,left>>right);
    return;
}
