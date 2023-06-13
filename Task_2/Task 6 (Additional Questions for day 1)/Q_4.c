//Program to print all uppercase alphabets from 'A' to 'Z' using while loop.

#include<stdio.h>

int main(){
    char ch='A';
    while(ch<='Z'){
        printf("%c ",ch++);
    }
}
