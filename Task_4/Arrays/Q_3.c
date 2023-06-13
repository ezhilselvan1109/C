/*

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:
Input: nums = [1]
Output: [[1]]
*/


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
int i;
if (l == r)
    printf("Ans :%s\n\n", a);
else
{
    for (i = l; i <= r; i++)
    {
        swap((a+l), (a+i));
        printf("First %s\n",a);
        permute(a, l+1, r);
        printf("Second %s\n",a);
        swap((a+l), (a+i));
        printf("Third %s\n",a);
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
    printf("\nLength %d",len);
    printf("Ans:\n");
    permute(str, 0, len-1);
    return 0;
}
