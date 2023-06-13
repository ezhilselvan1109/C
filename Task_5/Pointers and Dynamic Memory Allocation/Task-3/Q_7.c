//To copy one string to another using pointers.

#include <stdio.h>

char *copyString(char *s1,int len)
{
    char *s2;
    int i=0;
    while(i<len)
    {
        *(s2+i) = *(s1+i);
        i++;
    }
    return s2;
}


int main()
{
    char *s1;
    printf("Enter the string :\n");
    scanf("%s",s1);
    int len=0;
    while(*(s1+len)!='\0'){
            len++;
    }
    printf("%s",copyString(s1,len));
    return 0;
}
