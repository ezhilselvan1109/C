//Reverse a numbers using a recursion
#include<Stdio.h>

int main(){
    int n,sum=0;
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("Ans: %d",recursion(n,sum));
}

int recursion(int n,int sum){
    if(n<=0)
        return sum;
    sum=sum*10+n%10;
    return recursion(n/10,sum);
}

