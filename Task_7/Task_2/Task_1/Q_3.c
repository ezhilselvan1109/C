//C program to create a file and write data into files
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    FILE *file1;
    /*
    file1=fopen("D:\\C Program\\Task_7\\Task_1\\Q_3_f.txt","w");
    char ch[15];
    scanf("%[^\n]",ch);
    int len=strlen(ch);
    printf("%d",len);
    for(int i=0;i<len;i++){
        fputc(ch[i],file1);
    }
    fclose(file1);
    */
    file1=fopen("D:\\C Program\\Task_7\\Task_1\\Q_3_f.txt","a");
    char ch1[15];
    scanf("%[^\n]",ch1);
    int len1=strlen(ch1);
    printf("%d",len1);
    for(int i=0;i<len1;i++){
        fputc(ch1[i],file1);
    }
    fclose(file1);
}
