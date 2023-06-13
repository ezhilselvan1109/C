//Calculate the volume through function.

#include<stdio.h>
//l = Length w = Width h = Height
int main(){
    int l,w,h;
    printf("Enter the length,weight and height :");
    scanf("%d%d%d",&l,&w,&h);
    fun(l,w,h);
}
int fun(int l,int w,int h){
    printf("Volume : %d",l*w*h);
}
