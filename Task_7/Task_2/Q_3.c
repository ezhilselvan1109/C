//Program to count and remove all the comment lines in a "C" Program

#include<stdio.h>

int main(){
    FILE *file=fopen("Q_3.c","r");
    char ch;
    int flag=0,count=0;
    printf("/");
    while((ch=getc(file))!=EOF){
        if(ch=='/'){
            flag=1;
        }else if(ch=='/' && flag==1){
            count++;
        }else if(ch=='*' && flag==1){
            flag=2;
        }else if(ch=='*' && flag==2){
            flag=3;
        }else if(ch=='/' && flag==3){
            count++;
        }else if(!(flag==1) && !(flag ==2))
            printf("%c",ch);
    }
    printf("%d",count);
}
