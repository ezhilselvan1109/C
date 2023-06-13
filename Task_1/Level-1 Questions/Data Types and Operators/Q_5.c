//Write a program for increment (pre and post) and decrement (pre and post) operators.

#include <stdio.h>
#include <conio.h>
int main ()
{

int num1,num2;
printf("Enter the two numbers :\n");
scanf("%d%d",&num1,&num2);
printf ("the pre-increment operator :\n" );
printf ("%d\n", ++num1);
printf ("the post-increment operator :\n" );
printf ("%d\n", num1++);
printf ("%d\n", num1++);
printf ("the pre-decrement operator :\n" );
printf ("%d\n", --num2);
printf ("the post-decrement operator :\n" );
printf ("%d\n", num2--);
printf ("%d\n", num2--);
return 0;
}
