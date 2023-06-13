//write a c program to calculate power using recursion

#include <stdio.h>


int power(int base, int n) {
    if (n != 0)
        return (base * power(base, n - 1));
    else
        return 1;
}
int main() {
    int base, a,n, result;
    printf("Enter the base value : ");
    scanf("%d", &base);
    printf("Enter the number : ");
    scanf("%d", &n);
    result = power(base,n);
    printf("Ans: %d", result);
    return 0;
}

