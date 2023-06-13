//To read numbers from a file and write even, odd numbers to separate files.

#include<stdio.h>

int main(){
    FILE *number,*odd,*even;
    number=fopen("number.bin","wb");
    odd=fopen("Q_5_odd.bin","wb");
    even=fopen("Q_5_even.bin","wb");
    int n,i,num;
    printf("Enter the how many numbers :\n");
    scanf("%d",&n);
    printf("Enter the numbers :\n");
    for(i=0;i<n;i++){
        scanf("%d",&num);
        putw(num, number);
    }
    fclose(number);
    number=fopen("number.bin","rb");
    while((num=getw(number))!=EOF){
        if(num%2==1){
            putw(num, odd);
        }
        else
            putw(num, even);
    }
    fclose(number);
    fclose(odd);
    fclose(even);

    odd=fopen("Q_5_odd.bin","rb");
    even=fopen("Q_5_even.bin","rb");
    printf("Odd Number : ");
    while((num=getw(odd))!=EOF){
        printf("%d ",num);
    }

    printf("\nEven Number : ");
    while((num=getw(even))!=EOF){
        printf("%d ",num);
    }
    fclose(odd);
    fclose(even);
}
