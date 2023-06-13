//Write a c program to perform string manipulation by using the library function.


#include<stdio.h>
#include<string.h>
int main()
{
	int choice;
	char s[15],s1[15];
	printf("1-string length \n2-string copy \n3-string concatenation \n4-string uppercase conversion \n5-String lower case conversion \n6-String compare two strings\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		    printf("Enter strings :\n");
			scanf("%s",s);
			printf("Ans : ");
			printf("%d",strlen(s));
			break;
		case 2:
		    printf("Enter strings :\n");
			scanf("%s",s);
			strcpy(s1,s);
			printf("Ans : ");
			printf("%s",s1);
			break;
		case 3:
			printf("Enter two strings :\n");
			scanf("%s %s",s,s1);
			printf("Ans : ");
			printf("%s",strcat(s,s1));
			break;
		case 4:
		    printf("Enter strings :\n");
			scanf("%s",s);
			printf("Ans : ");
			printf("%s",strupr(s));
			break;
		case 5:
		    printf("Enter strings :\n");
			scanf("%s",s);
			printf("Ans : ");
			printf("%s",strlwr(s));
			break;
        case 6:
            printf("Enter two strings :\n");
            scanf("%s %s",s,s1);
            printf("Ans : ");
            printf("%s",strcmp(s,s1));
            break;
		default:
			printf("Enter valid choice");
			break;
	}
}
