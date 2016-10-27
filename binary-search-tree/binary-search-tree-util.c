#include <stdlib.h>
#include "binary-search-tree-util.h"
#include "../binary-tree/binary-tree.h"

binary_tree_node *search_traverse(binary_tree_node *node, int value) {
    if (!node) {
        return NULL;
    } else if (node->val == value) {
        return node;
    } else if (node->val > value) {
        return search_traverse(node->left_child, value);
    } else if (node->val < value) {
        return search_traverse(node->right_child, value);
    }
}

binary_tree_node *binary_search_tree_search(binary_tree *tree, int value) {
    return search_traverse(tree->root, value);
}