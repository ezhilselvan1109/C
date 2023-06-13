//Find the maximum of 'n' numbers.
#include <stdio.h>

int main() {
int i,max,N,x;
	printf("Enter N : ");
	scanf("%d",&N);
	max=0;
	for(i=1;i<=N;i++)
	{
		printf("Enter %d value : ",i);
		scanf("%d",&x);

		if(max < x)
			max = x;
	}
	printf("\nMax = %d",max);
	return 0;
}
