//To replace a specific line in a file with a line of another file.
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file;
    int linenumber,linecount=0,i=0,flag=1;
    char ch,arrayline[20];
    printf("ENTER THE SENTENCE :\n");
    scanf("%[^\n]",arrayline);
    int len=strlen(arrayline);
    printf("ENTER THE SPECIFIC LINE NUMBER :\n");
    scanf("%d",&linenumber);
    file=fopen("Q_12.c","r");
    while((ch=fgetc(file))!=EOF){
        if(ch=='\n'){
            linecount++;
        }
        if(linecount+1 != linenumber){
            printf("%c",ch);
        }
        if(linecount+1 == linenumber && flag==1){
            printf("\n");
            flag=0;
        }
        if(linecount+1 == linenumber){
            while(i<len){
                printf("%c",arrayline[i++]);
            }
        }
    }
    return 0;
}
