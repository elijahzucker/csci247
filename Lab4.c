#include <stdio.h>
#include <stdlib.h>

typedef unsigned float_bits;

int floatClass(float_bits f);
float_bits float_negate(float_bits f);
float_bits float_absval(float_bits f);

int main(int argc, char *argv[]) {
    unsigned int tVar = 0x41;
    int i = atoi(argv[1]);
	printf("FloatClass Rest: %u \n", floatClass((float)i));
    printf("FloatClass Rest: %u \n", float_negate((float)i));
    printf("FloatClass Rest: %u \n", float_absval((float)i));
	return 0;
}

//Task 1
int floatClass(float_bits f){
    //int sign = f>>31;
    int expo = (f>>23) & 0xff;
    int mant = f & 0x7fffff;

    if(expo == 0 && mant == 0){             //zero
        return 0;
    }
    
    else if(expo == 0xff && mant == 0){     //infinity
        return 1;
    }

    else if(expo == 0xff && mant != 0){     //NaN
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
    int sign = f>>31;
    if(floatClass(f) == 3 || floatClass(f) == 4)
        return f^0x80000000;
    return f;
}

//Task 3
float_bits float_absval(float_bits f){
    if(floatClass(f) == 2 || f > 0 || floatClass(f) == 0){
        return f;
    }
    else{
        return float_absval(f);
    }
}