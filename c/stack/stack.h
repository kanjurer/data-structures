#ifndef DSA_STACK
#define DSA_STACK

#include <corecrt.h>

typedef struct {
    int size;
    void *data;
    size_t type_size;
    const char *type_name;
    int max_size;
} Stack;

int stack_initialize(Stack *, size_t, const char *);

int stack_push(Stack *, void *);

int stack_pop(Stack *, void *);

int stack_peek(Stack *, void *);

void stack_clear(Stack *);

int stack_size(Stack *);

int stack_is_empty(Stack *);

void stack_destroy(Stack *);

static void resize(Stack *);

#endif
