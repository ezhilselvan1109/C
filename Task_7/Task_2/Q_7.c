//Program to find and replace a word in a text file.
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file,*tempfile;
    file=fopen("file.txt","w");
    char array1[15],ch;
    printf("ENTER THE STRING :");
    scanf("%[^\n]",array1);
    int len=strlen(array1),i=0;
    file=fopen("file.txt","w");
    while(i<len)
    {
        printf("%c",ch);
        putc(array1[i++],file);
    }
    fclose(file);

    file=fopen("file.txt","r");
    tempfile=fopen("secondfile.txt","w");
    printf("ENTER THE STRING TO FIND  :\n");
    char find[10],read[10];
    scanf("%s",find);
    printf("ENTER THE STRING TO REPLACE :\n");
    char replace[256];
    scanf("%s",replace);
    rewind(file);
    while ((fscanf(file,"%s",read))!=EOF) {
        if (strcmp(read,find) == 0) {
            strcpy(read,replace);
        }
        fprintf(tempfile,"%s ",read);
    }
    fclose(file);
    fclose(tempfile);



    file=fopen("file.txt","w");
    tempfile=fopen("secondfile.txt","r");
    rewind(tempfile);
    while ((fscanf(tempfile,"%s",read))!=EOF) {
        fprintf(file,"%s ",read);
    }
    fclose(file);
    fclose(tempfile);

    printf("AFTER REPLACE A FILE : ");
    file=fopen("file.txt","r");
    rewind(file);
    while ((fscanf(file,"%s",read))!=EOF) {
        printf("%s ",read);
    }
    fclose(file);
}
