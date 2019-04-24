#include <stdio.h>
#include <stdbool.h>        //bool was unidentified

int countSetBits(unsigned int var);
int identifyUniqueInteger(int arrayCount, int*Array);
int reverseBits(int var);
bool onlyOneBitSet(int);
bool onlyOneBitSetInEvenPosition(int);
int modWithoutUsingModOperator(int numerator, int denominator);
int swapNibbles(int);
int numberOfOperationsRequired(int);

int main(int argc, char *argv[]) {
    int i;
    printf("Enter a number: ");
    scanf("%d",&i);
    //printf("%d \n", countSetBits(i));                     //Task 1
    printf("%d \n", reverseBits(i));

    return 0;
}

int countSetBits(unsigned int var){
    unsigned int i = 0;
    while(var){
        i += var & 1;
        var >>= 1;
    }
    return i;
}

int identifyUniqueInteger(int arrayCount, int*Array){

}

int reverseBits(int var){
    int i = 0;
    while(var){
        i <<= 1;
        if(var & 1 == 1){
            i ^= 1;
        }
        var >>= 1;
    }
    return i;
}
/*
bool onlyOneBitSet(int){

}

bool onlyOneBitSetInEvenPosition(int){

}

int modWithoutUsingModOperator(int numerator, int denominator){

}

int swapNibbles(int){

}

int numberOfOperationsRequired(int){
    
}*/