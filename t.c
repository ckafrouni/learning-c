#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int x[] = {1, 2, 3, 4};

	*(x) = 10;
	*(x+1) = 20; 
	printf("%d\n", x[0]);
	printf("%d\n", x[1]);
	printf("%d\n", x[2]);
	printf("%d\n", x[3]);
	printf("%d\n", x[4]);
	printf("%d\n", x[5]);

	printf("size: %lu\n", sizeof(x));
	printf("size: %lu\n", sizeof(int));
	printf("size: %lu\n", sizeof(int *));
	printf("size: %lu\n", sizeof(char *));

	char str[] = {'h', 'e', 'l', 'l', 'o'};
	printf("string: %p\n", str);
	printf("string: %d\n", *(str+3 ));
	return 0;
}