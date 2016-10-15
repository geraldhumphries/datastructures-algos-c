#include <stdlib.h>
#include <mem.h>
#include "binary-tree-util.h"
#include "binary-tree.h"

binary_tree init_binary_tree() {
    binary_tree *tree = (binary_tree *) malloc(sizeof(binary_tree));
    tree->size = 0;
    return *tree;
}

void destroy_binary_tree(binary_tree *tree) {
    free(tree);
}

int binary_tree_node_is_internal(binary_tree_node *node) {
    if (node->left_child || node->right_child) {
        return 1;
    }
    return 0;
}

int binary_tree_node_is_external(binary_tree_node *node) {
    if (node->left_child || node->right_child) {
        return 0;
    }
    return 1;
}

int binary_tree_node_is_root(binary_tree *tree, binary_tree_node *node) {
    if (tree->root == node) {
        return 1;
    }
    return 0;
}

void binary_tree_replace_node(binary_tree *tree, binary_tree_node *node, binary_tree_node *new_node) {
    new_node->parent = node->parent;
    new_node->left_child = node->left_child;
    new_node->right_child = node->right_child;
    if (binary_tree_node_is_root(tree, node)) {
        tree->root = new_node;
    }
}

int binary_tree_depth(binary_tree *tree, binary_tree_node *node) {
    if (binary_tree_node_is_root(tree, node)) {
        return 0;
    } else {
        return 1 + binary_tree_depth(tree, node->parent);
    }
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int binary_tree_height(binary_tree *tree, binary_tree_node *node) {
    if (!node || binary_tree_node_is_external(node)) {
        return 0;
    }
    int height = 0;
    height = max(height, binary_tree_height(tree, node->left_child));
    height = max(height, binary_tree_height(tree, node->right_child));
    return 1 + height;
}


void binary_tree_add_root(binary_tree *tree, binary_tree_node *node) {
    tree->root = node;
    tree->size++;
}

void binary_tree_insert_left(binary_tree *tree, binary_tree_node *parent, binary_tree_node *node) {
    if (parent->left_child) {
        node->left_child = parent->left_child;
        parent->left_child->parent = node;
    }
    node->parent = parent;
    parent->left_child = node;
    tree->size++;
}

void binary_tree_insert_right(binary_tree *tree, binary_tree_node *parent, binary_tree_node *node) {
    if (parent->right_child) {
        node->right_child = parent->right_child;
        parent->right_child->parent = node;
    }
    node->parent = parent;
    parent->right_child = node;
    tree->size++;
}

int binary_tree_node_is_right(binary_tree_node *node) {
    if (node->parent->right_child == node) {
        return 1;
    }
    return 0;
}

int binary_tree_node_is_left(binary_tree_node *node) {
    if (node->parent->left_child == node) {
        return 1;
    }
    return 0;
}

void binary_tree_remove(binary_tree *tree, binary_tree_node *node) {
    if (node->left_child && node->right_child) {
        return; // can't remove a node with two children
    }

    binary_tree_node *new_in_pos;
    if (node->left_child) {
        new_in_pos = node->left_child;
        new_in_pos->parent = node->parent;
    } else if (node->right_child) {
        new_in_pos = node->right_child;
        new_in_pos->parent = node->parent;
    } else {
        new_in_pos = NULL;
    }

    if (binary_tree_node_is_root(tree, node)) {
        tree->root = new_in_pos;
    } else if (binary_tree_node_is_left(node)) {
        node->parent->left_child = new_in_pos;
    } else {
        node->parent->right_child = new_in_pos;
    }
    node->parent = NULL;
    node->left_child = NULL;
    node->right_child = NULL;

    tree->size--;

}