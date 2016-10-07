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

    enqueue(&q, &queue_node1);
    while (q.size) {
        printf("queue value: %s\n", dequeue(&q)->val);
    }

    enqueue(&q, &queue_node1);
    enqueue(&q, &queue_node2);
    while (q.size) {
        printf("queue value: %s\n", dequeue(&q)->val);
    }

    enqueue(&q, &queue_node1);
    enqueue(&q, &queue_node3);
    printf("queue value: %s\n", dequeue(&q)->val);

    enqueue(&q, &queue_node2);
    printf("queue value: %s\n", dequeue(&q)->val);
    printf("queue value: %s\n", dequeue(&q)->val);
}

int main(void) {
    // array insertion
    build_game_entries_and_insert();
    
    test_linked_list();
    test_circle_list();
    test_stack();
    test_queue();

    return 0;
}
