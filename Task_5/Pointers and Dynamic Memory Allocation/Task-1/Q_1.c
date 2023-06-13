//Program to allocate memory at runtime for an array containing "welcome" and add '4' to the characters at even numbered location.

#include<stdio.h>
#include<stdlib.h>
int main(){
    int i;
    char *ch,temp;
    strcpy(ch,"welcome");
    printf("%s\n",ch);
    for(i=0;i<7;i++){
        if(i%2==0){
            *(ch+i)+=4;
        }
    }
    printf("%s",ch);
}
