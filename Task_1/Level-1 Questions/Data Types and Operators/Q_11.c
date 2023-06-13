//Program to check a person is eligible to donate blood using nested if.

//Any healthy adult, both male and female, can donate blood. Men can donate safely once in every three months while women can donate every four months. Donor should be in the age group of 18 to 65 years. Donor should be in the age group of 18 to 65 years.
#include<stdio.h>

int main(){
    int age,month;
    char genter;
    printf("Enter the Age : \n");
    scanf("%d",&age);
    printf("Enter the Genter :\n");
    scanf(" %c",&genter);
    printf("Enter the gap between the last donated blood in months \"if you donate blood early enter zero\":\n");
    scanf("%d",&month);
    if(age>18 && age<65){
        if(genter=='m'){
            if(month>=3 || month==0){
                printf("eligible");
            }else{
                printf("not eligible");
            }
        }
        if(genter=='f'){
            if(month>=4 || month==0){
                printf("eligible");
            }else{
                printf("not eligible");
            }
        }
    }else{
        printf("not eligible");
    }

}
