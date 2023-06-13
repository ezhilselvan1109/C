//Write a program in C to print all permutations of a given string using pointers.

#include <stdio.h>
#include <string.h>

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r)
{
static int n=1,num=1;
int i;
if (l == r)
    printf("\nans :%s\n\n", a);
else
{
    for (i = l; i <= r; i++)
    {
        swap((a+l), (a+i));
        permute(a, l+1, r);
        swap((a+l), (a+i));
    }
}
}

int main()
{
    char str[10];
    printf("Enter the String :\n");
    scanf("%s",str);

    int len=0;
    while(str[len++]);
    len-=1;
    printf("Ans:\n");
    permute(str, 0, len-1);
    return 0;
}
