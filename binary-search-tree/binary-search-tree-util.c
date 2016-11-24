#include <stdlib.h>
#include <mem.h>
#include "binary-search-tree-util.h"
#include "../binary-tree/binary-tree-util.h"
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
    return NULL;
}

binary_tree_node *bst_search(binary_tree *tree, int value) {
    return search_traverse(tree->root, value);
}

binary_tree_node *search_traverse_nearest(binary_tree_node *node, int value) {
    if (node->val == value
        || node->val > value && !node->left_child
        || node->val < value && !node->right_child) {
        return node;
    } else if (node->val > value && node->left_child) {
        return search_traverse_nearest(node->left_child, value);
    } else if (node->val < value && node->right_child) {
        return search_traverse_nearest(node->right_child, value);
    }
    return NULL;
}

void bst_add(binary_tree *tree, binary_tree_node *node) {
    if (!tree->root) {
        binary_tree_add_root(tree, node);
        return;
    }
    binary_tree_node *found_node = search_traverse_nearest(tree->root, node->val);
    if (node->val < found_node->val) {
        binary_tree_insert_left(tree, found_node, node);
    } else {
        binary_tree_insert_right(tree, found_node, node);
    }
}

void replace_child(binary_tree_node *parent, binary_tree_node *child, binary_tree_node *replacement) {
    if (parent->right_child == child) {
        parent->right_child = replacement;
    } else {
        parent->left_child = replacement;
    }
}

binary_tree_node *external_remove(binary_tree *tree, binary_tree_node *node) {
    binary_tree_node *replacement = NULL;
    if (node->left_child) {
        replacement = node->left_child;
    } else if (node->right_child) {
        replacement = node->right_child;
    }
    if (replacement) {
        replacement->parent = node->parent;
    }
    return replacement;
}

binary_tree_node *internal_remove(binary_tree *tree, binary_tree_node *node) {
    binary_tree_node *replacement = node->right_child;
    while (replacement->left_child) {
        replacement = replacement->left_child;
    }

    if (replacement->right_child) {
        replacement->right_child->parent = replacement->parent;
        if (tree->root == replacement) {
            tree->root = replacement->right_child;
        }
    }

    replacement->left_child = node->left_child;
    replacement->left_child->parent = replacement;

    // if the replacement node's parent is the node we are trying to remove, that means the replacement node is the right child
    // it can't be the left child because we'd be at least one more level down
    // don't modify replacement's parent and right_child, or we'll end up with circular references
    if (replacement->parent != node) {
        replacement->parent->left_child = replacement->right_child;
        replacement->right_child = node->right_child;
        replacement->right_child->parent = replacement;
    }
    replacement->parent = node->parent;
    return replacement;
}

binary_tree_node *bst_remove(binary_tree *tree, binary_tree_node *node) {
    binary_tree_node *replacement;
    if (node->left_child && node->right_child) {
        replacement = internal_remove(tree, node);
    } else {
        replacement = external_remove(tree, node);
    }
    if (tree->root == node) {
        tree->root = replacement;
    } else {
        replace_child(node->parent, node, replacement);
    }
    tree->size--;
    return node;
}