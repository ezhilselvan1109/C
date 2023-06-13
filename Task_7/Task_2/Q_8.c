//To remove a specific line from a text file.
#include <stdio.h>

int main()
{
    FILE *file;
    int linenumber,linecount=0;
    char ch;
    printf("ENTER THE SPECIFIC LINE NUMBER :");
    scanf("%d",&linenumber);
    file=fopen("Q_8.c","r");
    while((ch=fgetc(file))!=EOF){
        if(ch=='\n'){
            linecount++;
        }
        if(linecount+1 != linenumber){
            printf("%c",ch);
        }
    }
    return 0;
}
