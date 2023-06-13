//To find the length of string using function pointers.
#include<stdio.h>
int length(char *s1){
    int len=0;
    while(*(s1+len)!='\0'){
            len++;
    }
    return len;
}
int main()
{
    char s1[50];
    printf("Enter the string :\n");
    scanf("%s",s1);
    int (*fun)(int)= length;
    printf("\nAns : %d",fun(s1));
    return 0;
}
