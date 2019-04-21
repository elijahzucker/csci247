/*
    Course: CSCI 247 -Spring 2019
    File Name Lab1.c

    Preproccessor directives: Include/Define,
    Foward Declaration: 
    Macros:
    Functions:
    Escape Charecter: these tell the compiler that the following bit in say a print statement will
    be an instruction like \n calling for a paragraph break.
    Operators:
    Keywords:
    Printf: 
*/

#include<stdio.h>
#include<string.h>

#define CHAR_DATA_TYPE "char"
#define INT_DATA_TYPE "int"

char* GetStringFromStdin(char* str);

void DataTypeSizes(void);
void DisplayString(const char* str);

int main(int argc, char* argv[]){
    printf("argc %d\n", argc - 1);
    for(int i = 0; i < sizeof(argc); i++){
        printf("argv[%d] %s\n",i , argv[i]);
    }
    //printf("Wow! This is my first C program!\r\n");
    char str[100];
    char* strPtr;
    fputs(GetStringFromStdin(str), stdout);
    DisplayString(str);
    DataTypeSizes();
    return(0);
}

char* GetStringFromStdin(char* str){
    printf("Enter a thing: ");
    return fgets(str, 100, stdin);
}


void DataTypeSizes(void){
    printf("\"%s\" is a standard C datatype. Size of a \"%s\" data type is=%ld\r\n",
    CHAR_DATA_TYPE, CHAR_DATA_TYPE, sizeof(char));
    printf("\"%s\" is a standard C datatype. Size of a \"%s\" data type is=%ld\r\n",
    INT_DATA_TYPE, INT_DATA_TYPE, sizeof(int));
}

void DisplayString(const char* str){
        printf("%s \n", str);
}