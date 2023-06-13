//C program to check whether a file or directory exists or not
#include<stdio.h>

int main(){
    FILE *file;
    char filename[15];
    printf("Enter the FileName :\n");
    scanf("%s",filename);
    strcat(filename,".txt");
    file=fopen(filename,"r");
    if(file){
        printf("exits");
    }else{
        printf("That n't exits");
    }
}
