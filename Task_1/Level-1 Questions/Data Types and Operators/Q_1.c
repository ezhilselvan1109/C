//Write a program to calculate Simple Interest.

#include<stdio.h>

int main()
    {
        int Principal_Amount , Rate_per_Annum , year , simple_interest;
        printf("Enter the Principal Amount : ");
        scanf("%d",&Principal_Amount);
        printf("Enter the Rate per Annum : ");
        scanf("%d",&Rate_per_Annum);
        printf("Enter the no of year : ");
        scanf("%d",&year);
        simple_interest= (Principal_Amount*Rate_per_Annum*year)/100;
        printf("Ans : %d", simple_interest);
        return;
    }
