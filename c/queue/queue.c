#include "queue.h"

#include <stdlib.h>
#include <string.h>

# define MAX_SIZE 1

int queue_initialize(Queue *s, size_t type_size, const char *type_name) {
    s->type_size = type_size;
    s->type_name = type_name;
    s->size = 0;
    s->max_size = MAX_SIZE;
    s->data = calloc(s->max_size, s->type_size);

    return 0;
}

int queue_push(Queue *s, void *el) {
    if (s == NULL) return -1;
    if (el == NULL) return -1;

    if (s->size == s->max_size) {
        resize(s);
    }

    memcpy((char *) s->data + s->size * s->type_size, el, s->type_size);
    s->size++;

    return 0;
}

int queue_pop(Queue *s, void *dst) {
    if (s == NULL) return -1;
    if (s->size == 0) return -1;

    s->size--;
    memcpy(dst, (char *) s->data + s->size * s->type_size, s->type_size);

    return 0;
}

int queue_peek(Queue *s, void *dst) {
    if (s == NULL) return -1;
    if (s->size == 0) return -1;

    memcpy(dst, (char *) s->data + (s->size - 1) * s->type_size, s->type_size);
    return 0;
}

void queue_clear(Queue *s) {
    if (s == NULL) return;
    memset(s->data, 0, s->size * s->type_size);
    s->size = 0;
}

int queue_size(Queue *s) {
    if (s == NULL) return -1;

    return s->size;
}

int queue_is_empty(Queue *s) {
    if (s == NULL) return -1;

    return s->size == 0;
}

void queue_destroy(Queue *s) {
    if (s == NULL) return;

    free(s->data);
    memset(s, 0, sizeof(Queue));
}

static void resize(Queue *s) {
    if (s == NULL) return;

    s->max_size <<= 1;
    void *tmp = realloc(s->data, s->max_size * s->type_size);
    if (tmp) {
        s->data = tmp;
    }
}