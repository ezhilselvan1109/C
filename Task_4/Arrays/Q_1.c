/*
 Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 A subarray is a contiguous part of an array.
 Example 1:
 Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 Output: 6
 Explanation: [4,-1,2,1] has the largest sum = 6.
 Example 2:
 Input: nums = [1]
 Output: 1
 Example 3:
 Input: nums = [5,4,-1,7,8]
 Output: 23
 */

#include<stdio.h>

int maxSubArraySum(int arr[], int size){
    int max=arr[0],current= arr[0];
    for (int i = 1; i < size; i++)
    {
        int value=arr[i];
        current= maxmum(value, current+value);
        max = maxmum(max, current);
    }
    return max;
}
int maxmum(int first,int second){
    int ans;
    if(first<second){
        ans=second;
    }else{
        ans=first;
    }
    return ans;
}
void main(){
    int n,i;
    printf("Enter the lenth of array :\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the element of array :\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int maxmum_sum = maxSubArraySum(arr, n);
    printf("Maximum contiguous sum is : %d"
                       , maxmum_sum);
}

