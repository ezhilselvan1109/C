#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BookingTaxi{
    char taxi[5];
    int BookingID;
    int CustomerID;
    char Pickup_Point;
    char Drop_Point;
    int PickupTime;
    int DropTime;
    int Amount;
}booking,bookingg;


void Display();
void bookingtaxi();

FILE *file,*secondfile;

int count=0;

int main()
{
    while(1){
        printf("\t\t\t\t 1 - BOOKING\n\t\t\t\t 2 - DETAILS\n\t\t\t\t 3 - EXIT\nENTER THE CHOICE : ");
        int choice;
        scanf("%d",&choice);
        switch(choice){
                case 1:
                        bookingtaxi();
                        break;
                case 2:
                        Display();
                        break;
                case 3:
                        printf("\t\t\t\tExited !! ");
                        exit(0);

    }
    }
    return 0;
}

void bookingtaxi(){
    char taxi[4][6]={"taxi1","taxi2","taxi3","taxi4"};

    char Pickup_taxi[4][6],TAXI[6],Pickup_taxis[25];
    strcpy(TAXI,taxi[0]);
    int Pickup_taxiAmount[4],T=0;

    file=fopen("file.bin","rb");
    while(fread(&booking,sizeof(struct BookingTaxi),1,file)){
        count=booking.BookingID;
    }
    fclose(file);
    file=fopen("file.bin","wb");
    int j=0;
    int Customer_ID;
    char Pickup_Point;
    char Drop_Point;
    int Pickup_Time;
    int Drop_Time;

    printf("ENTER THE CUSTOMER ID :");
    scanf("%d",&Customer_ID);
    printf("ENTER THE PICKUP POINT :");
    scanf(" %c",&Pickup_Point);
    printf("ENTER THE DROP POINT :");
    scanf(" %c",&Drop_Point);
    printf("ENTER THE PICKUP TIME :");
    scanf("%d",&Pickup_Time);

    int sub=Drop_Point-Pickup_Point;
    Drop_Time=sub+Pickup_Time;

    int hours=15*sub;
    hours-=5;
    int charge=100;
    while(0<hours){
        charge+=10;
        hours--;
    }


    booking.Pickup_Point=Pickup_Point;
    booking.Drop_Point=Drop_Point;
    booking.PickupTime=Pickup_Time;
    booking.DropTime=Drop_Time;
    printf("%s Is Allocated !\n",TAXI);
    strcpy(booking.taxi,TAXI);
    booking.BookingID=count+1;
    booking.CustomerID=Customer_ID;
    booking.Pickup_Point=Pickup_Point;
    booking.Drop_Point=Drop_Point;
    booking.PickupTime=Pickup_Time;
    booking.DropTime=Drop_Time;
    booking.Amount=charge;
    fwrite(&booking,sizeof(struct BookingTaxi),1,file);
    fclose(file);



    secondfile=fopen("tempfile.bin","wb");
    file=fopen("file.bin","rb");
    while(fread(&booking,sizeof(struct BookingTaxi),1,file)){
            printf("T1==>%s  ",booking.taxi);
        fwrite(&booking,sizeof(struct BookingTaxi),1,secondfile);
    }
    fclose(secondfile);
    fclose(file);

    secondfile=fopen("tempfile.bin","rb");
    while(fread(&bookingg,sizeof(struct BookingTaxi),1,secondfile))
            {
                printf("T2==>%s ",bookingg.taxi);
        }
    fclose(secondfile);
}

void Display(){
    file=fopen("file.bin","rb");
    char ch[6];
    int total=0;
    int i;
   // printf("ENTER THE TAXI NAME : ");
    //scanf("%s",ch);
    while(fread(&booking,sizeof(struct BookingTaxi),1,file)){
    //    if(strcmp(ch,booking.taxi)==0){
            total+=booking.Amount;
    //    }
    }
    printf("+----------+----------------+\n");
    printf("|  Taxi No | Total Earnings |\n");
    printf("+----------+----------------+\n");
    printf("|%-10s|     %-11d|\n",ch,total);
    printf("+----------+----------------+\n");

    rewind(file);
    printf("+-----------+------------+------+----+------------+----------+--------+\n");
    printf("| BookingID | CustomerID | From | To | PickupTime | DropTime | Amount |\n");
    printf("+-----------+------------+------+----+------------+----------+--------+\n");
    while(fread(&booking,sizeof(struct BookingTaxi),1,file)){
    //if(strcmp(ch,booking.taxi)==0){
    printf("|     %-6d|     %-7d|  %-4c| %-3c|     %-7d|   %-7d|  %-6d|\n",booking.BookingID,booking.CustomerID,booking.Pickup_Point,booking.Drop_Point,booking.PickupTime,booking.DropTime,booking.Amount);
    printf("+-----------+------------+------+----+------------+----------+--------+\n");
    //}
    }
    fclose(file);
}


