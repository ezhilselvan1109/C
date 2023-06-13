
/*

Let us work on the menu of a library. Create a structure containing book information like accession number, name of author,
book title and flag to know whether book is issued or not.
Create a menu in which the following can be done.
1 - Display book information
2 - Add a new book
3 - Display all the books in the library of a particular author
4 - Display the number of books of a particular title
5 - Display the total number of books in the library
6 - Issue a book
(If we issue a book, then its number gets decreased by 1 and if we add a book, its number gets increased by 1)

*/


#include<stdio.h>
#include<string.h>
struct library{
    int accession_number;
    char book_title[50];
    char name_of_author[50];
    int flag;
}book[50]={ 1, "C", "Dennis Ritchie",1,
            2, "Java", "James Gosling",1,
            3, "Html", "Tim Berners-Lee",1,
            4, "python","Guido van Rossum",1,
            5, "Java Script", "David Herman",1
};

int main(){
    int n,count=5,i,num;
    int bookcount,tempcount=bookcount=count;
    char booktitle[20],authorname[20];
    while(1){
            printf("1 - Display book information\n2 - Add a new book\n3 - Display all the books in the library of a particular author\n4 - Display the number of books of a particular title\n5 - Display the total number of books in the library\n6 - Issue a book\n7 - Exit");
    printf("\n");
            printf("\nEnter the Choice(1-7):\n");
    scanf("%d",&n);
    switch(n){
    case 1:
        printf("Display book information \n");
        printf("ACCESSION NUMBER\tBOOK TITILE\tAUTHOR\t\t\tNUMBER OF BOOK");
        for(i=0;i<count;i++){
            printf("\n%-24d%-16s%-24s%d",book[i].accession_number,book[i].book_title,book[i].name_of_author,book[i].flag);
        }
        printf("\n");
        printf("-----------------------------------------------------------------------------------");
        printf("\n");
        break;
    case 2:

        printf("Add a new book :\n");
        printf("Enter the book_title :\n");
        scanf(" %[^\n]s",booktitle);
        printf("Enter the name_of_author :\n");
        scanf(" %[^\n]s",authorname);
        int flag=1,temp;
        strcpy(book[count].book_title,booktitle);
        strcpy(book[count].name_of_author,authorname);
        book[count].accession_number=count+1;
        book[count].flag=1;
        bookcount+=1;
        count++;
        printf("\n");
        printf("-----------------------------------------------------------------------------");
        printf("\n");
        break;
    case 3:
        printf("Display all the books in the library of a particular author :\n");
        char author[50];
        printf("Enter the Author Name :\n");
        scanf(" %[^\n]s",author);
        printf("ACCESSION NUMBER\tBOOK TITILE\tAUTHOR\t\t\tNUMBER OF BOOK");
        for(i=0;i<count;i++){
            if(strcmp(author,book[i].name_of_author)==0)
            printf("\n%-24d%-16s%-24s%d",book[i].accession_number,book[i].book_title,book[i].name_of_author,book[i].flag);
        }
        printf("\n");
        printf("------------------------------------------------------------------------------");
        printf("\n");
        break;
    case 4:
        printf("Display the number of books of a particular title :\n");
        int titlecount=0;
        char title[50];
        printf("Enter the Title Name :\n");
        scanf(" %[^\n]s",title);
        for(i=0;i<count;i++){
            if(strcmp(title,book[i].book_title)==0){
                titlecount++;
            }
        }
        printf("Ans :%d",titlecount);
        printf("\n");
        printf("-----------------------------------------------------------------------------");
        printf("\n");
        break;


    case 5:
        printf("Display the total number of books in the library :\n");
        printf("%d",bookcount);
        printf("\n");
        printf("------------------------------------------------------------------------------");
        printf("\n");
        break;


    case 6:
        printf("Enter the title :\n");
        char Issuetitle[50];
        scanf("%s",Issuetitle);
        for(i=0;i<count;i++){
            if(strcmp(Issuetitle,book[i].book_title)==0){
                if(book[i].flag>=1){
                    book[i].flag-=1;
                    break;
                }
                else
                    continue;
            }else{
                printf("Not Available");
            }
        }
        bookcount--;
        printf("\n");
        printf("----------------------------------------------------------------------------");
        printf("\n");
        break;
    default:
        exit(0);
    }
    }

}
