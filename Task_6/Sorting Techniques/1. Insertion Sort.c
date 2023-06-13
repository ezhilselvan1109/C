//1. Insertion Sort

#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int i,b,temp;
    for(i=1;i<n;i++) {
        j=i;
        while(j>0 && arr[j]<arr[j-1]) {
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
}

int main()
{
    int n,i;
    printf("Enter the Array Size :\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array Element :\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertionSort(arr, n);
    printf("Ans : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

