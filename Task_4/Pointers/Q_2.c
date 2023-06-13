/*

Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.length and answer[i] is the distance from index i to the closest occurrence of character c in s.
The distance between two indices i and j is abs(i - j), where abs is the absolute value function.
Example 1:
Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
Explanation: The character 'e' appears at indices 3, 5, 6, and 11 (0-indexed).
The closest occurrence of 'e' for index 0 is at index 3, so the distance is abs(0 - 3) = 3.
The closest occurrence of 'e' for index 1 is at index 3, so the distance is abs(1 - 3) = 2.
For index 4, there is a tie between the 'e' at index 3 and the 'e' at index 5, but the distance is still the same: abs(4 - 3) == abs(4 - 5) = 1.
The closest occurrence of 'e' for index 8 is at index 6, so the distance is abs(8 - 6) = 2.

*/

#include<stdio.h>
#include<stdlib.h>
int checkDistance1(int*,int,int,char,char*,int );
int checkDistance2(int*,int,int,char,char*,int );
int checkMin(int *,int *,int);
int main(){
    char *charater,ch;
    printf("Enter the string :");
    scanf("%s",charater);
    printf("Enter the ch :");
    scanf(" %c",&ch);
    int i=0,len=0;
    while(charater[len++]!='\0'){
    }
    len-=1;
    int *arr1=(int *)malloc(len*sizeof(int));
    int *arr2=(int *)malloc(len*sizeof(int));
    checkDistance1(arr1,0,len-1,ch,charater,len);
    for(i=0;i<len;i++){
        printf("%d ",*(arr1+i));
    }
    printf("\n");
    checkDistance2(arr2,len-1,0,ch,charater,len);
    checkMin(arr1,arr2,len);
    printf("\nAns :\n");
    for(i=0;i<len;i++){
        printf("%d ",*(arr1+i));
    }
}

int checkDistance2(int *arr2,int start,int end,char ch,char *charater,int len){
    int i;
    int count=len;
    for(i=start;i>=end;i--)
    {
        if(charater[i]==ch){
            count=0;
        }
        *(arr2+i)=count++;

    }
}
int checkDistance1(int *arr1,int start,int end,char ch,char *charater,int len){
    int i;
    int count=len;
    for(i=start;i<=end;i++)
    {
        if(charater[i]==ch){
            count=0;
        }
        *(arr1+i)=count++;

    }
}

int checkMin(int *arr1,int *arr2,int len){
    int min,j=0;
    for(int i=0;i<len;i++){
        if(*(arr1+i)<= *(arr2+i)){
            *(arr1+j)=*(arr1+i);
        }else{
            *(arr1+j)=*(arr2+i);
        }
        j++;
    }
}
