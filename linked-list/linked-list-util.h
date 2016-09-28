#ifndef DATASTRUCTURES_ALGOS_C_LINKED_LIST_UTIL_H
#define DATASTRUCTURES_ALGOS_C_LINKED_LIST_UTIL_H

#include "linked-list.h"

linked_list init_linked_list();
void destroy_linked_list(linked_list *list);
linked_list_node *linked_list_get(linked_list list, int index);
void linked_list_add(linked_list *list, linked_list_node *node_to_add);
void linked_list_add_first(linked_list *list, linked_list_node *node_to_add);
void linked_list_add_last(linked_list *list, linked_list_node *node_to_add);
void linked_list_add_at(linked_list *list, linked_list_node *node_to_add, int index);
void linked_list_add_after(linked_list *list, linked_list_node *node_to_add, linked_list_node *after_node);
void linked_list_remove_first(linked_list *list);
void linked_list_remove_last(linked_list *list);
void linked_list_remove_at(linked_list *list, int index);
void linked_list_remove(linked_list *list, linked_list_node *node_to_remove);


#endif //DATASTRUCTURES_ALGOS_C_LINKED_LIST_UTIL_H
