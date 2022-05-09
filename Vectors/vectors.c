#include <stdlib.h>
#include <stdio.h>

#include "./vectors.h"

struct ivector *new_ivector() {
	int * vec = malloc(sizeof(int) * INITIAL_SIZE);
	struct ivector * ivec = malloc(sizeof(struct ivector));

	ivec->vec = vec;
	ivec->len = 0;
	ivec->cursor = 0;
	ivec->__size = INITIAL_SIZE;

	return ivec;
}

void push(struct ivector * ivec, int value) {
	//TODO
	ivec->vec[ivec->cursor++] = value;
	ivec->len++;
}

void print_ivector(struct ivector *ivec) {
	//TODO
	printf("Ivector( ");
	for (size_t i = 0; i < ivec->len; i++) {
		printf("%d - ", ivec->vec[i]);
	}
	printf(")\n");
}