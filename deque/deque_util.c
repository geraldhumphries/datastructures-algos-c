#include <stdlib.h>
#include "deque_util.h"
#include "deque.h"

deque init_deque() {
    deque *d = (deque *) malloc(sizeof(deque));
    d->size = 0;
    return *d;
}
void destroy_deque(deque *d) {
    free(d);
}
void deque_insert_first(deque *d, deque_node *node) {
    if (d->size > 0) {
        node->previous_node = d->head;
        d->head->next_node = node;
    } else {
        d->tail = node;
    }
    d->head = node;
    d->size++;
}
void deque_insert_last(deque *d, deque_node *node) {
    if (d->size > 0) {
        node->next_node = d->tail;
        d->tail->previous_node = node;
    } else {
        d->head = node;
    }
    d->tail = node;
    d->size++;
}
deque_node *deque_remove_first(deque *d) {
    if (d->size == 0) {
        return NULL;
    }

    deque_node *result = d->head;
    if (d->size > 1) {
        result->previous_node->next_node = NULL;
        d->head = result->previous_node;
        result->previous_node = NULL;
    } else {
        d->head = NULL;
        d->tail = NULL;
    }
    d->size--;
    return result;
}
deque_node *deque_remove_last(deque *d) {
    if (d->size == 0) {
        return NULL;
    }

    deque_node *result = d->tail;
    if (d->size > 1) {
        result->next_node->previous_node = NULL;
        d->tail = result->next_node;
        result->next_node = NULL;
    } else {
        d->head = NULL;
        d->tail = NULL;
    }
    d->size--;
    return result;
}
int deque_is_empty(deque *d) {
    if (d->size == 0) {
        return 1;
    } else {
        return 0;
    }
}