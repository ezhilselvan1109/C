//Create a structure called Time and convert the time into hours or minutes or seconds.
#include<stdio.h>

struct time{
    int hr;
    int min;
    int sec;
}calculate;

int main(){
    printf("Enter The Hours mintes seconds") ;
    scanf("%d%d %d",&calculate.hr,&calculate.min,&calculate.sec);
    printf("%ld",calculate.hr*3600+calculate.min*60+calculate.sec*1);
}


