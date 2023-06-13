//Count the total number of words in a string.

#include <stdio.h>
#include<string.h>

int count(char s1[])
{
    int len=0,i,count=1;
    while(s1[len]!='\0'){
            len++;
    }
    for(i=0;i<len;i++){
        if(s1[i]==' ')
            count++;
    }
    return count;
}


int main()
{
    char s1[15],s;
    printf("Enter the string :\n");
    scanf("%[^\n]",s1);
    int ans=count(s1);
    printf("%d",ans);
    return 0;
}
