//To append content to a file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *file;
    char ch;
    char array1[15];
    printf("ENTER THE STRING :");
    scanf("%[^\n]",array1);
    int len=strlen(array1),i=0;
    file=fopen("file.txt","a");
    while(i<len)
    {
        printf("%c",ch);
        putc(array1[i++],file);
    }
    fclose(file);


    printf("\nAFTER APPEND A FILE : ");
    file=fopen("file.txt","r");
    while((ch=getc(file))!=EOF)
    {
        printf("%c",ch);
    }
    fclose(file);
    return 0;
}
