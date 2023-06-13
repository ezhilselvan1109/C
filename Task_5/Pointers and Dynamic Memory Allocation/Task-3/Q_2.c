//Program to find the maximum of two numbers using function pointers.


#include <stdio.h>
int maximum(int x,int y)
{
    int max;
    if(x<y){
        max=y;
    }else{
        max=x;
    }
    return max;
}

int main()
{
    int first,second;
    printf("Enter the first number :\n");
    scanf("%d",&first);
    printf("Enter the second number :\n");
    scanf("%d",&second);
    int (*fun)(int,int)=maximum;
    printf("\nAns : %d",fun(first,second));
    return 0;
}


