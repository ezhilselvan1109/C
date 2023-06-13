//Write a program to convert decimal to binary

#include<stdio.h>
#include<stdlib.h>
int main(){
int arr[100],n,i,sum=0;
printf("Enter the decimal number : ");
scanf("%d",&n);
while(n>0)
{
sum=10*sum+n%2;
n=n/2;
}
printf("Ans : %d",sum);

return;
}

