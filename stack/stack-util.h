#ifndef DATASTRUCTURES_ALGOS_C_STACK_UTIL_H
#define DATASTRUCTURES_ALGOS_C_STACK_UTIL_H

#include "stack.h"

stack init_stack();
void stack_push(stack *s, stack_node *node);
stack_node *stack_pop(stack *s);
int stack_is_empty(stack *s);
void destroy_stack(stack *s);

#endif //DATASTRUCTURES_ALGOS_C_STACK_UTIL_H
