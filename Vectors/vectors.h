#if !defined(VECTORS)
#define VECTORS

#define INITIAL_SIZE 5

typedef struct
{
	int *array;
	size_t len;
	size_t cursor;
	size_t __size; // total size of vector
} Vector;

Vector vecCreate(void);

void vecPush(Vector *vec, int value);

void vecPrint(Vector *vec);

#endif // VECTORS
