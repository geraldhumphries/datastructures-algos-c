#include <stdio.h>
#include "insert/insert.h"
#include "linked-list/linked-list.h"
#include "linked-list/linked-list-util.h"
#include "circle-list/circle-list.h"
#include "circle-list/circle-list-util.h"

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
        linked_list_node *node = linked_list_get(linked_list, i);
        printf("node %i val: %s\n", i, node->val);
    }
    linked_list_remove_first(&linked_list);
    for (int i = 0; i < linked_list.size; i++) {
        linked_list_node *node = linked_list_get(linked_list, i);
        printf("node %i val: %s\n", i, node->val);
    }
    destroy_linked_list(&linked_list);

    // circular linked list
    circle_list circle_list = init_circle_list();

    circle_list_node circle_node1;
    circle_list_node circle_node2;
    circle_node1.val = "node1";
    circle_node2.val = "node2";

    circle_list_add(&circle_list, &circle_node1);
    circle_list_add(&circle_list, &circle_node2);
    for (int i = 0; i < circle_list.size; i++) {
        circle_list_node *node = circle_list_get(circle_list, i);
        printf("node %i val: %s\n", i, node->val);
    }
    circle_list_remove_first(&circle_list);
    for (int i = 0; i < circle_list.size; i++) {
        circle_list_node *node = circle_list_get(circle_list, i);
        printf("node %i val: %s\n", i, node->val);
    }
    destroy_circle_list(&circle_list);

    return 0;
}