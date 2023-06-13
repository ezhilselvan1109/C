/*
Write a program to take input of 5 subject. Find total and percent based on percent provide grade like:

             IF Per > 80 “A+”

             Per >= 65 and per <=80 “A”

             Per > =50 and per <=65 “B”

             Per >= 42 and per <=50 “C”

             Per < 42 “Fail”

*/
#include<stdio.h>

int main(){
int s1,s2,s3,s4,s5,total,percent;
printf("Enter the five marks :\n");
scanf("%d%d%d%d%d",&s1,&s2,&s3,&s4,&s5);
total=s1+s2+s3+s4+s5;
percent=total/5;
printf("Percent : %d\nGrade : ",percent);
if(percent>80)
    printf("A+");
else if(percent>=65 && percent<=80)
    printf("A");
else if(percent>=50 && percent<65)
    printf("B");
else if(percent>=42 && percent<=50)
    printf("C");
else if(percent<42)
    printf("Fail");
}
