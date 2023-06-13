//Find the nth bit of the given number

#include<stdio.h>
#include<stdlib.h>

int recursion(int n,int count,int bit,int temp){
    temp=n%2;
    n=n/2;
    if(count==bit){
        return temp;
    }
    count++;
    return recursion(n,count,bit,arr,temp);
}

int main(){
int n,bit,count=1,temp=0;
printf("Enter the number :");
scanf("%d",&n);
printf("Enter nth bit :");
scanf("%d",&bit);
printf("Ans :%d",recursion(n,count,bit,temp));
return;
}



