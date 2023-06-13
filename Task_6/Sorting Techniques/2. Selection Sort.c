/*
2. Selection Sort
*/
#include<stdio.h>

int main(){
    int n,i,j,k,temp,p=1;
    printf("Enter the Array Size : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Array Element : ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int small;
    for (i = 0; i < n-1; i++)
    {
        small = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[small])
            small = j;
        int temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;
    }
    printf("Ans :  ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

}
