#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
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
    printf("\t\t       * * * TAXI BOOKING APPLICATION * * *\n\n");
    while(1){
        printf("\t\t\t\t 1 - BOOKING\n\t\t\t\t 2 - DETAILS\n\t\t\t\t 3 - FULL LIST\n\t\t\t\t 0 - EXIT\nENTER THE CHOICE : ");
        int choice;
        scanf("%d",&choice);
        switch(choice){
                case 1:
                        bookingtaxi();
                        for(int i=0;i<82;i++){
                            printf(".");
                        }
                        printf("\n\n");
                        break;
                case 2:
                        Display();
                        for(int i=0;i<82;i++){
                            printf(".");
                        }
                        printf("\n\n");
                        break;
                case 3:
                        FullList();
                        for(int i=0;i<82;i++){
                            printf(".");
                        }
                        printf("\n\n");
                        break;
                case 0:
                        printf("\t\t\t\tExited !! ");
                        exit(0);

    }
    }
    return 0;
}

void bookingtaxi(){
    char taxi[4][6]={"taxi1","taxi2","taxi3","taxi4"};
    file=fopen("file.bin","rb");
    while(fread(&booking,sizeof(struct BookingTaxi),1,file)){
        count=booking.BookingID;

    }
    fclose(file);
    file=fopen("file.bin","ab+");
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
    /*---------------------------------------------------------------------*/
                                    char Pickup_taxi[4][6],TAXI[6],Pickup_taxis[25][30];
                                    strcpy(TAXI,taxi[0]);
                                    int Pickup_taxiAmount[4],T=0,ResultFlag=0;

                                    secondfile=fopen("tempfile.bin","rb");

                                    int P=0,P1=0,i=0,Taxiflag=1;
                                    int PickupCount=0,TaxiLocation;
                                    while(fread(&bookingg,sizeof(struct BookingTaxi),1,secondfile)){
                                        if(bookingg.Drop_Point==Pickup_Point && bookingg.DropTime<=Pickup_Time){
                                            PickupCount++;
                                            strcpy(Pickup_taxi[P++],bookingg.taxi);
                                        }
                                    }
                                    rewind(secondfile);
                                    while(fread(&bookingg,sizeof(struct BookingTaxi),1,secondfile)){
                                            strcpy(Pickup_taxis[T++],bookingg.taxi);
                                    }
                                    rewind(secondfile);
                                    int Pickup_total=0;
                                    if(PickupCount>=2){
                                        while(i<=P){
                                        while(fread(&bookingg,sizeof(struct BookingTaxi),1,secondfile)){
                                            if(strcmp(Pickup_taxi[i],bookingg.taxi)==0){
                                            Pickup_total+=bookingg.Amount;
                                            }
                                        }
                                        Pickup_taxiAmount[i]=Pickup_total;
                                        rewind(secondfile);
                                        i++;
                                        }
                                        int LowAmount=INT_MAX;
                                        for(i=0;i<P;i++){
                                            if(LowAmount>Pickup_taxiAmount[i]){
                                                LowAmount=Pickup_taxiAmount[i];
                                                TaxiLocation=i;
                                            }
                                        }
                                        strcpy(TAXI,Pickup_taxi[TaxiLocation]);
                                        ResultFlag=1;
                                    }else if(PickupCount==1){
                                        strcpy(TAXI,Pickup_taxi[0]);
                                        ResultFlag=1;
                                    }else{
                                        int LowDistance=INT_MAX;
                                        while(fread(&bookingg,sizeof(struct BookingTaxi),1,secondfile)){
                                            if(bookingg.DropTime<=Pickup_Time){
                                                int Distance=abs(Pickup_Point-bookingg.Drop_Point);
                                                if(LowDistance>Distance){
                                                    LowDistance=Distance;
                                                    Taxiflag=0;
                                                    strcpy(TAXI,bookingg.taxi);
                                                }
                                            }
                                    }
                                    if(Taxiflag){
                                            int flag;
                                            for(int i=0;i<4;i++){
                                                flag=0;
                                                for(int j=0;j<T;j++){
                                                    if(strcmp(taxi[i],Pickup_taxis[j])==0){
                                                        flag=1;
                                                        break;
                                                    }

                                                }
                                                if(flag==0)
                                                {
                                                strcpy(TAXI,taxi[i]);
                                                ResultFlag=1;
                                                break;
                                                }
                                            }

                                    }
                                    }
    /*--------------------------------------------------------------------------*/
    if(!ResultFlag){
        printf("\n\n\n\t\t\t\tSorry booking is rejected !\n\n");
    }else{
        printf("\t\t\t\tTaxi can be allotted.\n");
        printf("\t\t\t\t%s Is Allocated !\n",TAXI);
        booking.Pickup_Point=Pickup_Point;
        booking.Drop_Point=Drop_Point;
        booking.PickupTime=Pickup_Time;
        booking.DropTime=Drop_Time;
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
        fclose(secondfile);

        secondfile=fopen("tempfile.bin","wb");
        file=fopen("file.bin","rb");
        while(fread(&booking,sizeof(struct BookingTaxi),1,file)){
            fwrite(&booking,sizeof(struct BookingTaxi),1,secondfile);
        }
    }
    fclose(secondfile);
    fclose(file);
}

void Display(){
    file=fopen("file.bin","rb");
    char ch[6];
    int total=0;
    int i;
    printf("ENTER THE TAXI NAME : ");
    scanf("%s",ch);
    strlwr(ch);
    while(fread(&booking,sizeof(struct BookingTaxi),1,file)){
        if(strcmp(ch,booking.taxi)==0){
            total+=booking.Amount;
        }
    }
    printf("\t\t\t+----------+----------------+\n");
    printf("\t\t\t|  Taxi No | Total Earnings |\n");
    printf("\t\t\t+----------+----------------+\n");
    printf("\t\t\t|%-10s|     %-11d|\n",ch,total);
    printf("\t\t\t+----------+----------------+\n");

    rewind(file);
    printf("+-----------+------------+------+----+------------+----------+--------+\n");
    printf("| BookingID | CustomerID | From | To | PickupTime | DropTime | Amount |\n");
    printf("+-----------+------------+------+----+------------+----------+--------+\n");
    while(fread(&booking,sizeof(struct BookingTaxi),1,file)){
    if(strcmp(ch,booking.taxi)==0){
    printf("|     %-6d|     %-7d|  %-4c| %-3c|     %-7d|   %-7d|  %-6d|\n",booking.BookingID,booking.CustomerID,booking.Pickup_Point,booking.Drop_Point,booking.PickupTime,booking.DropTime,booking.Amount);
    printf("+-----------+------------+------+----+------------+----------+--------+\n");
    }
    }
    fclose(file);
}

void FullList(){
    file=fopen("file.bin","rb");
    rewind(file);
    printf("+-----------+------------+------+----+------------+----------+--------+----------+\n");
    printf("| BookingID | CustomerID | From | To | PickupTime | DropTime | Amount | TaxiName |\n");
    printf("+-----------+------------+------+----+------------+----------+--------+----------+\n");
    while(fread(&booking,sizeof(struct BookingTaxi),1,file)){
    printf("|     %-6d|     %-7d|  %-4c| %-3c|     %-7d|   %-7d|  %-6d|",booking.BookingID,booking.CustomerID,booking.Pickup_Point,booking.Drop_Point,booking.PickupTime,booking.DropTime,booking.Amount);
    printf("%-9s |\n",booking.taxi);
    printf("+-----------+------------+------+----+------------+----------+--------+----------+\n");
    }
    fclose(file);
}


