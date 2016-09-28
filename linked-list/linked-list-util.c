//
// Created by ghumphries on 9/14/2016.
//

#include <stdlib.h>
#include "linked-list-util.h"
#include "linked-list.h"

linked_list init_linked_list() {
    linked_list *list = (linked_list *) malloc(sizeof(linked_list));
    linked_list_node *first_node = (linked_list_node *) malloc(sizeof(linked_list_node));
    linked_list_node *last_node = (linked_list_node *) malloc(sizeof(linked_list_node));
    list->size = 0;
    first_node->val = "header";
    last_node->val = "trailer";
    first_node->next_node = last_node;
    last_node->previous_node = first_node;
    list->header = first_node;
    list->trailer = last_node;

    linked_list_node *node1 = (linked_list_node *) malloc(sizeof(linked_list_node));
    linked_list_node *node2 = (linked_list_node *) malloc(sizeof(linked_list_node));
    node1->val = "node1";
    node2->val = "node2";

    add(list, node1);
    add(list, node2);
    return *list;
}

linked_list_node *get(linked_list list, int index) {
    linked_list_node *cursor_node;
    if (list.size == 0 || index < 0 || index + 1 > list.size) {
        return NULL;
    }
    if (index < (list.size >> 1)) {
        cursor_node = list.header;
        for (int i = 0; i <= index; i++) {
            cursor_node = cursor_node->next_node;
        }
    } else {
        cursor_node = list.trailer;
        for (int i = list.size; i > index; i--) {
            cursor_node = cursor_node->previous_node;
        }
    }
    return cursor_node;
}

void add(linked_list *list, linked_list_node *node_to_add) {
    add_last(list, node_to_add);
}

void add_first(linked_list *list, linked_list_node *node_to_add) {
    add_after(list, node_to_add, list->header);
}

void add_last(linked_list *list, linked_list_node *node_to_add) {
    add_after(list, node_to_add, list->trailer->previous_node);
}

void add_at(linked_list *list, linked_list_node *node_to_add, int index) {
    linked_list_node *node = get(*list, index);
    add_after(list, node_to_add, node);
}

void add_after(linked_list *list, linked_list_node *node_to_add, linked_list_node *after_node) {
    node_to_add->previous_node = after_node;
    node_to_add->next_node = after_node->next_node;
    after_node->next_node->previous_node = node_to_add;
    after_node->next_node = node_to_add;
    list->size++;
}