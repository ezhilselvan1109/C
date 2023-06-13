/*
Print a checkerboard (8-by-8 grid). Each square should be 5-by-3 characters wide. A 2-by-2 example follows:

+-----+-----+

|        |      |

|        |      |

|        |      |

+-----+-----+

|       |       |

|       |       |

|       |       |

+-----+-----+
*/

#include<stdio.h>
int main()
{
         char c[33][49];
         int i,j,k;
         int temp;

         for(i=0;i<=32;i++){
            for(j=0;j<=49;j++){
                c[i][j]=" ";
            }
         }
         for(k=0;k<32;k++){
                for(j=0;j<49;j=j+6){
                     c[k][j]='|';
               }
         }

         for(i=0;i<33;i=i+4){
            j=0;
            c[i][j]='+';
            for(k=0;k<8;k++){
                temp=j;
                for(j=(temp+1);j<=(temp+5);j++){
                c[i][j]='-';
                }
                c[i][j]='+';
               }
       }
       for(i=0;i<33;i++){
          for(j=0;j<49;j++){
            printf("%c",c[i][j]);
          }
          printf("\n");
     }
      return 0;
}
