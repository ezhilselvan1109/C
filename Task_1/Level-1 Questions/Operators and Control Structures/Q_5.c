//Program to find the output of the following expression: x + x^3/3! + x^5/5! +…….+ x^n/n!

#include<stdio.h>

int main()
{
    int x,n,ans;
    printf("\nEnter a value for x :\n");
    scanf("%d",&x);
    printf("\nEnter an odd value for n :\n");
    scanf("%d",&n);
    ans=series(x,n);
    printf("\n%d",ans);
}

int series(int s, int t)
{
    int i;
    int result=0;
    for(i=1;i<=t;i+=2)
    {
        printf("%d\t",power(s,i));
        printf("%d\t",factorial(i));
        printf("%d\n",power(s,i)/factorial(i));
        result+=(power(s,i)/factorial(i));
    }
    return result;
}

int power(int s,int i){
    int t=1,temp=1;
    while(t<=i){
       temp*=s;
       t++;
    }
    return temp;
}
int factorial(int p)
{
    int f=1;
    while(p>0)
    {
        f*=p;
        p--;
    }
    return f;
}
