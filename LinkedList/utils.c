#include <stdlib.h>
#include <stdio.h>

#include "./linkedlist.h"

void print_list(linkedlistT *lst)
{
	printf("Linked List: %d\n\t-> ", lst->size);
	nodeT *cur = lst->head;
	while (cur != NULL)
	{
		printf("%i -> ", cur->value);
		cur = cur->next;
	}
	printf("\n");
}

void map(linkedlistT *lst, int (*fnPtr)(int))
{
	nodeT *cur = lst->head;
	while (cur != NULL)
	{
		cur->value = fnPtr(cur->value);
		cur = cur->next;
	}
}

void mapI(linkedlistT *lst, int (*fnPtr)(int idx, int))
{
	nodeT *cur = lst->head;
	int idx = 0;
	while (cur != NULL)
	{
		cur->value = fnPtr(idx, cur->value);
		cur = cur->next;
		idx++;
	}
}

int foldL(linkedlistT *lst, int (*fnPtr)(int acc, int x), int acc)
{
	nodeT *cur = lst->head;
	while (cur != NULL)
	{
		acc = fnPtr(acc, cur->value);
		cur = cur->next;
	}
	return acc;
}

int foldR(linkedlistT *lst, int (*fnPtr)(int x, int acc), int acc)
{
	nodeT *cur = lst->tail;
	while (cur != NULL)
	{
		acc = fnPtr(cur->value, acc);
		cur = cur->prev;
	}
	return acc;
}