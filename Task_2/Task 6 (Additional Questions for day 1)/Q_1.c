//Recursion to print Fibonacci series up to 20.
#include<stdio.h>

int main(){
    int start=0,second=1,end=20;
    printf("%d %d ",start,second);
    fib(start,second,end);
}
void fib(int start,int second,int end){
    int count=start+second;
    start=second;
    second=count;
    if(count<=end){
    printf("%d ",count);
        return fib(start,second,end);
    }
    else
        return;
}
