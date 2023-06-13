// 5. Bubble sort

#include<stdio.h>

int main(){
    int n,i,j,k,temp;
    printf("Enter the Array Size : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Array Element : ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }
    }
    printf("Ans : ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

}
