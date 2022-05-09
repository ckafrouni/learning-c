#include <stdlib.h>
#include <stdio.h>

#include "./vectors.h"


int main(void) {
	struct ivector * ivec = new_ivector();

	push(ivec, 3);
	push(ivec, 5);
	push(ivec, 10);
	push(ivec, 3);
	push(ivec, 5);
	push(ivec, 10);
	push(ivec, 3);
	push(ivec, 5);
	push(ivec, 10);
	push(ivec, 3);
	push(ivec, 5);
	push(ivec, 10);
	push(ivec, 10);
	push(ivec, 10);
	push(ivec, 10);

	print_ivector(ivec);
	
	return 0;
}