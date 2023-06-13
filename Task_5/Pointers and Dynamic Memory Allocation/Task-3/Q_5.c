//To search an element in array using function pointers.

#include <stdio.h>

int search_an_element(int *arr,int n,int s)
{
    for(int i=0;i<n;i++){
        if(*(arr+i)==s){
            return 1;
            break;
        }
    }
    return 0;
}

int main()
{
    int n,i,s;
    printf("Enter the Array size :\n");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter the Array Element :\n");
    for(i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    printf("Enter the Element :\n");
    scanf("%d",&s);
    int (*fun)(int,int,int)=search_an_element;
    printf("\nAns : ");
    int flag=fun(arr,n,s);
    if(flag)
        printf("Yes");
    else
        printf("No");
    return 0;
}


