#include <stdlib.h>
#include <stdio.h>

#include "./linkedlist.h"

int add(int x) { return x * x; }
int sum(int acc, int b) { return acc + b; }
int mul(int i, int x) { return i * x; }

int main(int argc, char const *argv[])
{

	linkedlistT *lst = new_linkedlist();

	pushR(lst, 0);
	pushR(lst, 1);
	pushR(lst, 2);
	pushR(lst, 3);
	pushR(lst, 4);
	pushR(lst, 5);
	pushR(lst, 6);
	pushR(lst, 7);
	pushR(lst, 8);
	print_list(lst);

	map(lst, add);
	print_list(lst);
	printf("Res: %d\n", foldR(lst, sum, 0));

	mapI(lst, mul);
	print_list(lst);
	return 0;
}
