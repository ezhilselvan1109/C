//Create an array that contains any string, where remove all occurrences of any special characters and spaces and find the length of the string w/o using strlen().

#include<Stdio.h>

int main(){
    char ch[1000],count=0;
    printf("Enter the string :\n");
    scanf("%[^\n]s",ch);
    int len=0;
    for(int i=0;ch[i]!='\0';i++){
        if(!(('a'<=ch[i] && ch[i]<='z' )|| ('A'<=ch[i] && ch[i]<='Z')|| ('0'<=ch[i] && ch[i]<='9')))
        {
            count++;
        }
        len++;
    }
    int ans=len-count;
    printf("%d",ans);
}
