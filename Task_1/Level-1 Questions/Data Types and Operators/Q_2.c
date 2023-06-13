//Write a program in which to declare all data types like integer, double, float, long integer and print value in specified format.

#include<stdio.h>
#include<conio.h>

void main()
{
int a;
double b;
float c;
char ch;
char string[100];
long int d;
printf("Enter the integer, double, float, long integer, char, string :\n");
scanf("%d %lf %f %d %c %s",&a,&b,&c,&d,&ch,string);
printf("Ans : \na=%d \nb=%lf \nc=%f \nd=%d \nch=%c \nstring=%s",a,b,c,d,ch,string);
return;
}



