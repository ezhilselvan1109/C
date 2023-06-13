//Create a structure student having data members to store roll number, name of student, name of three subjects,
// max marks and minimum marks. Declare a structure variable of student provide facilities to input
// data in data member and display result of student.
#include<stdio.h>

struct student{
    int roll_number;
    char name[50];
    char sub[2][10];
    int max;
    int min;
}details,sub[2];

int main(){
    printf("Enter The RollNo:\n");
    scanf("%d",&details.roll_number);
    printf("Enter The Name:\n");
    scanf("%[^\n]s",&details.name);
    printf("\nEnter Sub Names");

    for(int i=0;i<3;i++){
        scanf("%s ",details.sub[i]);
    }
    printf("Enter The Min Mark:\n");
    scanf("%d",&details.min);
    printf("Enter The Max Mark:\n");
    scanf("%d",&details.max);



    printf("The RollNo:\n");
    printf("%d",details.roll_number);
    printf("The Name:\n");
    printf("%[^\n]",details.name);
    printf("Three sub:");
    for(int i=0;i<3;i++){
        printf("%s\n",details.sub[i]);
    }
    printf("The Min Mark:\n");
    printf("%d",details.min);
    printf("The Max Mark:\n");
    printf("%d",details.max);

}
