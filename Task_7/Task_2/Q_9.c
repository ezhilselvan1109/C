//C program to rename a file using rename() function

#include<stdio.h>
#include<string.h>
int main(){
    FILE *file;
    char oldName[15];
    char newName[15];
    printf("Enter the old FileName :\n");
    scanf("%s",oldName);
    strcat(oldName,".txt");
    file=fopen(oldName,"w");
    char array1[]="EZHIL",ch;
    int len=5,i=0;
    while(i<len)
    {
        putc(array1[i++],file);
    }
    fclose(file);
    printf("Enter the New FileName :\n");
    scanf("%s",newName);
    int flag=rename(oldName,newName);
    if(!flag){
        printf("File Name changed Successfully");
    }else{
        printf("File Name Not changed");
    }
}
