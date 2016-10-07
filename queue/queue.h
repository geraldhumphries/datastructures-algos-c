#ifndef DATASTRUCTURES_ALGOS_C_QUEUE_H
#define DATASTRUCTURES_ALGOS_C_QUEUE_H

struct queue_node {
    char *val;
    struct queue_node *next_node;
    struct queue_node *previous_node;
};

typedef struct queue_node queue_node;

typedef struct {
    queue_node *head;
    queue_node *tail;
    int size;
} queue;

#endif //DATASTRUCTURES_ALGOS_C_QUEUE_H
