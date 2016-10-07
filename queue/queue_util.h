#ifndef DATASTRUCTURES_ALGOS_C_QUEUE_UTIL_H
#define DATASTRUCTURES_ALGOS_C_QUEUE_UTIL_H

#include "queue.h"

queue init_queue();
void destroy_queue(queue *q);
void enqueue(queue *q, queue_node *node);
queue_node *dequeue(queue *q);
int is_empty(queue *q);

#endif //DATASTRUCTURES_ALGOS_C_QUEUE_UTIL_H
