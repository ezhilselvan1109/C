//Check whether x=10 and y=?(user input) are same w/o using comparison operator.

#include<stdio.h>

int main()
{
    int x=10,y;
    printf("Enter the y number : ");
    scanf("%d",&y);
    printf("Ans: ");
    if (x-y)
        printf("Not Same");
    else
        printf("Same");
}
