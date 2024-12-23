#include "stack.h"

#include <stdlib.h>
#include <string.h>

# define MAX_SIZE 1

int stack_initialize(Stack *s, size_t type_size, const char *type_name) {
    s->type_size = type_size;
    s->type_name = type_name;
    s->size = 0;
    s->max_size = MAX_SIZE;
    s->data = calloc(s->max_size, s->type_size);

    return 0;
}

int stack_push(Stack *s, void *el) {
    if (s == NULL) return -1;
    if (el == NULL) return -1;

    if (s->size == s->max_size) {
        resize(s);
    }

    memcpy((char *) s->data + s->size * s->type_size, el, s->type_size);
    s->size++;

    return 0;
}

int stack_pop(Stack *s, void *dst) {
    if (s == NULL) return -1;
    if (s->size == 0) return -1;

    s->size--;
    memcpy(dst, (char *) s->data + s->size * s->type_size, s->type_size);

    return 0;
}

int stack_peek(Stack *s, void *dst) {
    if (s == NULL) return -1;
    if (s->size == 0) return -1;

    memcpy(dst, (char *) s->data + (s->size - 1) * s->type_size, s->type_size);
    return 0;
}

void stack_clear(Stack *s) {
    if (s == NULL) return;
    memset(s->data, 0, s->size * s->type_size);
    s->size = 0;
}

int stack_size(Stack *s) {
    if (s == NULL) return -1;

    return s->size;
}

int stack_is_empty(Stack *s) {
    if (s == NULL) return -1;

    return s->size == 0;
}

void stack_destroy(Stack *s) {
    if (s == NULL) return;

    free(s->data);
    memset(s, 0, sizeof(Stack));
}

static void resize(Stack *s) {
    if (s == NULL) return;

    s->max_size <<= 1;
    void *tmp = realloc(s->data, s->max_size * s->type_size);
    if (tmp) {
        s->data = tmp;
    }
}