//Create a Sparse matrix and find out the locations where 1's are there.

#include<stdio.h>

int main(){
    int row=3,col=3,i,j;
    printf("Enter the row and col :\n");
    scanf("%d %d",&row,&col);
    int arr[row][col];
    printf("Enter the array element :\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(arr[i][j]==1)
                printf("row=%d col=%d\n",i,j);
        }
    }
}
