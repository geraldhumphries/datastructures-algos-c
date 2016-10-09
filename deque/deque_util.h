#ifndef DATASTRUCTURES_ALGOS_C_DEQUE_UTIL_H
#define DATASTRUCTURES_ALGOS_C_DEQUE_UTIL_H

#include "deque.h"

deque init_deque();
void destroy_deque(deque *d);
void deque_insert_first(deque *d, deque_node *node);
void deque_insert_last(deque *d, deque_node *node);
deque_node *deque_remove_first(deque *d);
deque_node *deque_remove_last(deque *d);
int deque_is_empty(deque *d);

#endif //DATASTRUCTURES_ALGOS_C_DEQUE_UTIL_H
