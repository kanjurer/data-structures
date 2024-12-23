#include <stdio.h>
#include <stdlib.h>
#include "stack/stack.h"

int main(void) {
    printf("Hello, World!\n");

    Stack s;
    stack_initialize(&s, sizeof(int), "int");
    int tmp;

//    char *arr[] = {"Hello", "My", "Name", "Is", "Khan"};
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i) {
        stack_push(&s, arr + i);
        stack_peek(&s, &tmp);
        printf("%d\n", tmp);
    }

    while (stack_size(&s)) {
        stack_pop(&s, &tmp);
        printf("%d\n", tmp);
    }

    stack_clear(&s);
    printf("%d\n", s.size);

    int a = stack_is_empty(&s);
    printf("%d\n", a);
    stack_destroy(&s);

    return 0;
}