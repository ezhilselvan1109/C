/*

Create an exam result generator system at University level application using C programming language. It should follows the below points,

Make two interfaces one for student and another for coordinator

For Coordinator

*  He or she can login to their respective interface and mention the department.

* Enter the total number of students the enter their register number. Then mention the marks in the respective subjects for a respective semester.

* Behind the scene the grade, result and GPA must be calculated and stored along with the student information in a separate file.

For Student

* They have to enter their password and register number to login to their interface.

* After selecting the semester the result should be display along with the register number and  GPA.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct structure{
int rollno;
char name[15];
char department[15];
char sub_name[10][10];
char sub_grade[10][5];
char sub_result[10][5];
int sub_credits[10];
int sub_marks[10];
char password[15];
float GPA;
int NoOfSubject;
}Student[5];

struct Structure{
char userid[15];
char password[15];
char department[15];
char Name[15];
}Coordinator[5];

FILE *firstfile,*Secondfile;


void Register_Coordinator();
void Login_Coordinator();
void FillStudentDetail(char department[]);
void Login_Student();
void ShowResult(int rollno,char department[]);
char* SubjectResult(int mark);
char* Calculate_Grade(int mark);
int Grade(char ch[]);
int main()
{
    while(1){
        int Login,i;
        char userid[15],password[15];
        printf("--------------------------- RESULT GENERATOR SYSTEM ------------------------------\n");
        printf("\t\t\t\t1 - COORDINATOR\n\t\t\t\t2 - STUDENT\n\t\t\t\t0 - EXIT \nENTER THE CHOICE : ");
        scanf("%d",&Login);
        switch(Login){
            case 1:
                while(1){
                    printf("------------------------------ COORDINATOR PAGE ----------------------------------\n");
                    printf("\t\t\t\t1 - REGISTER\n\t\t\t\t2 - LOGIN\n\t\t\t\t3 - BACK\n\t\t\t\t0 - EXIT\nENTER THE CHOICE : ");
                    int register_login,BACK=0;
                    scanf("%d",&register_login);
                    switch(register_login){
                        case 1:
                            Register_Coordinator();
                            break;
                        case 2:
                            Login_Coordinator();
                            break;
                        case 3:
                            BACK=1;
                            break;
                        case 0:
                            printf("\n");
                            printf("\t\t\t\t\t* * EXIT * *\n");
                            printf("\n");
                            printf("<------------------------------------------------------------------------------------------------->\n");
                            exit(0);
                        }
                    if(BACK){
                        break;
                    }
                }
                break;
            case 2:
                Login_Student();
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

void Register_Coordinator(){
        printf("<------------------------- COORDINATOR REGISTER PAGE ---------------------------->\n");
        firstfile=fopen("login.bin","wb");
        int i=0;
        int loopsize=i+1;
        while(i<loopsize){
            printf("ENTER THE NAME : ");
            scanf("%s",Coordinator[i].Name);

            printf("ENTER THE DEPARTMENT : ");
            scanf("%s",Coordinator[i].department);

            printf("ENTER THE USERNAME : ");
            scanf("%s",Coordinator[i].userid);

            printf("ENTER THE PASSWORD : ");
            scanf("%s",Coordinator[i].password);
            printf("\n\n\t\t\t\tRegister Success !!\n\n");
            fwrite(&Coordinator[i],sizeof(struct Structure),1,firstfile);
        i++;
        }
        fclose(firstfile);
}

void Login_Coordinator(){
    printf("<-------------------------- COORDINATOR LOGIN PAGE ------------------------------>\n");
    firstfile=fopen("login.bin","rb");
    char userid[15],password[15];
    while(1){
        printf("ENTER THE USERNAME : ");
        scanf("%s",userid);
        printf("ENTER THE PASSWORD : ");
        scanf("%s",password);
        int i=0;
        int flag=1;
        while(i<1){
            fread(&Coordinator[i],sizeof(struct Structure),1,firstfile);
            if(strcmp(Coordinator[i].userid,userid)==0 && strcmp(Coordinator[i].password,password)==0){
                fclose(firstfile);
                flag=0;
                printf("\n\n\t\t\t\tLogin Success!!\n\n");
                char department[15];
                strcpy(department,Coordinator[i].department);
                FillStudentDetail(department);
            }
        i++;
        }
        if(!flag){
            break;
        }
        if(flag){
            printf("\n\n\t\tPlease Enter Correct UserName And Password\n\n");
        }
    }
}

void FillStudentDetail(char department[]){
    int i=0,j,NoOfSub,NoOfStudent;
    strcat(department,".bin");
    firstfile=fopen(department,"wb");
    printf("PLEASE ENTER NO OF SUBJECT : ");
    scanf("%d",&NoOfSub);
    for(j=0;j<NoOfSub;j++){
        printf("\nENTER %d SUBJECT NAME : ",j+1);
        scanf("%s",Student[i].sub_name[j]);
        while(1){
        printf("ENTER %s CREDITS (1-4): ",Student[i].sub_name[j]);
        scanf("%d",&Student[i].sub_credits[j]);
        if(Student[i].sub_credits[j]<=4){
            break;
            }else{
            printf("\t\tPLEASE ENTER CORRRECT CREDITS\n");
            }
        }
    }

    printf("\nPLEASE ENTER NO OF STUDENT : ");
    scanf("%d",&NoOfStudent);

    while(i<NoOfStudent){
        printf("ENTER %d STUDENT DETAILS :\n",i+1);
        printf("ENTER THE ROLLNO : ");
        scanf("%d",&Student[i].rollno);

        printf("ENTER THE NAME : ");
        scanf("%s",Student[i].name);
        printf("\n");
        for(j=0;j<NoOfSub;j++){
        printf("ENTER %s MARK : ",strupr(Student[i].sub_name[j]));
        scanf("%d",&Student[i].sub_marks[j]);
        }

        for(j=0;j<NoOfSub;j++){
        strcpy(Student[i].sub_name[j],Student[0].sub_name[j]);
        Student[i].sub_credits[j]=Student[0].sub_credits[j];
        }

        strcpy(Student[i].department,department);

        Student[i].NoOfSubject=NoOfSub;

        char pass[15];
        strcpy(pass,Student[i].name);
        strcat(pass,"@123");
        strcpy(Student[i].password,pass);

        fwrite(&Student[i],sizeof(struct structure),1,firstfile);
        i++;
        printf("\n\n");
    }
    printf("\n\n\t\t\t\tSuccessfully Filled !\n\n");
    fclose(firstfile);
}

void Login_Student(){
    printf("<-------------------------- STUDENT LOGIN PAGE ------------------------------>\n");
    printf("ENTER THE DEPARTMENT NAME : ");
    char department[15];
    scanf("%s",department);
    strcat(department,".bin");
    firstfile=fopen(department,"rb");
    char password[15];
    int userid;
    while(1){
        printf("ENTER THE USERNAME(ROLLNO) : ");
        scanf("%d",&userid);
        printf("ENTER THE PASSWORD(NAME@123) : ");
        scanf("%s",password);
        int i=0;
        int flag=1;
        while(i<5){
            fread(&Student[i],sizeof(struct structure),1,firstfile);
            if(Student[i].rollno==userid && (strcmp(Student[i].password,password))==0){
                fclose(firstfile);
                flag=0;
                printf("\n\n\t\t\t\tLogin Success!!\n\n");
                ShowResult(userid,department);
            }
        i++;
        }
        if(!flag){
            break;
        }
        if(flag){
            printf("\n\n\t\t\tPlease Enter Correct UserName And Password\n\n");
        }
    }
}

void ShowResult(int rollno,char department[]){
    firstfile=fopen(department,"rb");
    int i=0,j,flag=1;
    while(fread(&Student[i],sizeof(struct structure),1,firstfile)){
        if(Student[i].rollno==rollno){


            for(j=0;j<Student[i].NoOfSubject;j++){
                int mark=Student[i].sub_marks[j];
                strcpy(Student[i].sub_grade[j],Calculate_Grade(mark));
                strcpy(Student[i].sub_result[j],SubjectResult(mark));
            }

            for(j=0;j<Student[i].NoOfSubject;j++){
                if(strcmp(Student[i].sub_result[j],"FAIL")==0){
                    flag=0;
                }
            }

            if(flag){
                float SumQ=0,SumD=0;
                char ch[3];
                int G;
                for(j=0;j<Student[i].NoOfSubject;j++){
                    strcpy(ch,Student[i].sub_grade[j]);
                    G=Grade(ch);
                    SumQ+=(G*Student[i].sub_credits[j]);
                    SumD+=Student[i].sub_credits[j];
                }
                Student[i].GPA=SumQ/SumD;
            }else{
                Student[i].GPA=0;
            }

            printf("\n\n\t\t\t\t* * RESULT * *\n");
            printf("\t\t\t   +----------------+--------+\n");
            printf("\t\t\t   |ROLLNO \t    | ");
            printf("%-7d|\n",Student[i].rollno);
            printf("\t\t\t   +----------------+--------+\n");
            printf("\t\t\t   |NAME \t    | ");
            printf("%-7s|\n",Student[i].name);
            printf("\t\t\t   +----------------+--------+\n");


            printf("\t\t\t+--------------+-------+--------+\n");
            printf("\t\t\t| SUBJECT NAME | GRADE | RESULT |\n");
            printf("\t\t\t+--------------+-------+--------+\n");
            for(j=0;j<Student[i].NoOfSubject;j++){
                printf("\t\t\t|%-14s|%-7s|%-8s|\n",Student[i].sub_name[j],Student[i].sub_grade[j],Student[i].sub_result[j]);
                printf("\t\t\t+--------------+-------+--------+\n");
            }

            printf("\t\t\t\t+-----+------+\n");
            printf("\t\t\t\t| GPA | ");
            printf("%-5.2f|\n",Student[i].GPA);
            printf("\t\t\t\t+-----+------+\n");

        }
        i++;
    }
    fclose(firstfile);
}


char* Calculate_Grade(int mark){
        if(0<mark && mark<=49){
            return "RA-F";
        }else if(50<=mark && mark<=59){
            return "B";
        }
        else if(60<=mark && mark<=69){
            return "B+";
        }
        else if(70<=mark && mark<=79){
            return "A";
        }
        else if(80<=mark && mark<=89){
            return "A+";
        }
        else if(90<=mark && mark<=100){
            return "O";
        }
}

char* SubjectResult(int mark){
    if(mark>=50){
        return "PASS";
    }else{
        return "FAIL";
    }
}
int Grade(char ch[]){
    if(strcmp(ch,"O")==0){
        return 10;
    }
    if(strcmp(ch,"A+")==0){
        return 9;
    }
    if(strcmp(ch,"A")==0){
        return 8;
    }
    if(strcmp(ch,"B+")==0){
        return 7;
    }if(strcmp(ch,"B")==0){
        return 6;
    }
}




