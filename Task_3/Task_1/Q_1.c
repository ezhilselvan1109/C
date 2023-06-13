//Create an array that contains "yourname" where add 1 to the content of odd-numbered locations and subtract 1 from the even-numbered locations.

#include<Stdio.h>
#include<string.h>

int main(){
    char ch[100];
    printf("Enter the string :\n");
    scanf("%s",ch);
    int i,len=strlen(ch);
    for(i=0;i<len;i++){
        if(i%2==0)
            ch[i]+=1;
        else
            ch[i]-=1;
    }
    printf("%s",ch);
}
