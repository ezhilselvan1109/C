//C program to count 1s in a number (get input from user)

#include<stdio.h>
#include<stdlib.h>
int main(){
int n,temp,count=0;
printf("Enter the number: ");
scanf("%d",&n);
printf("Ans: %d",recursion(n,count));
return;
}

int recursion(int n,int count){
    if(n<=0)
        return count;
    int temp=n%2;
    if(temp==1)
    count++;
    n=n/2;
    return recursion(n,count);
}

