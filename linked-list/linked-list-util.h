//
// Created by ghumphries on 9/14/2016.
//

#ifndef DS_AND_ALGO_C_LINKED_LIST_UTIL_H
#define DS_AND_ALGO_C_LINKED_LIST_UTIL_H

#include "linked-list.h"

linked_list init_linked_list();
linked_list_node *get(linked_list list, int index);
void add(linked_list *list, linked_list_node *node_to_add);
void add_first(linked_list *list, linked_list_node *node_to_add);
void add_last(linked_list *list, linked_list_node *node_to_add);
void add_at(linked_list *list, linked_list_node *node_to_add, int index);
void add_after(linked_list *list, linked_list_node *node_to_add, linked_list_node *after_node);


#endif //DS_AND_ALGO_C_LINKED_LIST_UTIL_H
