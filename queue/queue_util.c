#include <stdlib.h>
#include "queue_util.h"
#include "queue.h"

queue init_queue() {
    queue *q = (queue *) malloc(sizeof(queue));
    q->size = 0;
    return *q;
}

void destroy_queue(queue *q) {
    free(q);
}

void enqueue(queue *q, queue_node *node) {
    if (q->size == 0) {
        q->head = node;
    } else {
        q->tail->previous_node = node;
        node->next_node = q->tail;
    }
    q->tail = node;
    q->size++;
}

queue_node *dequeue(queue *q) {
    if (q->size == 0) {
        return NULL;
    }
    queue_node *result = q->head;
    if (q->size > 1) {
        q->head = result->previous_node;
        q->head->next_node = NULL;
    } else {
        q->head = NULL;
        q->tail = NULL;
    }
    q->size--;
    return result;
}
int is_empty(queue *q) {
    if (q->size == 0) {
        return 0;
    } else {
        return 1;
    }
}