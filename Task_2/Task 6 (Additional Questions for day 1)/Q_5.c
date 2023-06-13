//Check whether x=10 and y=?(user input) are same w/o using comparison operator.
#include<Stdio.h>

int main(){
    int x=10,y;
    printf("Enter the number of Y: ");
    scanf("%d",&y);
    fun(x,y);
}

int fun(int x,int y){
    printf("Ans: ");
    if(x-y)
        printf("Not Same");
    else
        printf("Same");
}

