#include <stdio.h>

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}
void heap(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d", arr[i]);
        printf(" ");
    }

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
    heap(a, n);
    printf("\nAfter sorting :\n");
    print(a, n);
    return 0;
}
/*
Enter the Array Size :
5
Enter the Array Element :
8 6 4 9 7

After sorting :
4 6 7 8 9
*/
