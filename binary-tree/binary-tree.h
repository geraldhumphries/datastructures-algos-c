#ifndef DATASTRUCTURES_ALGOS_C_BINARY_TREE_H
#define DATASTRUCTURES_ALGOS_C_BINARY_TREE_H

struct binary_tree_node {
    int val;
    struct binary_tree_node *parent;
    struct binary_tree_node *left_child;
    struct binary_tree_node *right_child;
};

typedef struct binary_tree_node binary_tree_node;

typedef struct {
    binary_tree_node *root;
    int size;
} binary_tree;

#endif //DATASTRUCTURES_ALGOS_C_BINARY_TREE_H
