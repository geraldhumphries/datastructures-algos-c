#ifndef DATASTRUCTURES_ALGOS_C_BINARY_TREE_UTIL_H
#define DATASTRUCTURES_ALGOS_C_BINARY_TREE_UTIL_H

#include "binary-tree.h"

binary_tree init_binary_tree();

void destroy_binary_tree(binary_tree *tree);

int binary_tree_node_is_internal(binary_tree_node *node);

int binary_tree_node_is_external(binary_tree_node *node);

int binary_tree_node_is_root(binary_tree *tree, binary_tree_node *node);

void binary_tree_replace_node(binary_tree *tree, binary_tree_node *node, binary_tree_node *new_node);

int binary_tree_depth(binary_tree *tree, binary_tree_node *node);

int binary_tree_height(binary_tree *tree, binary_tree_node *node);

void binary_tree_add_root(binary_tree *tree, binary_tree_node *node);

void binary_tree_insert_left(binary_tree *tree, binary_tree_node *parent, binary_tree_node *node);

void binary_tree_insert_right(binary_tree *tree, binary_tree_node *parent, binary_tree_node *node);

int binary_tree_node_is_right(binary_tree_node *node);

int binary_tree_node_is_left(binary_tree_node *node);

void binary_tree_remove(binary_tree *tree, binary_tree_node *node);

void binary_tree_preorder(binary_tree *tree, int *list);

void binary_tree_postorder(binary_tree *tree, int *list);

void binary_tree_inorder(binary_tree *tree, int *list);

void binary_tree_invert(binary_tree *tree);

#endif //DATASTRUCTURES_ALGOS_C_BINARY_TREE_UTIL_H
