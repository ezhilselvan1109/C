//C program to input and print array elements using pointers.

#include<stdio.h>

int main(){
    int n,i;
    printf("Enter the Array size :\n");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter the Array Element :\n");
    for(i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    printf("Ans :\n");
    for(i=0;i<n;i++){
        printf("%d ",*(arr+i));
    }
}
