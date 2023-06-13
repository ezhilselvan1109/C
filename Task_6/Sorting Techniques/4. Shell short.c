//4. Shell short

#include <stdio.h>

int shell(int a[], int n)
{
    for (int interval = n/2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < n; i += 1)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
                a[j] = a[j - interval];
            a[j] = temp;
        }
    }
    return 0;
}
void printArr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
int main()
{
    int n,i;
    printf("Enter the Array Size :");
    scanf("%d",&n);
    int a[n];
    printf("Enter the Array Element :");
    for (i = 0; i < n; i++)
        scanf("%d ", &a[i]);
    shell(a, n);
    printf("\nAns :\n");
    printArr(a, n);
    return 0;
}
