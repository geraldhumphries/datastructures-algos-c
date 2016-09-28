#ifndef DATASTRUCTURES_ALGOS_C_LINKED_LIST_H
#define DATASTRUCTURES_ALGOS_C_LINKED_LIST_H

struct linked_list_node {
    char *val;
    struct linked_list_node *next_node;
    struct linked_list_node *previous_node;
};

typedef struct linked_list_node linked_list_node;

typedef struct {
    linked_list_node *header;
    linked_list_node *trailer;
    int size;
} linked_list;

#endif //DATASTRUCTURES_ALGOS_C_LINKED_LIST_H
