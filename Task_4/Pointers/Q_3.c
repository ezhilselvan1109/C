/*
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
Return any array that satisfies this condition.
Example 1:
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
Example 2:
Input: nums = [0]
Output: [0]

*/

#include<stdio.h>

int main(){
    int i,j=0,n;
    printf("Enter the array size :\n");
    scanf("%d",&n);
    int *arr1=(int *)malloc(n*sizeof(int));
    int *arr2=(int *)malloc(n*sizeof(int));
    printf("Enter the array element :\n");
    for(i=0;i<n;i++){
        scanf("%d",arr1+i);
    }
    for(i=0;i<n;i++){
        if((*(arr1+i))%2==0){
            *(arr2+j) = *(arr1+i);
        j++;
        }
    }
    for(i=0;i<n;i++){
        if((*(arr1+i))%2!=0){
            *(arr2+j)=*(arr1+i);
        j++;
        }
    }
    printf("Ans :\n");
    for(i=0;i<n;i++){
        printf("%d ",*(arr2+i));
    }
    free(arr1);
    free(arr2);
}
