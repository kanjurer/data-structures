#ifndef DSA_QUEUE
#define DSA_QUEUE

#include <corecrt.h>

typedef struct {
    int size;
    void *data;
    size_t type_size;
    const char *type_name;
    int max_size;

} Queue;

int queue_initialize(Queue *, size_t, const char *);

int queue_push(Queue *, void *);

int queue_pop(Queue *, void *);

int queue_peek(Queue *, void *);

void queue_clear(Queue *);

int queue_size(Queue *);

int queue_is_empty(Queue *);

void queue_destroy(Queue *);

static void resize(Queue *);

#endif