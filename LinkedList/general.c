#include <stdio.h>
#include <stdlib.h>

#include "./linkedlist.h"

/****** Initialisation ******/

nodeT *new_node(int value, nodeT *prev, nodeT *next)
{
	nodeT *new = malloc(sizeof(nodeT));
	new->value = value;
	new->prev = prev;
	new->next = next;
	return new;
}

linkedlistT *new_linkedlist(void)
{
	linkedlistT *list = malloc(sizeof(linkedlistT));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}

/**
 * Get Methods
 */
nodeT *getL(linkedlistT *lst) { return lst->head; }

nodeT *getR(linkedlistT *lst) { return lst->tail; }

nodeT *getI(linkedlistT *lst, int idx)
{
	if (idx < 0)
		idx = lst->size + idx;
	if (idx >= lst->size || idx < 0)
		return NULL;

	if (idx == 0 || idx == -lst->size)
		return getL(lst);
	if (idx == -1 || idx == lst->size - 1)
		return getR(lst);

	nodeT *cur;
	if (idx < lst->size / 2)
	{
		cur = lst->head;
		for (int i = 0; i < idx; i++)
			cur = cur->next;
	}
	else
	{
		cur = lst->tail;
		for (int i = lst->size - 1; i > idx; i--)
			cur = cur->prev;
	}
	return cur;
}

/**
 * Push methods
 */
nodeT *pushL(linkedlistT *lst, int value)
{
	nodeT *new = new_node(value, NULL, lst->head);
	lst->size++;
	lst->head = new;
	if (lst->size == 1)
		lst->tail = new;
	else
		new->next->prev = new;
	return new;
}

nodeT *pushR(linkedlistT *lst, int value)
{
	nodeT *new = new_node(value, lst->tail, NULL);
	lst->size++;
	lst->tail = new;
	if (lst->size == 1)
		lst->head = new;
	else
		new->prev->next = new;
	return new;
}

nodeT *pushI(linkedlistT *lst, int idx, int value)
{
	if (idx == 0 || idx == -lst->size)
		return pushL(lst, value);
	if (idx == -1 || idx == lst->size - 1)
		return pushR(lst, value);
	nodeT *tmp = getI(lst, idx);
	nodeT *new = new_node(value, tmp->prev, tmp);
	tmp->prev->next = new;
	tmp->prev = new;
	lst->size++;
	return NULL;
}

/**
 * Pop methods
 */
nodeT *popL(linkedlistT *lst)
{
	if (lst->size == 0)
		return NULL;
	nodeT *tmp = lst->head;
	lst->head = tmp->next;
	if (lst->head != NULL)
		lst->head->prev = NULL;
	if (lst->size <= 2)
		lst->tail = tmp->next;
	lst->size--;
	return tmp;
}

nodeT *popR(linkedlistT *lst)
{
	if (lst->size == 0)
		return NULL;
	nodeT *tmp = lst->tail;
	lst->tail = tmp->prev;
	if (lst->tail != NULL)
		lst->tail->next = NULL;
	if (lst->size <= 2)
		lst->head = tmp->prev;
	lst->size--;
	return tmp;
}

nodeT *popI(linkedlistT *lst, int idx)
{
	if (idx == 0 || idx == -lst->size)
		return popL(lst);
	if (idx == -1 || idx == lst->size - 1)
		return popR(lst);

	nodeT *tmp = getI(lst, idx);
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	lst->size--;
	return tmp;
}
