#ifndef DATASTRUCTURES_ALGOS_C_DEQUE_H
#define DATASTRUCTURES_ALGOS_C_DEQUE_H

struct deque_node {
    char *val;
    struct deque_node *next_node;
    struct deque_node *previous_node;
};

typedef struct deque_node deque_node;

typedef struct {
    deque_node *head;
    deque_node *tail;
    int size;
} deque;

#endif //DATASTRUCTURES_ALGOS_C_DEQUE_H
