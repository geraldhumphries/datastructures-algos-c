#ifndef DATASTRUCTURES_ALGOS_C_CIRCLE_LIST_H
#define DATASTRUCTURES_ALGOS_C_CIRCLE_LIST_H

struct circle_list_node {
    char *val;
    struct circle_list_node *next_node;
    struct circle_list_node *previous_node;
};

typedef struct circle_list_node circle_list_node;

typedef struct {
    circle_list_node *cursor_node;
    int size;
} circle_list;

#endif //DATASTRUCTURES_ALGOS_C_CIRCLE_LIST_H
