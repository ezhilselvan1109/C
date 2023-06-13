//C program to rename a file using rename() function

#include<stdio.h>

int main(){
    char *oldfileName="Q_110.c";
    char *newfileName="part2_Q_1.c";
    int flag=rename(oldfileName,newfileName);
    if(!flag){
        printf("File Name Changed Sucessfully");
    }else{
        printf("Failed");
    }
}
