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
    file=fopen("file.bin","wb+");
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
                                    /*
                                    rewind(secondfile);
                                    int Pickup_total=0;
                                    if(Pickup_Point>=2){
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
                                    }else if(Pickup_Point==1){
                                        printf("hi......");
                                        strcpy(TAXI,Pickup_taxi[0]);
                                        printf("%s",TAXI);
                                    }else{
                                        int LowDistance=INT_MAX;
                                            while(fread(&bookingg,sizeof(struct BookingTaxi),1,secondfile)){
                                            if(bookingg.DropTime<=Pickup_Time){
                                                int Distance=abs(Pickup_Time-bookingg.Drop_Point);
                                                if(LowDistance>Distance){
                                                    LowDistance=Distance;
                                                    Taxiflag=0;
                                                    strcpy(TAXI,bookingg.taxi);
                                                }
                                            }
                                        }
                                        if(Taxiflag){
                                            for(i=3;i>=0;i--){
                                                for(j=0;j<T;j++){
                                                    if(!(strcmp(taxi[i],Pickup_taxis[j])==0)){
                                                        strcpy(TAXI,taxi[i]);
                                                    }
                                                }
                                            }
                                        }

                                    }
                                    */

    booking.Pickup_Point=Pickup_Point;
    booking.Drop_Point=Drop_Point;
    booking.PickupTime=Pickup_Time;
    booking.DropTime=Drop_Time;
    printf("\n\n\n\t\t\t\t%s Is Allocated !\n\n\n",strupr(TAXI));
    strcpy(booking.taxi,"taxi1");
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
    while(fread(&booking,sizeof(struct BookingTaxi),1,file)){
        if(strcmp(ch,booking.taxi)==0){
            total+=booking.Amount;
        }
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
    i=0;
    while(fread(&booking,sizeof(struct BookingTaxi),1,file)){
    //if(strcmp(ch,booking.taxi)==0){
    printf("|     %-6d|     %-7d|  %-4c| %-3c|     %-7d|   %-7d|  %-6d|",booking.BookingID,booking.CustomerID,booking.Pickup_Point,booking.Drop_Point,booking.PickupTime,booking.DropTime,booking.Amount);
    printf("%s \n",booking.taxi);
    printf("+-----------+------------+------+----+------------+----------+--------+\n");

    //}
    }
    fclose(file);
}
/*
+-----------+------------+------+----+------------+----------+--------+
| BookingID | CustomerID | From | To | PickupTime | DropTime | Amount |
+-----------+------------+------+----+------------+----------+--------+
|     1     |     1      |  A   | B  |     2      |   3      |  200   |taxi1
+-----------+------------+------+----+------------+----------+--------+
|     2     |     2      |  B   | C  |     1      |   2      |  200   |taxi1
+-----------+------------+------+----+------------+----------+--------+
|     3     |     2      |  C   | D  |     2      |   3      |  200   |taxi1
+-----------+------------+------+----+------------+----------+--------+
|     4     |     3      |  A   | B  |     4      |   5      |  200   |taxi1
+-----------+------------+------+----+------------+----------+--------+
|     5     |     2      |  A   | B  |     2      |   3      |  200   |taxi2
+-----------+------------+------+----+------------+----------+--------+
|     6     |     4      |  B   | D  |     4      |   6      |  350   |taxi2
+-----------+------------+------+----+------------+----------+--------+

*/


