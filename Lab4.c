#include <stdio.h>
#include <stdlib.h>

typedef unsigned float_bits;

int floatClass(float_bits f);
float_bits float_negate(float_bits f);
float_bits float_absval(float_bits f);
float_bits float_twice(float_bits f);
float_bits float_half(float_bits f);

int main(int argc, char *argv[]) {
    unsigned int tVar = 0x41;
    int i = atoi(argv[1]);
	printf("FloatClass Test: %u \n", floatClass((float)i));
    printf("FloatNegate Test: %d \n", float_negate((float)i));
    printf("FloatAbsval Test: %d \n", float_absval((float)i));
    printf("FloatTwice Test: %d \n", float_twice((float)i));
    printf("FloatHalf Test: %d \n", float_half((float)i));      //truncating
	return 0;
}

//Task 1
int floatClass(float_bits f){
    int sign = f>>31;
    int expo = (f>>23) & 0xff;
    int mant = f & 0x7fffff;

    if(expo == 0 && mant == 0){             //zero
        return 0;
    }
    
    else if(expo == 0xff && mant == 0){     //infinity
        return 1;
    }

    else if(expo == 0xff && f != f){     //NaN
        return 2;
    }

    else if(expo == 0){                     //Denormalized
        return 3;
    }

    else{                                   //Normalized
        return 4;
    }
}

//Task 2
float_bits float_negate(float_bits f){
    if(floatClass(f) ==  0 || floatClass(f) == 1 || floatClass(f) == 2){
        return f;
    }
    int sign = f>>31;
    int x = 1<<31;
    return 0x80000000 - f^x;
}

//Task 3
float_bits float_absval(float_bits f){
    if(floatClass(f) ==  0 || floatClass(f) == 1 || floatClass(f) == 2){
        return f;
    }
    float_bits i = float_negate(f);
    int sign = f>>31;
    if(sign > 0){
        return i;
    }
    return f;
}

//Task 4
float_bits float_twice(float_bits f){
    int flag = 0;
    if(f>>31 > 0){
        flag = 1;
        f = float_absval(f);
    }
    int sign = f>>31;
    int expo = (f>>23) & 0xff;
    int mant = f & 0x7fffff;

    if(floatClass(f) ==  0 || floatClass(f) == 1 || floatClass(f) == 2){
        return f;
    }

    if(floatClass(f) == 3){
        mant <<= 1;
    }
    else if(expo == 0xff -1){
        expo = 0xff;
        mant = 0;
    }
    else{
        expo += 1;
    }
    if(flag == 1){
        return float_negate((sign<<31) | (expo<<23) | mant);
    }
    return (sign<<31) | (expo<<23) | mant;
}

//Task 5
float_bits float_half(float_bits f){
    int flag = 0;
    if(f>>31 > 0){
        flag = 1;
        f = float_absval(f);
    }
    int sign = f>>31;
    int expo = (f>>23) & 0xff;
    int mant = f & 0x7fffff;

    if(floatClass(f) ==  0 || floatClass(f) == 1 || floatClass(f) == 2){
        return f;
    }

    if(floatClass(f) == 3){
        mant >>= 1;
    }
    else if(expo == 0xff -1){
        expo = 0xff;
        mant = 0;
    }
    else{
        expo -= 1;
    }
    if(flag == 1){
        return float_negate((sign<<31) | (expo<<23) | mant);
    }
    return (sign<<31) | (expo<<23) | mant;
}