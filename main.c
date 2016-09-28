#include <stdio.h>
#include "insert/insert.h"
#include "linked-list/linked-list.h"
#include "linked-list/linked-list-util.h"

int main(void) {
    // array insertion
    build_game_entries_and_insert();

    // linked list
    linked_list linked_list = init_linked_list();
    for (int i = 0; i < linked_list.size; i++) {
        linked_list_node *node = get(linked_list, i);
        printf("node %i val: %s\n", i, node->val);
    }

    return 0;
}