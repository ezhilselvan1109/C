//Write a program in C to perform maths and character library function using switch case (use 5 operations on each)

#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int choice;
	char s[15],s1[15];
	double a,b;
	printf("1-power \n2-squareroot \n3-string length \n4-string copy \n5-string concatenation \n6-string uppercase conversion \n7m-String lower case conversion\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		    printf("Enter two value :\n");
			scanf("%lf%lf",&a,&b);
			printf("Ans : ");
			printf("%lf",pow(a,b));
			break;
		case 2:
		    printf("Enter the one value :\n");
			scanf("%lf",&a);
			printf("Ans : ");
			printf("%lf",sqrt(a));
			break;
		case 3:
		    printf("Enter strings :\n");
			scanf("%s",s);
			printf("Ans : ");
			printf("%d",strlen(s));
			break;
		case 4:
		    printf("Enter strings :\n");
			scanf("%s",s);
			strcpy(s1,s);
			printf("Ans : ");
			printf("%s",s1);
			break;
		case 5:
			printf("Enter two strings :\n");
			scanf("%s %s",s,s1);
			printf("%s",strcat(s,s1));
			break;
		case 6:
		    printf("Enter strings :\n");
			scanf("%s",s);
			printf("Ans : ");
			printf("%s",strupr(s));
			break;
		case 7:
		    printf("Enter strings :\n");
			scanf("%s",s);
			printf("Ans : ");
			printf("%s",strlwr(s));
			break;
		default:
			printf("Enter valid choice");
			break;
	}
}
