#include <stdlib.h>
#include "circle-list-util.h"
#include "circle-list.h"

circle_list init_circle_list() {
    circle_list *list = (circle_list *) malloc(sizeof(circle_list));
    list->size = 0;
    return *list;
}

void destroy_circle_list(circle_list *list) {
    while (list->size > 0) {
        circle_list_remove_first(list);
    }
    free(list);
}

circle_list_node *circle_list_get(circle_list list, int index) {
    circle_list_node *cursor_node;
    if (list.size == 0 || index < 0 || index + 1 > list.size) {
        return NULL;
    }
    if (index < (list.size >> 1)) {
        cursor_node = list.cursor_node;
        for (int i = 0; i < index; i++) {
            cursor_node = cursor_node->next_node;
        }
    } else {
        cursor_node = list.cursor_node;
        for (int i = list.size; i > index; i--) {
            cursor_node = cursor_node->previous_node;
        }
    }
    return cursor_node;
}

void circle_list_add(circle_list *list, circle_list_node *node_to_add) {
    if (list->size > 0) {
        circle_list_add_last(list, node_to_add);
    } else {
        circle_list_add_at(list, node_to_add, 0);
    }
}

void circle_list_add_first(circle_list *list, circle_list_node *node_to_add) {
    circle_list_add_at(list, node_to_add, 0);
}

void circle_list_add_last(circle_list *list, circle_list_node *node_to_add) {
    circle_list_add_after(list, node_to_add, list->cursor_node->previous_node);
}

void circle_list_add_at(circle_list *list, circle_list_node *node_to_add, int index) {
    if (index > 0) {
        circle_list_node *node = circle_list_get(*list, index);
        circle_list_add_after(list, node_to_add, node);
    } else if (list->size == 0) {
        node_to_add->next_node = node_to_add;
        node_to_add->previous_node = node_to_add;
        list->cursor_node = node_to_add;
        list->size++;
    } else {
        node_to_add->previous_node = list->cursor_node->previous_node;
        node_to_add->next_node = list->cursor_node;
        list->cursor_node->previous_node = node_to_add;
        list->cursor_node = node_to_add;
        list->size++;
    }
}

void circle_list_add_after(circle_list *list, circle_list_node *node_to_add, circle_list_node *after_node) {
    node_to_add->previous_node = after_node;
    node_to_add->next_node = after_node->next_node;
    after_node->next_node->previous_node = node_to_add;
    after_node->next_node = node_to_add;
    list->size++;
}

void circle_list_remove_first(circle_list *list) {
    circle_list_remove_at(list, 0);
}

void circle_list_remove_last(circle_list *list) {
    circle_list_remove_at(list, list->size - 1);
}

void circle_list_remove_at(circle_list *list, int index) {
    if (index > 0) {
        circle_list_node *node_to_remove = circle_list_get(*list, index);
        circle_list_remove(list, node_to_remove);
    } else {
        list->cursor_node->next_node->previous_node = list->cursor_node->previous_node;
        list->cursor_node->previous_node->next_node = list->cursor_node->next_node;
        circle_list_node *new_cursor = list->cursor_node->next_node;
        list->cursor_node->previous_node = NULL;
        list->cursor_node->next_node = NULL;
        list->cursor_node = new_cursor;
        list->size--;
    }
}

void circle_list_remove(circle_list *list, circle_list_node *node_to_remove) {
    node_to_remove->next_node->previous_node = node_to_remove->previous_node;
    node_to_remove->previous_node->next_node = node_to_remove->next_node;
    node_to_remove->previous_node = NULL;
    node_to_remove->next_node = NULL;
    list->size--;
}

void circle_list_advance(circle_list *list) {
    list->cursor_node = list->cursor_node->next_node;
}