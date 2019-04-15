/*
    Course: CSCI 247 -Spring 2019
    File Name Lab1.c

*/

#include<stdio.h>
#include<string.h>

#define CHAR_DATA_TYPE "char"
#define INT_DATA_TYPE "int"
char* GetStringFromStdin(char* str);

void DataTypeSizes(void);
void DisplayString( const char* str);

int main(){
    //printf("Wow! This is my first C program!\r\n");
    char str[100];
    fgets(str, 100, stdin);
    DataTypeSizes();
    return(0);
}

void DataTypeSizes(void){
    printf("\"%s\" is a standard C datatype. Size of a \"%s\" data type is=%ld\r\n",
    CHAR_DATA_TYPE, CHAR_DATA_TYPE, sizeof(char));
    printf("\"%s\" is a standard C datatype. Size of a \"%s\" data type is=%ld\r\n",
    INT_DATA_TYPE, INT_DATA_TYPE, sizeof(int));
}

//void Display( const char* str)