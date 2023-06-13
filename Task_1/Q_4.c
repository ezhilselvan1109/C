// Display the ASCII Table.
#include<Stdio.h>

int main(){
    int start=0,end=255,i;
    for(i=start;i<=end;i++){
        printf("%d %c\n",i,i);
    }
}
