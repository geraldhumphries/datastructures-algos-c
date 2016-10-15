#include <stdio.h>
#include "insert/insert.h"
#include "linked-list/linked-list.h"
#include "linked-list/linked-list-util.h"
#include "circle-list/circle-list.h"
#include "circle-list/circle-list-util.h"
#include "stack/stack.h"
#include "stack/stack-util.h"
#include "queue/queue.h"
#include "queue/queue_util.h"
#include "deque/deque.h"
#include "deque/deque_util.h"
#include "array-list/array-list.h"
#include "array-list/array-list-util.h"
#include "binary-tree/binary-tree.h"
#include "binary-tree/binary-tree-util.h"

void test_linked_list() {
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
}

void test_circle_list() {
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
}

void test_stack() {
    stack stack = init_stack();
    
    stack_node stack_node1;
    stack_node stack_node2;
    stack_node stack_node3;
    stack_node1.val = "node 1";
    stack_node2.val = "node 2";
    stack_node3.val = "node 3";

    stack_push(&stack, &stack_node1);
    while (stack.size) {
        printf("stack value: %s\n", stack_pop(&stack)->val);
    }

    stack_push(&stack, &stack_node1);
    stack_push(&stack, &stack_node2);
    while (stack.size) {
        printf("stack value: %s\n", stack_pop(&stack)->val);
    }

    stack_push(&stack, &stack_node1);
    stack_push(&stack, &stack_node2);
    printf("stack value: %s\n", stack_pop(&stack)->val);
    stack_push(&stack, &stack_node3);
    printf("stack value: %s\n", stack_pop(&stack)->val);
    printf("stack value: %s\n", stack_pop(&stack)->val);

    destroy_stack(&stack);
}

void test_queue() {
    queue q = init_queue();

    queue_node queue_node1;
    queue_node queue_node2;
    queue_node queue_node3;
    queue_node1.val = "node 1";
    queue_node2.val = "node 2";
    queue_node3.val = "node 3";

    queue_enqueue(&q, &queue_node1);
    while (q.size) {
        printf("queue value: %s\n", queue_dequeue(&q)->val);
    }

    queue_enqueue(&q, &queue_node1);
    queue_enqueue(&q, &queue_node2);
    while (q.size) {
        printf("queue value: %s\n", queue_dequeue(&q)->val);
    }

    queue_enqueue(&q, &queue_node1);
    queue_enqueue(&q, &queue_node3);
    printf("queue value: %s\n", queue_dequeue(&q)->val);

    queue_enqueue(&q, &queue_node2);
    printf("queue value: %s\n", queue_dequeue(&q)->val);
    printf("queue value: %s\n", queue_dequeue(&q)->val);

    destroy_queue(&q);
}

void test_deque() {
    deque d = init_deque();

    deque_node deque_node1;
    deque_node deque_node2;
    deque_node deque_node3;
    deque_node1.val = "node 1";
    deque_node2.val = "node 2";
    deque_node3.val = "node 3";

    deque_insert_last(&d, &deque_node1);

    while (d.size) {
        printf("deque value: %s\n", deque_remove_first(&d)->val);
    }

    deque_insert_last(&d, &deque_node1);
    deque_insert_last(&d, &deque_node2);
    deque_insert_last(&d, &deque_node3);

    while (d.size) {
        printf("deque value: %s\n", deque_remove_first(&d)->val);
    }

    deque_insert_first(&d, &deque_node1);
    deque_insert_first(&d, &deque_node2);
    deque_insert_first(&d, &deque_node3);

    while (d.size) {
        printf("deque value: %s\n", deque_remove_first(&d)->val);
    }

    deque_insert_last(&d, &deque_node1);
    deque_insert_last(&d, &deque_node2);
    deque_insert_last(&d, &deque_node3);

    while (d.size) {
        printf("deque value: %s\n", deque_remove_last(&d)->val);
    }


    destroy_deque(&d);
}

void test_array_list() {
    array_list list = init_array_list();

    for (int i = 0; i < 4; i++) {
        array_list_add(&list, i, i * 2);
        printf("array list capacity = %i, size = %i\n", list.capacity, list.size);
    }

    for (int i = 0; i < list.size; i++) {
        printf("array list value: position = %i, value = %i\n", i, array_list_get(&list, i));
    }

    destroy_array_list(&list);
    list = init_array_list();

    for (int i = 0; i < 100; i++) {
        array_list_add(&list, i, i * 2);
        printf("array list capacity = %i, size = %i\n", list.capacity, list.size);
    }

    for (int i = 0; i < list.size; i++) {
        printf("array list value: position = %i, value = %i\n", i, array_list_get(&list, i));
    }

    for (int i = 0; i < 50; i++) {
        array_list_remove(&list, 0);
        printf("array list capacity = %i, size = %i\n", list.capacity, list.size);
        printf("array list value: position = %i, value = %i\n", 0, array_list_get(&list, 0));
    }


    for (int i = 0; i < 50; i++) {
        array_list_set(&list, i, i);
        printf("array list capacity = %i, size = %i\n", list.capacity, list.size);
        printf("array list value: position = %i, value = %i\n", i, array_list_get(&list, i));
    }

    destroy_array_list(&list);
}

void test_binary_tree() {
    binary_tree tree = init_binary_tree();
    binary_tree_node node1;
    memset(&node1, 0, sizeof(binary_tree_node));
    node1.val = 1;
    binary_tree_node node2;
    memset(&node2, 0, sizeof(binary_tree_node));
    node2.val = 2;
    binary_tree_node node3;
    memset(&node3, 0, sizeof(binary_tree_node));
    node3.val = 3;
    binary_tree_node node4;
    memset(&node4, 0, sizeof(binary_tree_node));
    node4.val = 4;

    binary_tree_add_root(&tree, &node1);
    binary_tree_insert_left(&tree, &node1, &node2);
    binary_tree_insert_right(&tree, &node1, &node3);
    binary_tree_insert_left(&tree, &node2, &node4);

    printf("height of node1: %i\n", binary_tree_height(&tree, &node1));
    printf("height of node2: %i\n", binary_tree_height(&tree, &node2));
    printf("height of node3: %i\n", binary_tree_height(&tree, &node3));
    printf("height of node4: %i\n", binary_tree_height(&tree, &node4));

    printf("depth of node1: %i\n", binary_tree_depth(&tree, &node1));
    printf("depth of node2: %i\n", binary_tree_depth(&tree, &node2));
    printf("depth of node3: %i\n", binary_tree_depth(&tree, &node3));
    printf("depth of node4: %i\n", binary_tree_depth(&tree, &node4));

    binary_tree_remove(&tree, &node2);
    binary_tree_remove(&tree, &node4);
    binary_tree_remove(&tree, &node3);
    binary_tree_remove(&tree, &node1);
    
    binary_tree_node node5;
    memset(&node5, 0, sizeof(binary_tree_node));
    node5.val = 5;
    binary_tree_node node6;
    memset(&node6, 0, sizeof(binary_tree_node));
    node6.val = 6;
    binary_tree_node node7;
    memset(&node7, 0, sizeof(binary_tree_node));
    node7.val = 7;

    binary_tree_add_root(&tree, &node1);
    binary_tree_insert_left(&tree, &node1, &node2);
    binary_tree_insert_right(&tree, &node1, &node3);
    binary_tree_insert_left(&tree, &node2, &node4);
    binary_tree_insert_right(&tree, &node2, &node5);
    binary_tree_insert_left(&tree, &node3, &node6);
    binary_tree_insert_right(&tree, &node3, &node7);

    int preorder_list[tree.size];
    binary_tree_preorder(&tree, preorder_list);
    for (int i = 0; i < tree.size; i++) {
        printf("preorder traversal position %i: %i\n", i, preorder_list[i]);
    }

    int postorder_list[tree.size];
    binary_tree_postorder(&tree, postorder_list);
    for (int i = 0; i < tree.size; i++) {
        printf("postorder traversal position %i: %i\n", i, postorder_list[i]);
    }

    destroy_binary_tree(&tree);
}

int main(void) {
    // array insertion
    build_game_entries_and_insert();
    
    test_linked_list();
    test_circle_list();
    test_stack();
    test_queue();
    test_deque();
    test_array_list();
    test_binary_tree();

    return 0;
}
