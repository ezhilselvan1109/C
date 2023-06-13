//C program to print source code of itself as output

#include <stdio.h>
int main()
{
    FILE *file4;
    char ch;
    file4=fopen("Q_4.c","r");
    rewind(file4);
    while((ch=getc(file4))!=EOF)
    {
        printf("%c",ch);
    }
    return 0;
}
