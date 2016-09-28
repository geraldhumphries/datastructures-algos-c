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
    return *list;
}

void destroy_linked_list(linked_list *list) {
    int size = list->size;
    for (int i = 0; i < size; i++) {
        linked_list_remove_first(list);
    }
    free(list->header);
    free(list->trailer);
    free(list);
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

void linked_list_add(linked_list *list, linked_list_node *node_to_add) {
    linked_list_add_last(list, node_to_add);
}

void linked_list_add_first(linked_list *list, linked_list_node *node_to_add) {
    linked_list_add_after(list, node_to_add, list->header);
}

void linked_list_add_last(linked_list *list, linked_list_node *node_to_add) {
    linked_list_add_after(list, node_to_add, list->trailer->previous_node);
}

void linked_list_add_at(linked_list *list, linked_list_node *node_to_add, int index) {
    linked_list_node *node = get(*list, index);
    linked_list_add_after(list, node_to_add, node);
}

void linked_list_add_after(linked_list *list, linked_list_node *node_to_add, linked_list_node *after_node) {
    node_to_add->previous_node = after_node;
    node_to_add->next_node = after_node->next_node;
    after_node->next_node->previous_node = node_to_add;
    after_node->next_node = node_to_add;
    list->size++;
}

void linked_list_remove_first(linked_list *list) {
    linked_list_remove_at(list, 0);
}

void linked_list_remove_last(linked_list *list) {
    linked_list_remove_at(list, list->size - 1);
}

void linked_list_remove_at(linked_list *list, int index) {
    linked_list_node *node_to_remove = get(*list, index);
    linked_list_remove(list, node_to_remove);
}

void linked_list_remove(linked_list *list, linked_list_node *node_to_remove) {
    node_to_remove->next_node->previous_node = node_to_remove->previous_node;
    node_to_remove->previous_node->next_node = node_to_remove->next_node;
    node_to_remove->previous_node = NULL;
    node_to_remove->next_node = NULL;
    list->size--;
}