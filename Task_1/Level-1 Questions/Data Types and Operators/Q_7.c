//Write a program to differentiate local and global variables.

#include<stdio.h>
	int first;
	int Add()
	{
        int second;
        printf("Enter Local Variable For add : \n");
        scanf("%d",&second);
        printf("sum : %d\n",first+second);
	}

    int Mul()
    {
        int third;
        printf("Enter Local Variable For muliple : \n");
        scanf("%d",&third);
        printf("product : %d",first*third);
    }
    void main()
	{
        printf("Enter the Global Variable : \n");
        scanf("%d",&first);
        Add();
        Mul();
	}

