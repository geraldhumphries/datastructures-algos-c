#include <stdlib.h>
#include "array-list-util.h"
#include "array-list.h"

array_list init_array_list() {
    array_list *list = (array_list *) malloc(sizeof(array_list));
    int *array = malloc(sizeof(int) * 1);
    list->capacity = 1;
    list->size = 0;
    list->val = array;
    return *list;
}
void destroy_array_list(array_list *list) {
    free(list->val);
    free(list);
}
void array_list_add(array_list *list, int index, int val) {
    if (list->size == list->capacity) {
        int *new_val = malloc(sizeof(int) * list->capacity * 2);
        for (int i = 0; i < list->capacity; i++) {
            if (i < index) {
                new_val[i] = list->val[i];
            } else {
                new_val[i + 1] = list->val[i + 1];
            }
        }
        free(list->val);
        list->val = new_val;
        list->capacity *= 2;
    } else {
        for (int i = list->size; i > index; i--) {
            list->val[i] = list->val[i - 1];
        }
    }
    list->val[index] = val;
    list->size++;
}
int array_list_get(array_list *list, int index) {
    if (index >= list->size) {
        return NULL;
    }

    return list->val[index];
}
void array_list_remove(array_list *list, int index) {
    for (int i = index; i < list->size; i++) {
        list->val[i] = list->val[i+1];
    }
    list->size--;
}
void array_list_set(array_list *list, int index, int val) {
    if (index < list->size) {
        list->val[index] = val;
    }
}