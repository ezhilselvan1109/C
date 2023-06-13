//Program to count and remove all the comment lines in a "C" Program

/* Program to count and remove all the comment lines in a "C" Program
Program to count and remove all the comment lines in a "C" Program */
/* Program to count and remove all the comment lines in a "C" Program
Program to count and remove all the comment lines in a "C" Program
Program to count and remove all the comment lines in a "C" Program*/

#include<stdio.h>

int main(){
    FILE *file=fopen("Dummy.c","r");
    char ch;
    int flag=0,count=0;
    while((ch=getc(file))!=EOF){
        if(ch=='/'){
                ch=getc(file);
                if(ch=='/'){
                    while((ch=getc(file))!='\n'){}
                    count++;
                    ch=getc(file);
                }

                if(ch=='*'){
                    while((ch=getc(file))!='*'){}
                    ch=getc(file);

                    if(ch=='/'){
                           count++;
                           ch=getc(file);
                    }
                }
        }
        printf("%c",ch);
    }
    printf("COUNT : %d",count);
}
