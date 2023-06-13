/*
Write a program to print the following pattern

                         1

                         1 2

                         1  2   3

                         1  2   3  4
*/
#include<stdio.h>

int main(){
int n,i,j;
printf("Enter the number : ");
scanf("%d",&n);
for(i=1;i<=n;i++){
    for(j=1;j<=i;j++){
        printf("%d ",j);
    }
    printf("\n");
}
}
