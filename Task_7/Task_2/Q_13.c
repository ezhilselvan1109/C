/*
Program to read 10 student details from a file and write them into another file for those who have total marks>400 or Average>80.

Note: RNo, Name, Course, Mark-1,Mark-2,Mark-3,Mark-4,Mark-5,Total and Average as

fields of a Student structure.

Use binary form.
*/

#include<stdio.h>

struct student{
    struct details{
        int Rno;
        char Name[15];
        char Course[15];
        int Marks_1;
        int Marks_2;
        int Marks_3;
        int Marks_4;
        int Marks_5;
    }detail;
    int total;
    int Average;
}detailss[10],detailsss[10];
int main(){
    FILE *file,*file1;
    int i,count=0;
    int choice;
    while(1){
        printf("\t\t\t\t1 - FILL THE  DETAILS\n\t\t\t\t2 - DISPLAY ALL DETAILS \n\t\t\t\t3 - DISPLAY ABOVE AVEARAGE 80%%\n\t\t\t\t0 - EXIT\nENTER THE NUMBER : ");
        scanf("%d",&choice);
        switch(choice){
                case 1:
                    file=fopen("Q_13.bin","wb");
                    i=0;
                    while(i<4){
                        printf("\t\t\t\tSTRUDENT %d  ",i+1);
                        printf("\nEnter the Roll No : ");
                        scanf("%d",&detailss[i].detail.Rno);
                        printf("\nEnter the Name : ");
                        scanf("%s",&detailss[i].detail.Name);
                        printf("\nEnter the Course : ");
                        scanf("%s",&detailss[i].detail.Course);
                        printf("\nEnter the Marks_1 : ");
                        scanf("%d",&detailss[i].detail.Marks_1);
                        printf("\nEnter the Marks_2 : ");
                        scanf("%d",&detailss[i].detail.Marks_2);
                        printf("\nEnter the Marks_3 : ");
                        scanf("%d",&detailss[i].detail.Marks_3);
                        printf("\nEnter the Marks_4 : ");
                        scanf("%d",&detailss[i].detail.Marks_4);
                        printf("\nEnter the Marks_5 : ");
                        scanf("%d",&detailss[i].detail.Marks_5);
                        detailss[i].total=(detailss[i].detail.Marks_1+detailss[i].detail.Marks_2+detailss[i].detail.Marks_3+detailss[i].detail.Marks_4+detailss[i].detail.Marks_5);
                        detailss[i].Average=(detailss[i].total/5);
                        fwrite(&detailss[i],sizeof(struct student),1,file);
                        i++;
                    }
                    fclose(file);
                    printf("\n");
                    printf("<------------------------------------------------------------------------------------------------->\n");
                    break;

                    case 2:
                        file=fopen("Q_13.bin","rb");
                        file1=fopen("Q_13_copy.bin","wb");
                        i=0;
                            printf("+--------+-------------+---------+---------+---------+---------+---------+---------+-----+-------+\n");
                            printf("|ROLL_NO |     NAME    |COURSE   | MARKS_1 | MARKS_2 | MARKS_3 | MARKS_4 | MARKS_5 |TOTAL|AVERAGE|\n");
                            printf("+--------+-------------+---------+---------+---------+---------+---------+---------+-----+-------+\n");
                            while(i<4){
                            fread(&detailss[i],sizeof(struct student),1,file);
                            if(detailss[i].total > 400 ||  detailss[i].Average > 80){
                            fwrite(&detailss[i],sizeof(struct student),1,file1);
                            count++;
                            printf("|%-8d|%-13s|%-9s|%-9d|%-9d|%-9d|%-9d|%-9d|%-5d|%-7d|\n",detailss[i].detail.Rno,detailss[i].detail.Name,detailss[i].detail.Course,detailss[i].detail.Marks_1,detailss[i].detail.Marks_2,detailss[i].detail.Marks_3,detailss[i].detail.Marks_4,detailss[i].detail.Marks_5,detailss[i].total,detailss[i].Average);
                            printf("+--------+-------------+---------+---------+---------+---------+---------+---------+-----+-------+\n");
                            }else{
                            printf("|%-8d|%-13s|%-9s|%-9d|%-9d|%-9d|%-9d|%-9d|%-5d|%-7d|\n",detailss[i].detail.Rno,detailss[i].detail.Name,detailss[i].detail.Course,detailss[i].detail.Marks_1,detailss[i].detail.Marks_2,detailss[i].detail.Marks_3,detailss[i].detail.Marks_4,detailss[i].detail.Marks_5,detailss[i].total,detailss[i].Average);
                            printf("+--------+-------------+---------+---------+---------+---------+---------+---------+-----+-------+\n");
                            }
                            i++;
                        }
                        fclose(file);
                        fclose(file1);
                        printf("\n");
                        printf("<------------------------------------------------------------------------------------------------->\n");
                        break;
                    case 3:
                        file1=fopen("Q_13_copy.bin","rb");
                        i=0;
                        printf("+--------+-------------+---------+---------+---------+---------+---------+---------+-----+-------+\n");
                        printf("|ROLL_NO |     NAME    |COURSE   | MARKS_1 | MARKS_2 | MARKS_3 | MARKS_4 | MARKS_5 |TOTAL|AVERAGE|\n");
                        printf("+--------+-------------+---------+---------+---------+---------+---------+---------+-----+-------+\n");
                            while(i<count){
                            fread(&detailsss[i],sizeof(struct student),1,file1);
                            printf("|%-8d|%-13s|%-9s|%-9d|%-9d|%-9d|%-9d|%-9d|%-5d|%-7d|\n",detailsss[i].detail.Rno,detailsss[i].detail.Name,detailsss[i].detail.Course,detailsss[i].detail.Marks_1,detailsss[i].detail.Marks_2,detailsss[i].detail.Marks_3,detailsss[i].detail.Marks_4,detailsss[i].detail.Marks_5,detailsss[i].total,detailsss[i].Average);
                            i++;
                            printf("+--------+-------------+---------+---------+---------+---------+---------+---------+-----+-------+\n");

                        }
                        fclose(file1);
                        printf("\n");
                        printf("<------------------------------------------------------------------------------------------------->\n");
                        break;
                    case 0:
                        printf("\n");
                        printf("\t\t\t\t\t* * EXIT * *\n");
                        printf("\n");
                        printf("<------------------------------------------------------------------------------------------------->\n");
                        exit(0);
        }
    }
}
