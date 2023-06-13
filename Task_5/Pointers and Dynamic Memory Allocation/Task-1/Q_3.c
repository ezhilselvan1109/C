//Manipulate an array using pointers, where find out count of the prime numbers and its position stored in that array.

#include<stdio.h>
#include<math.h>
int check_prime(int);

int main()
{
    int n,*arr,result,i,j=0,count=0;

    printf("Enter an Number :\n");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    printf("Enter an Element:\n");
    for(i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    printf("position :");
    for(i=0;i<n;i++){
        result = check_prime(*(arr+i));
        if (result == 1){
            count++;
            printf("%d ",i);
        }
    }
    printf("\nCount : %d",count);
    return 0;
}

int check_prime(int n)
{
   if (n <= 1) {
           return 0;
       }
   for (int i = 2; i <= sqrt(n); i++) {
       if (n % i == 0) {
           return 0;
       }
   }
    return 1;
}
