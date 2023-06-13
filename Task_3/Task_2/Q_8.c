//Create a user defined enum type for days of week and display all

#include <stdio.h>
enum days{sunday=1, monday, tuesday, wednesday, thursday, friday, saturday};
int main()
{
   enum days d;
   d=1;
   while(d++<=7){
   switch(d)
   {
       case sunday:
       printf("sunday");
       break;
       case monday:
       printf("monday");
       break;
       case tuesday:
       printf("tuesday");
       break;
       case wednesday:
       printf("wednesday");
       break;
       case thursday:
       printf("thursday");
       break;
       case friday:
       printf("friday");
       break;
       case saturday:
       printf("saturday");
       break;
   }
   printf("\n");
}
    return 0;
}
