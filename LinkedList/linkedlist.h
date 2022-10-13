#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdbool.h>

// typedef struct node nodeT;
// struct node
// {
// 	int value;
// 	nodeT *next;
// 	nodeT *prev;
// };

typedef struct
{
	int value;
	nodeT *next;
	nodeT *prev;
} nodeT;

typedef struct
{
	size_t size;
	nodeT *head;
	nodeT *tail
} linkedlistT;



// typedef struct linkedlist linkedlistT;
// struct linkedlist
// {
// 	nodeT *head;
// 	nodeT *tail;
// 	int size;
// };

nodeT *new_node(int value, nodeT *prev, nodeT *next);

linkedlistT *new_linkedlist(void);

nodeT *getL(linkedlistT *lst);
nodeT *getR(linkedlistT *lst);
nodeT *getI(linkedlistT *lst, int idx);

nodeT *pushL(linkedlistT *lst, int value);
nodeT *pushR(linkedlistT *lst, int value);
nodeT *pushI(linkedlistT *lst, int idx, int value);

nodeT *popL(linkedlistT *lst);
nodeT *popR(linkedlistT *lst);
nodeT *popI(linkedlistT *lst, int idx);

void print_list(linkedlistT *lst);

void map(linkedlistT *lst, int (*fnPtr)(int));
void mapI(linkedlistT *lst, int (*fnPtr)(int idx, int));

int foldL(linkedlistT *lst, int (*fnPtr)(int acc, int), int acc);
int foldR(linkedlistT *lst, int (*fnPtr)(int, int acc), int acc);

// TODO
void filter(linkedlistT *lst, bool (*predicatePtr)(int));
void filterI(linkedlistT *lst, bool (*predicatePtr)(int idx, int));

// TODO
linkedlistT *slice(linkedlistT *lst, int start, int end);

#endif // LINKEDLIST