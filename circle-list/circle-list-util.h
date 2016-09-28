#ifndef DATASTRUCTURES_ALGOS_C_CIRCLE_LIST_UTIL_H
#define DATASTRUCTURES_ALGOS_C_CIRCLE_LIST_UTIL_H

#include "circle-list.h"

circle_list init_circle_list();
void destroy_circle_list(circle_list *list);
circle_list_node *circle_list_get(circle_list list, int index);
void circle_list_add(circle_list *list, circle_list_node *node_to_add);
void circle_list_add_first(circle_list *list, circle_list_node *node_to_add);
void circle_list_add_last(circle_list *list, circle_list_node *node_to_add);
void circle_list_add_at(circle_list *list, circle_list_node *node_to_add, int index);
void circle_list_add_after(circle_list *list, circle_list_node *node_to_add, circle_list_node *after_node);
void circle_list_remove_first(circle_list *list);
void circle_list_remove_last(circle_list *list);
void circle_list_remove_at(circle_list *list, int index);
void circle_list_remove(circle_list *list, circle_list_node *node_to_remove);
void circle_list_advance(circle_list *list);


#endif //DATASTRUCTURES_ALGOS_C_CIRCLE_LIST_UTIL_H
