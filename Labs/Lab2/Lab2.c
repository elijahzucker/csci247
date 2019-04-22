#include <stdio.h>

#define BUFFSIZE 4096

char* itoa(int num, char* str, int base);
void stringRev(char* str, int length);
int main(int argc, char *argv[]) {
	int number, base;

	if (argc != 3) {
		printf("Usage: ./Lab2 <number> <base>\n");
		return 1;
	}

	int res = sscanf(argv[1], "%d", &number);
	if (!res || res == EOF) {
		printf("Could not parse %s\n", argv[1]);
		return 1;
	}

	res = sscanf(argv[2], "%d", &base);
	if (!res || res == EOF) {
		printf("Could not parse %s\n", argv[2]);
		return 1;
	} else if (!(2 <= base && base <= 36)) {
		printf("Base must be between 2 and 36\n");
		return 1;
	}

	char buf[BUFFSIZE];

	if (itoa(number, buf, base) != buf) {
		printf("Failed to convert %d to base %d\n", number, base);
		return 1;
	}

	printf("Here is %d converted to base %d:\n%s\n", number, base, buf);

	return 0;
}
void stringRev(char* str, int length){			//reverses the order of a given string
	if(length == 0){							
		return;
	}
	int front = 0;
	int end = length - 1;
	while(front < end){							//swaps the values at the points front and end
		char a, b;								//repeatedly until they meat in the middle
		a = str[front];
		b = str[end];

		str[front] = b;
		str[end] = a;
		front++;
		end--;
	}
}
char* itoa(int num, char* str, int base) {
	int count = 0;								//initialize itterator

	if(num == 0){								//checks if num is zero and trivialy solved
		str[count++] = '0';
		str[count] = '\0';
		return str;
	}
	
	int flag = 0;

	if(num < 0 && base == 10){					//signals a base 10 num is negative
		flag = 1;								//then sets it to positive while flaging it was negative
		num = num * -1;
	}

	while(num != 0){							//converts the number and reads it in in reverse direction
		int temp = num % base;
		if(temp > 9){
			str[count++] = (temp-10) + 'a';
		}
		else{
			str[count++] = temp + '0';
		}
		num = num/base;
	}

	if(flag == 1){								//appends the negative symbol
		str[count++] = '-';
	}
	str[count] = '\0';
	stringRev(str, count);
	return str;
}