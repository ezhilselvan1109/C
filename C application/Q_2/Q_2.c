/*

Create a Library management system using C file system.It should follows the below scenarios,

Display the front screen having two options 1. Books Issue 2.Books Return

After clicking the respective numbers it should move to the corresponding menu

In Books issue:

Get the inputs like Stud_name,Stud_Regno,Stud_Dept,No of books, Books ID, Issued date, returning date.

Store those information on a file system

In Books Return page:

Type the Register number (Stud_Regno)

It should display the information about the student like name, department,books issued, no of books, due date and due amount.

After clicking returned option by admin or library manager the corresponding information about the student must be deleted.

Then store the returned candidates information in the another file

*/

/*
Create an exam result generator system at University level application using C programming language. It should follows the below points,

Make two interfaces one for student and another for coordinator

For Coordinator

➤  He or she can login to their respective interface and mention the department.

➤ Enter the total number of students the enter their register number. Then mention the marks in the respective subjects for a respective semester.

➤ Behind the scene the grade, result and GPA must be calculated and stored along with the student information in a separate file.

For Student

➤ They have to enter their password and register number to login to their interface.

➤ After selecting the semester the result should be display along with the register number and  GPA.

*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

struct Library{
    char Stud_name[15];
    int Stud_Regno;
    char Stud_Dept[15];
    int No_Of_books;
    char Name_Of_books[15];
    int Books_ID;
    int Issued_date;
    int Issued_month;
    int Issued_year;
    int returning_date;
    int returning_month;
    int returning_year;
    int due_amount;
    int size;
}student[50];


int leapyear(int);
int DueAmount(int,int,int,int,int,int);
int Calculate_Amount(int);


void BooksIssue();
void BooksReturn();
void IssuseDetails();
void ReturnsDetails();

FILE *file,*tempfile,*returnedfile;


int main()
{
    while(1){
        printf("------------------------------------- MENU ----------------------------------\n\n");
        printf("\t\t\t\t1 - BOOKS ISSUE\n\t\t\t\t2 - BOOKS RETURN\n\t\t\t\t3 - ONLY LIBRARY MANAGER\n\t\t\t\t0 - EXIT\nENTER THE CHOICE : ");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                BooksIssue();
                break;
            case 2:
                BooksReturn();
                break;
            case 3:
                printf("--------------------------------- LIBRARY MANAGER -------------------------------\n\n");
                printf("\t\t\t\t1 - ISSUSE DETAILS\n\t\t\t\t2 - RETURNS DETAILS\n\t\t\t\t3 - BACK\n\t\t\t\t0 - EXIT\nENTER THE CHOICE : ");
                int body_choice;
                scanf("%d",&body_choice);
                switch(body_choice){
                    case 1:
                        IssuseDetails();
                        break;
                    case 2:
                        ReturnsDetails();
                        break;
                    case 3:
                        break;
                    case 0:
                    printf("\n");
                    printf("\t\t\t\t\t* * EXIT * *\n");
                    printf("\n");
                    printf("<------------------------------------------------------------------------------------------------->\n");
                    exit(0);
                }
                break;
            case 0:
                printf("\n");
                printf("\t\t\t\t\t* * EXIT * *\n");
                printf("\n");
                printf("<------------------------------------------------------------------------------------------------->\n");
                exit(0);
        }

    }
    return 0;
}

void BooksReturn(){
    file=fopen("mainfile.bin","rb");
    tempfile=fopen("tempfile.bin","wb");
    returnedfile=fopen("returnedfile.bin","ab");

    int Regno,i=0,flag=0,innerflag=1;
    printf("ENTER THE REGISTAION NO : ");
    scanf("%d",&Regno);

    while(fread(&student[i],sizeof(struct Library),1,file)){
        if(student[i].Stud_Regno==Regno){
            flag=1;
        }
        i++;
    }
    if(flag){
    rewind(file);
    printf("STUDENT NAME   \t DEPARTMENT  \t  BOOKS ID  \t  NAME OF BOOK  \t ISSUED DATE \n");
    while(fread(&student[i],sizeof(struct Library),1,file)){
        if(student[i].Stud_Regno==Regno){
            printf(" %s\t\t  ",student[i].Stud_name);
            printf("%s\t\t\t",student[i].Stud_Dept);
            printf("%d\t\t\t",student[i].Books_ID);
            printf("%s\t   ",student[i].Name_Of_books);
            printf("%d/%d/%d\n",student[i].Issued_date,student[i].Issued_month,student[i].Issued_year);
            }
            i++;
        }
    }else{
        printf("Not yet !!\n");
    }

    if(flag){
    rewind(file);
            int bookid;
            printf("ENTER THE BOOK ID : ");
            scanf("%d",&bookid);
                while(fread(&student[i],sizeof(struct Library),1,file)){
                    if(student[i].Stud_Regno==Regno){
                            if(student[i].Books_ID==bookid){
                            printf("STUDENT NAME   \t DEPARTMENT  \t  BOOKS ID  \t  NAME OF BOOK  \t ISSUED DATE \n");
                            printf(" %s\t\t  ",student[i].Stud_name);
                            printf("%s\t\t\t",student[i].Stud_Dept);
                            printf("%d\t\t\t",student[i].Books_ID);
                            printf("%s\t   ",student[i].Name_Of_books);
                            printf("%d/%d/%d\n\n\n",student[i].Issued_date,student[i].Issued_month,student[i].Issued_year);

                            char ch;
                            printf("ENTER THE RETURNING DATE (DD/MM/YY): ");
                            scanf("%d%c",&student[i].returning_date,&ch);
                            scanf("%d%c",&student[i].returning_month,&ch);
                            scanf("%d",&student[i].returning_year);

                            int returning_date=student[i].returning_date;
                            int returning_month=student[i].returning_month;
                            int returning_year=student[i].returning_year;
                            int Issued_date=student[i].Issued_date;
                            int Issued_month=student[i].Issued_month;
                            int Issued_year=student[i].Issued_year;
                            student[i].due_amount=DueAmount(returning_date,returning_month,returning_year,Issued_date,Issued_month,Issued_year);
                            if(student[i].due_amount!=0)
                            printf("\n\n\t\t\t\tDUE AMOUNT : %d\n\n\n",student[i].due_amount);
                            fwrite(&student[i],sizeof(struct Library),1,returnedfile);
                            }else{
                                fwrite(&student[i],sizeof(struct Library),1,tempfile);
                            }
                            fwrite(&student[i],sizeof(struct Library),1,tempfile);
                    }
                    fwrite(&student[i],sizeof(struct Library),1,tempfile);
                    i++;
                }
    }

    fclose(file);
    fclose(tempfile);
    fclose(returnedfile);


    i=0;
    file=fopen("mainfile.bin","wb");
    tempfile=fopen("tempfile.bin","rb");
    while(fread(&student[i],sizeof(struct Library),1,tempfile)){
        fwrite(&student[i],sizeof(struct Library),1,file);
        i++;
    }
    fclose(file);
    fclose(tempfile);

}


void BooksIssue(){
    file=fopen("mainfile.bin","ab");
    int regno,noofbook,i=0;
    char name[15],department[10];
    printf("ENTER THE STUDENT NAME : ");
    scanf("%s",name);
    printf("ENTER THE STUDENT REGISTAION NO : ");
    scanf(" %d",&regno);
    printf("ENTER THE STUDENT DEPARTMENT : ");
    scanf("%s",department);
    printf("HOW MANY BOOKS YOU WANT??");
    scanf(" %d",&noofbook);
    while(i<noofbook){

        printf("ENTER THE BOOKS ID : ");
        scanf("%d",&student[i].Books_ID);

        printf("ENTER THE NAME OF THE BOOK : ");
        scanf("%s",student[i].Name_Of_books);

        strcpy(student[i].Stud_name,name);

        student[i].Stud_Regno=regno;

        strcpy(student[i].Stud_Dept,department);

        time_t now;
        time(&now);
        struct tm *local = localtime(&now);
        student[i].Issued_date = local->tm_mday;
        student[i].Issued_month = local->tm_mon + 1;
        student[i].Issued_year = local->tm_year + 1900;
        fwrite(&student[i],sizeof(struct Library),1,file);
        i++;
    }
    fclose(file);
}


int DueAmount(int returning_date,int returning_month,int returning_year,int Issued_date,int Issued_month,int Issued_year){
        int md[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        long int n1 = returning_year * 365 + returning_date;
        for (int i = 0; i < returning_month - 1; i++)
        {
            n1 =n1+ md[i];
        }
        n1 = n1+leapyear(returning_year);
        long int n2 = Issued_year * 365 + Issued_date;
        for (int i = 0; i < Issued_month - 1; i++)
        {
            n2 =n2+ md[i];
        }
        n2 = n2+leapyear(Issued_year);
        int difference_date=n1 - n2;
        int amount=Calculate_Amount(difference_date);
        return amount;
}

int leapyear(int year)
{
	if(year%4==0)
	{
		return 1;
	}
	else
	{
	    return 0;
	}
}

int Calculate_Amount(int difference_date){
    int amount=0;
    difference_date-=30;
    while(0<difference_date){
        amount+=5;
        difference_date-=1;
    }
    return amount;
}

void IssuseDetails(){
    int i=0;
    file=fopen("mainfile.bin","rb");
    printf("REGISTAION NO  \t  STUDENT NAME   \t DEPARTMENT  \t  BOOKS ID  \t  NAME OF THE BOOK  \t ISSUED DATE \n");
    while(fread(&student[i],sizeof(struct Library),1,file)){
            printf("%d\t\t\t",student[i].Stud_Regno);
            printf(" %s\t\t  ",student[i].Stud_name);
            printf("%s\t\t\t",student[i].Stud_Dept);
            printf("%d\t\t\t",student[i].Books_ID);
            printf("%s\t   ",student[i].Name_Of_books);

            printf("%d/%d/%d\n",student[i].Issued_date,student[i].Issued_month,student[i].Issued_year);
            i++;
        }
    fclose(file);
}

void ReturnsDetails(){
    int i=0;
    returnedfile=fopen("returnedfile.bin","rb");
    printf("REGISTAION NO  STUDENT NAME  DEPARTMENT   BOOKS ID   NAME OF THE BOOK   ISSUED DATE    DUE DATE   DUE AMOUNT\n");
    while(fread(&student[i],sizeof(struct Library),1,returnedfile)){
            printf("%d\t",student[i].Stud_Regno);
            printf(" %s\t  ",student[i].Stud_name);
            printf("%s\t",student[i].Stud_Dept);
            printf("%d\t",student[i].Books_ID);
            printf("%s\t",student[i].Name_Of_books);

            printf("%d/%d/%d\t",student[i].Issued_date,student[i].Issued_month,student[i].Issued_year);
            printf("%d/%d/%d\t",student[i].returning_date,student[i].returning_month,student[i].returning_year);
            printf("%d\n",student[i].due_amount);
            i++;
        }
    fclose(returnedfile);
}























