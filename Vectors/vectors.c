#include <stdlib.h>
#include <stdio.h>

#include "./vectors.h"

Vector vecCreate(void) {
	Vector vec = {
		.array = malloc(sizeof(int) * INITIAL_SIZE),
		.cursor = 0,
		.len = 0,
		.__size = INITIAL_SIZE
	};
	return vec;
}

void vecPush(Vector* vec, int value) {
	if (vec->cursor == vec->__size) {
		vec->__size *= 2;
		vec->array = realloc(vec->array, vec->__size*sizeof(int));
	}
	vec->array[vec->cursor++] = value;
	vec->len++;
}

void vecPrint(Vector *vec) {
	printf("\033[31m[\033[m ");
	for (size_t i = 0; i < vec->len; i++) {
		printf("%d\033[31m,\033[m ", vec->array[i]);
	}
	printf("\033[31m]\033[m\n");
}