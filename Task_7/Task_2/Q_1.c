//Program to copy the data and add '3' to data at even location and display them.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *file;
    file=fopen("file.txt","w");
    char name[10];
    printf("Enter the string :");
    scanf("%s",name);
    int len=strlen(name),i;
    for(i=0;i<len;i++){
        fputc(name[i],file);
    }
    fclose(file);
    char ch;
    i=0;
    printf("Ans : ");
    file=fopen("file.txt","r");
    while((ch=fgetc(file))!=EOF){
        if(i%2==0)
            printf("%c",ch+3);
        else
            printf("%c",ch);
        i++;
    }
    fclose(file);

}

