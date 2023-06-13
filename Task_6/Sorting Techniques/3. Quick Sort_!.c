#include<stdio.h>

int swap(int *a,int *b){
        int temp=*a;
        *a=*b;
        *b=temp;
}

void printArr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
int Partition(int *a,int lb,int ub){
        int Pivot=a[lb];
        int start=lb;
        int end=ub;
        while(start<end){
            while(a[start]<=Pivot){
                start++;
                }
            while(a[end]>Pivot){
                end--;
                }
            if(start<end){
                swap(&a[start],&a[end]);
            }
        }
        swap(&a[lb],&a[end]);
        return end;
}

int quickSort(int a,int lb,int ub){
    if(lb<ub){
        int loc=Partition(a,lb,ub);
        quickSort(a,lb,loc-1);
        quickSort(a,loc+1,ub);
    }
}

int main()
{
    int n,i;
    printf("Enter the Array Size :\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the Array Elements :\n");
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
    quickSort(a, 0, n - 1);
    printf("\nAfter sorting array :\n");
    printArr(a, n);
    return 0;
}
