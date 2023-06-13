#include<stdio.h>

int main(){
    int n,i,s;
    printf("Enter the Array Size : \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Element :\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the Number for Search :\n");
    scanf("%d",&s);
    if(search(arr,s,0,n-1))
        printf("Yes");
    else
        printf("No");
}

int search(int *arr,int s,int start,int end){
    if(end>=1){
    int mid=start+end/2;
    if(s==arr[mid])
        return 1;
    if(s<arr[mid])
        return search(arr,s,start,mid-1);
    return search(arr,s,mid+1,end);
    }
    return 0;
}
