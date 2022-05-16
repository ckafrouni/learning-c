#include <stdlib.h>
#include <stdio.h>

#include "./vectors.h"


int main(void) {
	Vector vec = vecCreate();

	vecPush(&vec, 3);
	vecPush(&vec, 5);
	vecPush(&vec, 10);
	vecPush(&vec, 3);
	vecPush(&vec, 5);
	vecPush(&vec, 10);
	vecPush(&vec, 3);
	vecPush(&vec, 5);
	vecPush(&vec, 10);
	vecPush(&vec, 3);
	vecPush(&vec, 5);
	vecPush(&vec, 10);
	vecPush(&vec, 10);
	vecPush(&vec, 10);
	vecPush(&vec, 10);

	vecPrint(&vec);
	
	return 0;
}