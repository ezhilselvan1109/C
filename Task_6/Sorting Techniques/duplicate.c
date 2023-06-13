#include<stdio.h>

void quickSort(int *arr,int i,int j){
    int r=0,l=r,pivot=*(arr+j);
    while(i<j){
        i+=1;
    while(i<=r&&*(arr+i)<pivot)
        i++;
    while(j>=l&&*(arr+j)>pivot)
       j--;
    if(i<j&&i<=r)
        swap(*arr,i,j);
    }
        swap(*arr,1,j);
        quickSort(*arr,l,j-1);
        quickSort(*arr,j+1,r);
}


void printArr(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", *(arr+i));
}

void swap(int *arr,int i,int j){
    int temp=*(arr+i);
    *(arr+i)= *(arr+j);
    *(arr+j)=temp;
}
int main()
{
    int n,i;
    printf("Enter the Array Size :\n");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter the Array Elements :\n");
    for (i = 0; i < n; i++)
        scanf("%d",*(arr+i));
    quickSort(*arr, 0, n - 1);
    printf("\nAfter sorting array :\n");
    printArr(arr, n);

    return 0;
}
