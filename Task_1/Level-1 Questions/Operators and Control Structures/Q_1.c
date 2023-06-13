/*
The program adds, subtracts, multiplies, and divides simple integers. When the program is running, it zeros the result register and displays its contents. The user can then type in an operator and number. The result are updated and displayed. The following operators are valid:

Operator  Meaning

+   Addition

-   Subtraction

*   Multiplication

/   Division

Example (user input is in boldface)

calc

Result: 0

Enter operator and number: + 123

Result: 123

Enter operator and number: - 23

Result: 100

Enter operator and number: / 25

Result: 4

Enter operator and number: * 4

Result: 16
*/
#include<stdio.h>

int main()
{
    int num,sum=0,times;
    char ch;
    while(1)
    {
        printf("Enter the any operator :\n");
        scanf(" %c",&ch);
        switch(ch)
        {
        case '+':
            printf("Enter the number :\n");
            scanf("%d",&num);
            printf("%d\n",sum+=num);
        break;
        case '-':
            printf("Enter the number :\n");
            scanf("%d",&num);
            printf("%d\n",sum-=num);
        break;
        case '*':
            printf("Enter the number :\n");
            scanf("%d",&num);
            printf("%d\n",sum*=num);
        break;
        case '%':
            printf("Enter the number :\n");
            scanf("%d",&num);
            printf("%d\n",sum%=num);
        break;
        default:
            exit(0);

        }
    }
}




































