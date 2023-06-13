//Create an adjacency matrix, where '1' represents the edges of a graph from i -> j, also use i != j  as a constraint and find the number of incoming and out going edges of each vertex.

#include<stdio.h>

int main(){
    int row=3,col=3,i,j;
    printf("Enter row and col");
    scanf("%d %d",&row,&col);
    int arr[row][col];
    printf("Enter the element");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<row;i++){
        int count=0;
        for(j=0;j<col;j++){
            if(arr[i][j]==1)
                count++;
        }

        printf("Row: %d Count: %d\n",i+1,count);
    }
}
