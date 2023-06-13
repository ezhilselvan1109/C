/*

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:
Input: nums = [0]
Output: [0]

*/

#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,j=0;
    printf("Enter the array size :\n");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter the array element :\n");
    for (i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    for(i=0;i<n;i++){
        if(*(arr+i)!=0)
            *(arr+j)=*(arr+i);
        j++;
    }
    for(i=j;i<n;i++){
        *(arr+i)=0;
    }
    printf("Ans :\n");
    for(i=0;i<n;i++){
        printf("%d ",*(arr+i));
    }
    free(arr);
}
