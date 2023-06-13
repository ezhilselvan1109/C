//Write a C program which reads an integer n and prints a twin prime which has the maximum size among twin primes less than or equals to n.

//According to wikipedia "A twin prime is a prime number that is either 2 less or 2

//more than another prime number" for example, either member of the twin prime

//pair (41, 43). In other words, a twin prime is a prime that has a prime gap of two".

#include <stdio.h>

void printTwinPrime(int n)
{
	int  prime[n],p,i;
	for(p=2;p<=n;p++){
        prime[p]=1;
	}
	for (p = 2; p * p <= n; p++) {
		if (prime[p] == 1) {
			for (i = p * 2; i <= n; i += p)
				prime[i] = 0;
		}
	}
	for (p = 2; p <= n - 2; p++)
		if (prime[p] && prime[p + 2])
			 printf("(%d,%d) ",p,p+2);
}

int main()
{
	int n;
	printf("Enter the number :\n");
	scanf("%d",&n);
	printTwinPrime(n);
	return 0;
}
