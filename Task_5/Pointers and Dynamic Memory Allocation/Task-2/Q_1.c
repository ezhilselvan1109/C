//Program to compare two strings using pointers.
#include<stdio.h>
#include<stdlib.h>

int compare(char *s1,char *s2,int len1,int len2)
{
    if(len1!=len2)
        return 0;
    int i=0;
    while(i<len1){
        if(*(s1+i) != *(s2+i))
            return 0;
        i++;
    }
    return 1;
}


int main()
{
    char *s1,*s2;
    printf("Enter First the string :\n");
    scanf("%s",s1);
    printf("Enter Second the string :\n");
    scanf("%s",s2);
    int len1=1,len2=1;
    while(*(s1+len1)!='\0'){
            len1++;
    }
    while(*(s1+len2)!='\0'){
            len2++;
    }
    int flag=compare(s1,s2,len1,len2);
    printf("Ans : ");
    if(flag)
        printf("Same");
    else
        printf("Not Same");
    return 0;
}
