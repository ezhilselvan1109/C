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
    if(search(arr,s,n))
        printf("Yes");
    else
        printf("No");
}
int search(int *arr,int s,int n){
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==s)
            return 1;
    }
    return 0;
}
