#include <stdio.h>

void merge(int a[], int begin, int mid, int end)
{
    int i, j, k;
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    int Leftside[n1], Rightside[n2];
    for (int i = 0; i < n1; i++)
    Leftside[i] = a[begin + i];
    for (int j = 0; j < n2; j++)
    Rightside[j] = a[mid + 1 + j];
    i = 0;
    j = 0;
    k = begin;
    while (i < n1 && j < n2)
    {
        if(Leftside[i] <= Rightside[j])
        {
            a[k] = Leftside[i];
            i++;
        }
        else
        {
            a[k] = Rightside[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        a[k] = Leftside[i];
        i++;
        k++;
    }

    while (j<n2)
    {
        a[k] = Rightside[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        mergeSort(a, begin, mid);
        mergeSort(a, mid + 1, end);
        merge(a, begin, mid, end);
    }
}

void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the Array Size :\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the Array Element :\n");
    for(int i=0;i < n; ++i)
        scanf("%d",&a[i]);
    printf("Before sorting :\n");
    printArray(a, n);
    mergeSort(a, 0, n - 1);
    printf("After sorting :\n");
    printArray(a, n);
    return 0;
}
