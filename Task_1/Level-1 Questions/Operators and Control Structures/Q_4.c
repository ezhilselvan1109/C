//Program to check the two given numbers are same or equal without using any comparison operator.

#include<stdio.h>

void areSame(int x, int y)
{
    if (x-y)
        printf("Not Same");
    else
        printf("Same");
}

int main()
{
    int x=10,y;
    printf("Enter the y number:");
    scanf("%d",&y);
    areSame(x, y);
}
