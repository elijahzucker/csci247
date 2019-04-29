#include <stdio.h>
#include <stdbool.h>        //bool was unidentified
#include <stdlib.h>

int countSetBits(unsigned int var);
int identifyUniqueInteger(int arrayCount, int* intArray);
int reverseBits(int var);
bool onlyOneBitSet(int);
bool onlyOneBitSetInEvenPosition(int);
int modWithoutUsingModOperator(int n, int d);
int swapNibbles(int);
int numberOfOperationsRequired(int);

int main(int argc, char *argv[]) {

    // char j[100];                                         //Task 1
    // fgets(j, 100, stdin);
    // int i = atoi(j);
    // printf("%d \n", countSetBits(i));                     

    /*int arr[argc-1];                                      //Task 2
    for(int i = 1; i < argc; i++){
        arr[i-1] = atoi(argv[i]);
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d \n", identifyUniqueInteger(n, arr));*/

    // int i = atoi(argv[1]);
    // printf("%d \n", reverseBits(i));                      //Task 3

    //int i = atoi(argv[1]);
    //printf("%d \n", onlyOneBitSet(i));                    //Task 4
    
    //int i = atoi(argv[1]);
    //printf("%d \n", onlyOneBitSetInEvenPosition(i));      //Task 5

    // int i = atoi(argv[1]);
    // int r = atoi(argv[2]);
    // printf("%d \n", modWithoutUsingModOperator(i, r));    //Task 6  

    // int i = atoi(argv[1]);
    // printf("%d \n", swapNibbles(i));                      //Task 7

    // int i = atoi(argv[1]);
    // printf("%d \n", numberOfOperationsRequired(i));       //Task 8 / 9

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
int identifyUniqueInteger(int arrayCount, int* intArray){
    int uni = intArray[0];
    for(int i = 0; i > arrayCount; i++){
        uni = uni ^ intArray[i];
    }
    return uni;
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

//Task 8 / 9
int numberOfOperationsRequired(int var){
    int count = 0;
    if(var <= 1){
        return count;
    }
    while(var > 1){                         //find compliment put the 2 together then bitwise shift by 1 to the right to find the highest power of 2 less than the var
        if(!onlyOneBitSet(var)){
            int msg = 0;
            int varTemp = var;
            while(varTemp > 0){
                varTemp >>= 1;
                msg++;
            }
            var = var & ~(1 << (msg - 1));
            count++;
            continue;
        }
        var >>= 1;                          //dividing by 2
        count++;
    }
    return count;
}