#if !defined(VECTORS)
#define VECTORS

#define INITIAL_SIZE 10

struct ivector
{
	int *vec;
	int len;
	int cursor;
	int __size; // total size of vector
};

struct ivector *new_ivector(void);

void push(struct ivector * ivec, int value);

void print_ivector(struct ivector *ivec);

#endif // VECTORS
