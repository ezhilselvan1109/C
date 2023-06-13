//Write a C program to read numbers from a file and write even, odd and prime numbers to separate file.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    FILE *file1,*fileodd,*fileeven;

    //file1=fopen("D:\\C Program\\Task_7\\Task_1\\Q_2\\Q_2_f.txt","w");
    int *n,i,N;
    printf("Enter the Array Size :\n");
    scanf("%d",&N);
    /*
    n=(int *)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        printf("Enter the %d number : \n",i+1);
        scanf("%d",n+i);
    }
    printf("Array numbers :\n");
    for(i=0;i<N;i++){
        printf("%d ",*(n+i));
    }
    printf("\n");
    for(int i=0;i<N;i++){
        printf("%d\n",putw(*(n+i),file1));
    }
    fclose(file1);
    */
    printf("Print the file number : \n");
    file1=fopen("D:\\C Program\\Task_7\\Task_1\\Q_2\\Q_2_f.txt","r");
    fileodd=fopen("D:\\C Program\\Task_7\\Task_1\\Q_2\\Q_2_odd.txt","w");
    fileeven=fopen("D:\\C Program\\Task_7\\Task_1\\Q_2\\Q_2_even.txt","w");
    fseek(file1,0,SEEK_SET );
    for(int i=0;i<N;i++)
    {
        printf("%d ",getw(file1));
    }
    fseek(file1,0,SEEK_SET );
    printf("\n");
    for(int i=0;i<N;i++){
        if(getw(file1)%2==0){
            printf("Odd :");
            printf("%d\n",getw(file1));
        }else{
            printf("even :");
            printf("%d\n",getw(file1));
            }
    }
    fclose(file1);

}
