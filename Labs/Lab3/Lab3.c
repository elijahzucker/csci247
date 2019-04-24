#include <stdio.h>

int countSetBits(unsigned int var);
int identifyUniqueInteger(int arrayCount, int*Array);
int reverseBits(int var);

int main(int argc, char *argv[]) {
    /*int i;                                                //Task 1
    printf("Enter a number to check # of set bits: ");      //Task 1
    scanf("%d",&i);                                         //Task 1
    printf("%d \n", countSetBits(i));*/                     //Task 1
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
    
}