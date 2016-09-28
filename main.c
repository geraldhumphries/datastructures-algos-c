#include <stdio.h>
#include "insert/insert.h"
#include "linked-list/linked-list.h"
#include "linked-list/linked-list-util.h"

int main(void) {
    // array insertion
    build_game_entries_and_insert();

    // linked list
    linked_list linked_list = init_linked_list();

    linked_list_node node1;
    linked_list_node node2;
    node1.val = "node1";
    node2.val = "node2";

    linked_list_add(&linked_list, &node1);
    linked_list_add(&linked_list, &node2);
    for (int i = 0; i < linked_list.size; i++) {
        linked_list_node *node = get(linked_list, i);
        printf("node %i val: %s\n", i, node->val);
    }
    linked_list_remove_first(&linked_list);
    for (int i = 0; i < linked_list.size; i++) {
        linked_list_node *node = get(linked_list, i);
        printf("node %i val: %s\n", i, node->val);
    }
    destroy_linked_list(&linked_list);

    return 0;
}