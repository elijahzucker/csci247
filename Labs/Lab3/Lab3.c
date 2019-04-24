#include <stdio.h>
#include <stdbool.h>        //bool was unidentified

int countSetBits(unsigned int var);
int identifyUniqueInteger(int arrayCount, int*Array);
int reverseBits(int var);
bool onlyOneBitSet(int);
bool onlyOneBitSetInEvenPosition(int);
int modWithoutUsingModOperator(int n, int d);
int swapNibbles(int);
int numberOfOperationsRequired(int);

int main(int argc, char *argv[]) {
    int i;
    //int r;                                                  //for mod w/out
    printf("Enter a number: ");
    scanf("%d",&i);
    //printf("Enter a second number: ");                      //for mod w/out
    //scanf("%d",&r);
    //printf("%d \n", countSetBits(i));                     //Task 1
    //printf("%d \n", reverseBits(i));                      //Task 3
    //printf("%d \n", onlyOneBitSet(i));                    //Task 4
    //printf("%d \n", onlyOneBitSetInEvenPosition(i));      //Task 5
    //printf("%d \n", modWithoutUsingModOperator(i, r));    //Task 6
    //printf("%d \n", swapNibbles(i));                      //Task 7
    printf("%d \n", numberOfOperationsRequired(i));                      //Task 8

    return 0;
}

//Task 1
int countSetBits(unsigned int var){
    unsigned int i = 0;
    while(var){
        i += var & 1;
        var >>= 1;
    }
    return i;
}

//Task 2
int identifyUniqueInteger(int arrayCount, int*Array){

}

//Task 3
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

//Task 4
bool onlyOneBitSet(int var){
    return var && !(var & (var-1));
}

//Task 5
bool onlyOneBitSetInEvenPosition(int var){
    int i = 0;
    if(onlyOneBitSet(var) == 0){
        return 0;
    }
    while(onlyOneBitSet(var) == 1){
        var >>= 1;
        i++;
    }
    if(i % 2 == 0){
        return 1;
    }
    return 0;
}

//Task 6
int modWithoutUsingModOperator(int n, int d){
    int q = n / d;
    int p = q * d;
    int m = n - p;
    return m;
}

//Task 7
int swapNibbles(int var){
    return((var & 0x0F) << 4 | (var & 0xF0) >> 4);
}

//Task 8
int numberOfOperationsRequired(int var){
    int count = 0;
    if(var <= 1){
        return count;
    }
    while(var > 1){
        if(onlyOneBitSet(var)){
            var = var - (var >> 1);
            count++;
            continue;
        }
        var = var/2;
        count++;
    }
    return count;
}