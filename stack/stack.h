#ifndef DATASTRUCTURES_ALGOS_C_STACK_H
#define DATASTRUCTURES_ALGOS_C_STACK_H

struct stack_node {
    char *val;
    struct stack_node *next_node;
};

typedef struct stack_node stack_node;

typedef struct {
    stack_node *head;
    int size;
} stack;

#endif //DATASTRUCTURES_ALGOS_C_STACK_H
