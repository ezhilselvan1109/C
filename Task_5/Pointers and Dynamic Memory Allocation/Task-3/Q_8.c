//To concatenate two strings using pointers.
#include <stdio.h>

char *concatenate(char *s1,char *s2)
{
    int len1=0;
    while(*(s1+len1)!='\0'){
            len1++;
    }
    int i=0;
    while(*(s2+i)!='\0'){
        *(s1+len1) = *(s2+i);
        i++;
        len1++;
    }
    return s1;
}


int main()
{
    char s1[15],s2[50];
    printf("Enter the first string :\n");
    scanf("%s",s1);
    printf("Enter the Second string :\n");
    scanf("%s",s2);
    printf("%s",concatenate(s1,s2));
    return 0;
}
