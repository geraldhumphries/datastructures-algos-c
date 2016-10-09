#ifndef DATASTRUCTURES_ALGOS_C_ARRAY_LIST_UTIL_H
#define DATASTRUCTURES_ALGOS_C_ARRAY_LIST_UTIL_H

#include "array-list.h"

array_list init_array_list();
void destroy_array_list(array_list *list);
void array_list_add(array_list *list, int index, int val);
int array_list_get(array_list *list, int index);
void array_list_remove(array_list *list, int index);
void array_list_set(array_list *list, int index, int val);

#endif //DATASTRUCTURES_ALGOS_C_ARRAY_LIST_UTIL_H
