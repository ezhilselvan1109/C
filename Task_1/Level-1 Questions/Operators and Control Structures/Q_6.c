 /*Write a C program to which reads n digits chosen from 0 to 9 and counts the number of combinations where the sum of the digits equals to given number. Do not use the same digits in a combination.

For example, the combinations where n = 2 and s = 5 are as follows:

0 + 5 = 5

1 + 4 = 5

3 + 2 = 5
*/

#include <stdio.h>
int main()
{
        int  n,s,count=0;
        printf("Enter the number:\n");
		scanf("%d", &n);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i+j==n){
                    count++;
                }
            }
        }
        if(n%2==0)
            printf("%d",count/2+1);
        else
            printf("%d",count/2);
	return 0;
}



