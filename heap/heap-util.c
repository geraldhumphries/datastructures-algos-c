#include <stdlib.h>
#include "heap-util.h"
#include "heap.h"
#include "../array-list/array-list-util.h"

void up_heap(array_list *heap, int position) {
    if (position == 0) {
        return;
    }
    int curr_val = array_list_get(heap, position);
    int parent_position = (position - 1) >> 1;
    int parent_val = array_list_get(heap, parent_position);

    if (curr_val < parent_val) {
        // swap
        array_list_set(heap, parent_position, curr_val);
        array_list_set(heap, position, parent_val);
        up_heap(heap, parent_position);
    }
}

void heap_add(array_list *heap, int value) {
    array_list_add(heap, heap->size, value);
    up_heap(heap, heap->size - 1);
}

void down_heap(array_list *heap, int position) {
    if (position == heap->size - 1) {
        return;
    }
    int curr_val = array_list_get(heap, position);
    int child_position = (position << 1) + 2;
    if (child_position >= heap->size) {
        child_position--;
    }
    int child_val = array_list_get(heap, child_position);

    if (curr_val > child_val) {
        // swap
        array_list_set(heap, child_position, curr_val);
        array_list_set(heap, position, child_val);
        down_heap(heap, child_position);
    }
}


int heap_remove(array_list *heap) {
    int result = array_list_get(heap, 0);
    array_list_set(heap, 0, array_list_get(heap, heap->size - 1));
    array_list_remove(heap, heap->size - 1);
    down_heap(heap, 0);
    return result;
}