#ifndef DATASTRUCTURES_ALGOS_C_BINARY_SEARCH_TREE_UTIL_H
#define DATASTRUCTURES_ALGOS_C_BINARY_SEARCH_TREE_UTIL_H

#include "../binary-tree/binary-tree.h"

binary_tree_node *bst_search(binary_tree *tree, int value);
void bst_add(binary_tree *tree, binary_tree_node *node);
binary_tree_node *bst_remove(binary_tree *tree, binary_tree_node *node);

#endif //DATASTRUCTURES_ALGOS_C_BINARY_SEARCH_TREE_UTIL_H
