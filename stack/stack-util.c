#include <stdlib.h>
#include "stack-util.h"

stack init_stack() {
    stack *s = (stack *) malloc(sizeof(stack));
    s->size = 0;
    return *s;
}

void stack_push(stack *s, stack_node *node) {
    node->next_node = s->head;
    s->head = node;
    s->size++;
}

stack_node *stack_pop(stack *s) {
    stack_node *node = s->head;
    s->head = s->head->next_node;
    s->size--;
    node->next_node = NULL;
    return node;
}

int stack_is_empty(stack *s) {
    if (s->size == 0) {
        return 1;
    } else {
        return 0;
    }
}

void destroy_stack(stack *s) {
    free(s);
}