//Write a program to check whether the entered string is palindrome or not.

#include<stdio.h>

int main(){
    char *ch;
    int i=0,len=0,flag=1;
    //ch=(char*)malloc(20*sizeof(char));
    printf("Enter the string :\n");
    scanf("%s",ch);
    while(*(ch+i)!='\0'){
        printf("%d",i);
        ++i;
    }
    printf("%d",i);
    int temp=len=i;
    temp-=1;
    ch=(char*)malloc(i*sizeof(char));
    for(i=0;i<len;i++){
        if(*(ch+i) != *(ch+temp)){
            flag=0;
            break;
        }
        temp--;
    }


    if(flag){
        printf("Palindrome");
    }else{
        printf("Not a Palindrome");
    }
    return 0;
}
