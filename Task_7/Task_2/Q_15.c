/*
Program to write 10 Product details to a file and write them into separate files based on the type (packed, fresh) of the product. Update stock when it reaches below or 5.

Note: PNo, PName, Type, Quantity, CostperUnit as  fields of a Product structure.
*/

#include<stdio.h>
#include <stdlib.h>

struct structure{
    int PNo;
    char PName[15],Type[15];
    int Quantity,CostperUnit,NoOfProduct;
}Product[10],Products[10];

void ProductDetails();
void Display();
FILE *file,*packed,*fresh;

int main(){
    int i,choice;
    while(1){
        printf("\t\t\t\t1 - ENTER THE PRODUCT DETAILS\n\t\t\t\t2 - SALES THE PRODUCT\n\t\t\t\t3 - DISPLAY THE PRODUCT\n\t\t\t\t0 - EXIT\nENTER THE NUMBER : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                    ProductDetails();
                    break;
            case 2:
                    Sales();
                    break;
            case 3:
                    Display();
                    break;
            case 0:
                    printf("\t\t\t\t\t** EXIT **");
                    exit(0);
        }
    }
}


void ProductDetails(){
        printf("<-------------------------------ENTER THE PRODUCT DETAILS----------------------------------->\n");
        file=fopen("Q_15.bin","wb");
        int i=0;
        printf("ENTER THE NO OF PRODUCT : ");
        int NoOfProduct;
        scanf("%d",&NoOfProduct);
        while(i<NoOfProduct){
            printf("\t\t\tPRODUCT  %d \n",i+1);
            printf("ENTER THE PRODUCT NO : ");
            scanf("%d",&Product[i].PNo);
            printf("ENTET THE PRODUCT NAME : ");
            scanf("%s",Product[i].PName);
            printf("ENTET THE PRODUCT TYPE (packed/fresh): ");
            scanf("%s",Product[i].Type);
            printf("ENTET THE PRODUCT QUANTITY : ");
            scanf("%d",&Product[i].Quantity);
            printf("ENTET THE PRODUCT COSTPERUNIT : ");
            scanf("%d",&Product[i].CostperUnit);

            Product[i].NoOfProduct=NoOfProduct;
            fwrite(&Product[i],sizeof(struct structure),1,file);
            i++;
        }
        fclose(file);
        printf("<-------------------------------------------------------------------------------------------->\n");
}

void Display(){
        printf("<---------------------------------DISPLAY THE PRODUCT----------------------------------------->\n");
        file=fopen("Q_15.bin","rb");
        packed=fopen("Q_15_packed.bin","wb");
        fresh=fopen("Q_15_packed.bin","wb");
        printf("\n    \t\t\t\t     ** PACKED **\n\n  ");
        int i=0;
        while(i<5){
            fread(&Products[i],sizeof(struct structure),1,file);
            if(strcmp(Products[i].Type,"packed")==0){

            printf("\t\t\t\t\tPRODUCT  %d \n\n",i+1);

            printf("THE PRODUCT NO : ");
            printf("%d\n",Products[i].PNo);

            printf("THE PRODUCT NAME : ");
            printf("%s\n",Products[i].PName);

            printf("THE PRODUCT TYPE : ");
            printf("%s\n",Products[i].Type);

            printf("THE PRODUCT QUANTITY : ");
            printf("%d\n",Products[i].Quantity);

            printf("THE PRODUCT COSTPERUNIT : ");
            printf("%d\n",Products[i].CostperUnit);

            fwrite(&Products[i],sizeof(struct structure),1,packed);
            }
            i++;
        }
        i=0;
        fclose(file);
        file=fopen("Q_15.bin","rb");
        rewind(file);
        fread(&Products[i],sizeof(struct structure),1,file);
        printf("\n     \t\t\t\t     ** FRESH **\n\n  ");
        while(i<5){
            fread(&Products[i],sizeof(struct structure),1,file);
            if(strcmp(Products[i].Type,"fresh")==0){

            printf("\t\t\t\t\tPRODUCT  %d \n\n",i+1);

            printf("THE PRODUCT NO : ");
            printf("%d\n",Products[i].PNo);

            printf("THE PRODUCT NAME : ");
            printf("%s\n",Products[i].PName);

            printf("THE PRODUCT QUANTITY : ");
            printf("%d\n",Products[i].Quantity);

            printf("THE PRODUCT COSTPERUNIT : ");
            printf("%d\n",Products[i].CostperUnit);
            fwrite(&Products[i],sizeof(struct structure),1,fresh);
            }
            i++;
        }
        fclose(file);
        fclose(packed);
        fclose(fresh);
        printf("<---------------------------------------------------------------------------------------------------->\n");
}

void Sales(){
        printf("<----------------------------------SALES THE PRODUCT----------------------------------------->\n");
        file=fopen("Q_15.bin","rb");
        packed=fopen("Q_15_packed.bin","wb");
        fresh=fopen("Q_15_packed.bin","wb");
        int i=0;
        char proName[15];
        int Quan;
        printf("ENTET THE PRODUCT NAME : ");
        scanf("%s",proName);

        printf("ENTET THE QUANTITY : ");
        scanf("%d",&Quan);
        while(i<5){
            fread(&Products[i],sizeof(struct structure),1,file);
            if(strcmp(Products[i].PName,proName)==0){
                    if(Product[i].Quantity>=Quan)
                        Product[i].Quantity-=Quan;
                    else{
                        printf("%s Only %d is Available\n",Products[i].PName,Product[i].Quantity);
                        break;
                    }
            }
            if(strcmp(Products[i].Type,"packed")==0){
                fwrite(&Products[i],sizeof(struct structure),1,packed);
            }else{
                fwrite(&Products[i],sizeof(struct structure),1,fresh);
            }
            i++;
        }
        fclose(file);
        fclose(packed);
        fclose(fresh);
        printf("<-------------------------------------------------------------------------------------------->\n");

}


