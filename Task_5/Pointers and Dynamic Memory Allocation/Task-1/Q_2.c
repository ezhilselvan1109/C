/*
Program to allocate memory for 10 integers and reallocate the same memory for 15 integers and
store some integer data(may be positive or negative) and find the odd numbers and its position or index.
*/

#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i;
    int *arr=(int *)malloc(10*sizeof(int));
    printf("Enter the Array Element :\n");
    for(i=0;i<10;i++){
        scanf("%d",arr+i);
    }
    printf("Malloc Array Element :\n");
    for(i=0;i<10;i++){
        printf("%d ",*(arr+i));
    }
    printf("\n");
    arr=(int*)realloc(arr,15);
    printf("Enter the Array Element :\n");
    for(i=0;i<15;i++){
        scanf("%d",arr+i);
    }
    printf("Realloc Array Element :\n");
    for(i=0;i<15;i++){
        printf("%d ",*(arr+i));
    }
    printf("\n");
    for(i=0;i<15;i++){
        if((arr[i])%2!=0){
            printf("Number :%d Position :%d\n",*(arr+i),i);
        }
    }
    free(arr);
}
