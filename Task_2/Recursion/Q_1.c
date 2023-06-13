//Write a program to find factorial of a number using recursion

#include<stdio.h>
long int multiplyNumbers(int n);
int main() {
    int n;
    printf("Enter the number :");
    scanf("%d",&n);
    printf("Ans: %ld", multiplyNumbers(n));
}

long int multiplyNumbers(int n) {
    if (n>=1)
        return n*multiplyNumbers(n-1);
    else
        return 1;
}
