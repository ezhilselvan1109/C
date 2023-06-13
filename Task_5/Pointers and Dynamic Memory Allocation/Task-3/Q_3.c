//Swap two numbers using function pointers.

#include <stdio.h>

void Swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int main()
{
    int x,y;
    printf("Enter the X value :\n");
    scanf("%d",&x);
    printf("Enter the Y value :\n");
    scanf("%d",&y);
    void (*fun)(int,int)=Swap;
    fun(&x,&y);
    printf("\nAns : \n");
    printf("X = %d\nY = %d",x,y);
    return 0;
}


