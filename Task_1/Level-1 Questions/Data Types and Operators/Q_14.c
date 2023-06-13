/*
Write a program by using switch case if user enter 11 it will have are area of circle and when user enter
22 it will have area of rectangle and when user enter 33 it will give area of square when user enter 44
it will give area of triangle.
*/
#include<stdio.h>

int main(){
    printf("enter the number \n11 -> area of circle \n22 -> area of rectangle \n33 -> area of square \n44 -> area of triangle\n");
    int num;
    scanf("%d",&num);
    switch(num){
        case 11:
            printf("area of circle :\n");
            float r, Area;
            printf("Enter the radius of circle :\n");
            scanf("%f",&r);
            Area = 3.14*r*r;
            printf("the area of the circle is : %f\n",Area);
        break;
        case 22:
            printf("area of rectangle :\n");
            int width;
            int height;
            printf("Enter the width of rectangle :\n");
            scanf("%d",&width);
            printf("Enter the height of rectangle :\n");
            scanf("%d",&height);
            int area=width*height;
            printf("Area of the rectangle = %d",area);
        break;
        case 33:
            printf("area of square :\n");
            int s;
            printf("Enter the area of square :\n");
            scanf("%d",&s);
            int area_square=s*s;
            printf("Area of the square = %d",area_square);
        break;
        case 44:
            printf("area of triangle :\n");
            int b ,h;
            printf("Enter the height :\n");
            scanf("%d",&h);
            printf("Enter the base :\n");
            scanf("%d",&b);
			area = (b*h) / 2 ;
			printf("\n\n Area of Triangle is: %d",area);
        break;
    }
}

