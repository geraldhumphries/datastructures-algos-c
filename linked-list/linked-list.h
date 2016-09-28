//
// Created by ghumphries on 9/14/2016.
//

#ifndef DS_AND_ALGO_C_NODE_H
#define DS_AND_ALGO_C_NODE_H

struct linked_list_node {
    char * val;
    struct linked_list_node * next_node;
    struct linked_list_node * previous_node;
};

typedef struct linked_list_node linked_list_node;

typedef struct {
    linked_list_node * header;
    linked_list_node * trailer;
    int size;
} linked_list;

#endif //DS_AND_ALGO_C_NODE_H
