//Add three values without using addition operator(+)
#include<stdio.h>

int main(){
    int a,b,c;
    printf("Enter the three number: ");
    scanf("%d%d%d",&a,&b,&c);
    printf("Ans: %d",-(-a-b-c));
}
