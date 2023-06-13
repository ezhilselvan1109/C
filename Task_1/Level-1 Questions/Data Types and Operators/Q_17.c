//Write a program in C to illustrate how to use goto statement.
#include <stdio.h>

int main()
{
        int start, end;
        printf("Enter the start and end number :\n");
        scanf("%d%d",&start,&end);
        int curr = start;
        print_line :
        printf("%d ", curr);
         if(curr<end)
        {
            curr++;
            goto print_line;
        }
}
