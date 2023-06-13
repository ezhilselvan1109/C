//(L2)Write a program to swapping of two numbers using call by value and call by address.

//call by value
#include <stdio.h>

void swap(int x, int y) {
   int temp;
   temp = x;
   x = y;
   y = temp;
}
int main () {
   int a;
   int b;
   printf("Enter the two values : ");
   scanf("%d %d",&a,&b);
   swap(a, b);
   printf("After swap, value of a : %d\n", a );
   printf("After swap, value of b : %d\n", b );
   return 0;
}
