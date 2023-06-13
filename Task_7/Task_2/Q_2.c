//Program to remove duplicate letters in a file.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    char character,chaarray[15];
    printf("Enter The String : ");
    scanf("%[^\n]",chaarray);
    file=fopen("first.txt","w");
    int i=0;
    for(i=0;chaarray[i]!='\0';i++)
    {
        fputc(chaarray[i],file);
    }
    fclose(file);

    char ch[15];
    file=fopen("first.txt","r");
    i=0;
    while((character=fgetc(file))!=EOF)
    {
        ch[i++]=character;
    }
    int len=i,j;
    fclose(file);
    int temp[len];
    file=fopen("first.txt","w");
    for(i=0;i<len;i++){
        temp[i]=0;
    }
    for(i=0;i<len-1;i++){
        for(j=i+1;j<len;j++){
            if(ch[i]==ch[j]){
                temp[j]=1;
            }
        }
    }
    for(i=0;i<len;i++)
    {
        if(temp[i]!=1)
        {
            fprintf(file,"%c",ch[i]);
        }
    }

    fclose(file);
    printf("remove duplicate letters in a file : ");
    file=fopen("first.txt","r");
    while((character=fgetc(file))!=EOF)
    {
        printf("%c",character);
    }
    fclose(file);
    return 0;
}
