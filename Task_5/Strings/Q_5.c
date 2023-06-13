//C program to count occurrences of a character in a string.

#include <stdio.h>
#include<string.h>

int count(char s1[],char s)
{
    int len=0,i,count=0;
    while(s1[len]!='\0'){
            len++;
    }
    for(i=0;i<len;i++){
        if(s1[i]==s)
            count++;
    }
    return count;
}


int main()
{
    char s1[15],s;
    printf("Enter the first string :\n");
    scanf("%[^\n]s",s1);
    printf("Enter the character :\n");
    scanf(" %c",&s);
    int ans=count(s1,s);
    printf("Ans:%d",ans);
    return 0;
}
