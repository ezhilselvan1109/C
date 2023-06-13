//To copy a file.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fF,*fS;
    char ch;
    char chaarray[15];
    printf("Enter The String : ");
    scanf("%[^\n]",chaarray);
    fF=fopen("first.txt","w");
    int i=0;
    for(i=0;chaarray[i]!='\0';i++)
    {
        fputc(chaarray[i],fF);
    }
    fclose(fF);
    fF=fopen("first.txt","r");
    fS=fopen("second.txt","w");
    while((ch=fgetc(fF))!=EOF)
    {
        fputc(ch,fS);
    }
    fclose(fF);
    fclose(fS);
    printf("FROM SECOND FILE : ");
    fS=fopen("second.txt","r");
    while((ch=fgetc(fS))!=EOF)
    {
        printf("%c",ch);
    }
    fclose(fS);
    return 0;
}
