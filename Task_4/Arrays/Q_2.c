/*

In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.
 You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.
The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.
If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
Example 1
Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]
Example 2
Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]
*/

#include<stdio.h>

int main(){
    int row1,col1,row2,col2,i,j;
    printf("Enter the array row and col size :\n");
    scanf("%d%d",&row1,&col1);
    int resize1=row1*col1;
    int arr[row1][col1];
    printf("Enter the array elements :\n");
    for(i=0;i<row1;i++){
        for(j=0;j<col1;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Enter the resize array row and col size :\n");
    scanf("%d%d",&row2,&col2);
    int resize2=row2*col2;
    if(resize1==resize2){
        printf("[");
        for(i=0;i<row2;i++){
            printf("[");
        for(j=0;j<col2;j++){
            printf("%d",arr[i][j]);
            if(j!=col2-1)
                printf(",");
        }
    printf("]");
    if(i!=row2-1)
            printf(",");
    }
    printf("]");
    }else{
        printf("[");
        for(i=0;i<row1;i++){
            printf("[");
        for(j=0;j<col1;j++){
            printf("%d",arr[i][j]);
            if(j!=col1-1)
                printf(",");
        }
    printf("]");
    if(i!=row1-1)
            printf(",");
    }
    printf("]");
    }
}
