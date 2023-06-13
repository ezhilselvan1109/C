//To create an Employee detail using structure and update the same in a file using fscanf() and fprintf() functions.


#include<stdio.h>

struct employee{
    char Id[5];
    char Name[15];
    char gender[10];
    int age;
    char EmailId[25];
    unsigned long phone;
    char Fathers_Name[15];
    char Mothers_Name[15];
    char Marital_Status[15];
    unsigned long Aadhaar_Number;
    char address[256];
    unsigned long BankAccountNo;
    char Name_as_per_Bank_Passbook[25];
    char Name_Of_The_Bank[25];
    char IFSC_Code[15];
}detail[10];


int main(){
    int first_option,employe,i,j,number;
    FILE *file;
    while(1){
        printf(" \t\t\t 1 - ENTER THE DETAILS \n \t\t\t 2 - ENTER THE UPDATE DETAILS\n \t\t\t 3 - PRINT THE DETAILS\n \t\t\t 0 - EXIT\n");
        printf("ENTER THE NUMBER : ");
        scanf("%d",&first_option);
        switch(first_option){
            case 1:
                printf("<------------------------------- FILL THE DETAILS -------------------------------->\n");
                file=fopen("Q_14.txt","w");
                printf("ENTER NUMBER OF EMPLOYEE : ");
                scanf("%d",&employe);
                i=0;
                while(i<employe){
                    printf("ENTER THE EMPLOYEE ID : ");
                    scanf("%s",detail[i].Id);
                    fprintf(file,"%s\n",detail[i].Id);

                    printf("ENTER THE EMPLOYEE NAME : ");
                    scanf("%s",detail[i].Name);
                    fprintf(file,"%s\n",detail[i].Name);

                    printf("ENTER THE EMPLOYEE GENTER (M/F): ");
                    scanf("%s",detail[i].gender);
                    fprintf(file,"%s\n",detail[i].gender);

                    printf("ENTER THE EMPLOYEE AGE (18-55): ");
                    scanf("%d",&detail[i].age);
                    fprintf(file,"%d\n",detail[i].age);

                    printf("ENTER THE EMPLOYEE EMAIL-ID : ");
                    scanf("%s",detail[i].EmailId);
                    fprintf(file,"%s\n",detail[i].EmailId);

                    printf("ENTER THE EMPLOYEE PHONE NO : ");
                    scanf("%lu",&detail[i].phone);
                    fprintf(file,"%lu\n",detail[i].phone);

                    printf("ENTER THE EMPLOYEE FATHER NAME : ");
                    scanf("%s",detail[i].Fathers_Name);
                    fprintf(file,"%s\n",detail[i].Fathers_Name);

                    printf("ENTER THE EMPLOYEE MOTHER NAME : ");
                    scanf("%s",detail[i].Mothers_Name);
                    fprintf(file,"%s\n",detail[i].Mothers_Name);

                    printf("ENTER THE EMPLOYEE MARITAL STATUS : ");
                    scanf("%s",detail[i].Marital_Status);
                    fprintf(file,"%s\n",detail[i].Marital_Status);

                    printf("ENTER THE EMPLOYEE AADHAAR NUMBER : ");
                    scanf("%lu",&detail[i].Aadhaar_Number);
                    fprintf(file,"%lu\n",detail[i].Aadhaar_Number);

                    printf("ENTER THE EMPLOYEE ADDRESS : ");
                    scanf("%s",detail[i].address);
                    fprintf(file,"%s\n",detail[i].address);

                    printf("ENTER THE EMPLOYEE BANK ACCOUNT NO : ");
                    scanf("%lu",&detail[i].BankAccountNo);
                    fprintf(file,"%lu\n",detail[i].BankAccountNo);

                    printf("ENTER THE EMPLOYEE NAME AS PER BANK PASSBOOK : ");
                    scanf("%s",detail[i].Name_as_per_Bank_Passbook);
                    fprintf(file,"%s\n",detail[i].Name_as_per_Bank_Passbook);

                    printf("ENTER THE EMPLOYEE NAME OF THE BANK : ");
                    scanf("%s",&detail[i].Name_Of_The_Bank);
                    fprintf(file,"%s\n",detail[i].Name_Of_The_Bank);

                    printf("ENTER THE EMPLOYEE IFSC CODE : ");
                    scanf("%s",&detail[i].IFSC_Code);
                    fprintf(file,"%s\n",detail[i].IFSC_Code);
                    i++;
                    fclose(file);
                }
                printf("<----------------------------------------------------------------------->\n");
                break;
            case 2:
                printf("<------------------------------- UPDATE -------------------------------->\n");

                /*
                printf(" \t\t\t 1 - UPDATE TO OLD RECORD\n \t\t\t 2 - ADD NEW EMPLOYEE DETAIL \nENTER THE NUMBER : ");
                scanf("%d",&number);
                if(number==1){
                        while(1){

                        }
                }
                if(number==2)

                */

                while(1){
                        printf("\n \t\t\t 0 - EXIT \n \t\t\t 1 - ENTER THE DETAILS \nENTER THE NUMBER : ");
                        scanf("%d",&j);
                        switch(j){
                            case 1:
                                file=fopen("Q_14.txt","a");
                                i=employe;
                                printf("ENTER THE EMPLOYEE ID : ");
                                scanf("%s",detail[i].Id);
                                fprintf(file,"%s\n",detail[i].Id);

                                printf("ENTER THE EMPLOYEE NAME : ");
                                scanf("%s",detail[i].Name);
                                fprintf(file,"%s\n",detail[i].Name);

                                printf("ENTER THE EMPLOYEE GENTER (M/F): ");
                                scanf("%s",detail[i].gender);
                                fprintf(file,"%s\n",detail[i].gender);

                                printf("ENTER THE EMPLOYEE AGE (18-55): ");
                                scanf("%d",&detail[i].age);
                                fprintf(file,"%d\n",detail[i].age);

                                printf("ENTER THE EMPLOYEE EMAIL-ID : ");
                                scanf("%s",detail[i].EmailId);
                                fprintf(file,"%s\n",detail[i].EmailId);

                                printf("ENTER THE EMPLOYEE PHONE NO : ");
                                scanf("%d",&detail[i].phone);
                                fprintf(file,"%d\n",detail[i].phone);

                                printf("ENTER THE EMPLOYEE FATHER NAME : ");
                                scanf("%s",detail[i].Fathers_Name);
                                fprintf(file,"%s\n",detail[i].Fathers_Name);

                                printf("ENTER THE EMPLOYEE MOTHER NAME : ");
                                scanf("%s",detail[i].Mothers_Name);
                                fprintf(file,"%s\n",detail[i].Mothers_Name);

                                printf("ENTER THE EMPLOYEE MARITAL STATUS : ");
                                scanf("%s",detail[i].Marital_Status);
                                fprintf(file,"%s\n",detail[i].Marital_Status);

                                printf("ENTER THE EMPLOYEE AADHAAR NUMBER : ");
                                scanf("%d",&detail[i].Aadhaar_Number);
                                fprintf(file,"%d\n",detail[i].Aadhaar_Number);

                                printf("ENTER THE EMPLOYEE ADDRESS : ");
                                scanf("%s",detail[i].address);
                                fprintf(file,"%s\n",detail[i].address);

                                printf("ENTER THE EMPLOYEE BANK ACCOUNT NO : ");
                                scanf("%d",&detail[i].BankAccountNo);
                                fprintf(file,"%d\n",detail[i].BankAccountNo);

                                printf("ENTER THE EMPLOYEE NAME AS PER BANK PASSBOOK : ");
                                scanf("%s",detail[i].Name_as_per_Bank_Passbook);
                                fprintf(file,"%s\n",detail[i].Name_as_per_Bank_Passbook);

                                printf("ENTER THE EMPLOYEE NAME OF THE BANK : ");
                                scanf("%s",&detail[i].Name_Of_The_Bank);
                                fprintf(file,"%s\n",detail[i].Name_Of_The_Bank);

                                printf("ENTER THE EMPLOYEE IFSC CODE : ");
                                scanf("%s",&detail[i].IFSC_Code);
                                fprintf(file,"%s\n",detail[i].IFSC_Code);
                                employe++;
                                fclose(file);
                                break;
                            case 0:
                                exit(0);
                    }
                }
                printf("<------------------------------------------------------------------------>\n");
                break;
            case 3:
                printf("<------------------------------- DETAILS -------------------------------->\n");
                file=fopen("Q_14.txt","r");
                char str[15] ;
                fscanf(file,"%s\n",str);
                while(fscanf(file,"%s\n",str)!=EOF){
                    printf ("%s\n", str);

                }
                fclose(file);
                printf("<-------------------------------------------------------------------------->\n");
                break;
            case 0:
                exit(0);
        }
    }
}
