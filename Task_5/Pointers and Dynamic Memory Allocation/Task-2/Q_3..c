//Access two dimensional arrays using pointers in C.

#include<stdio.h>

int main(){
    int i,j,row ,col,**arr;
    printf("Enter the row and col:\n");
    scanf("%d%d",&row,&col);
    arr=(int *)malloc(row*col*sizeof(int));
    printf("Enter the Array Element:\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
                scanf("%d",*(arr+i)+j);
        }
    }
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
        printf("%d ",*(*(arr+i)+j));
        }
        printf("\n");
    }
}
