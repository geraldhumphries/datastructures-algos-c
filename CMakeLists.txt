cmake_minimum_required(VERSION 3.6)
project(datastructures-algos-c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11 ")

set(SOURCE_FILES main.c insert/insert.c insert/insert.h insert/game_entry.h linked-list/linked-list.h
        linked-list/linked-list-util.c linked-list/linked-list-util.h circle-list/circle-list.h
        circle-list/circle-list-util.c circle-list/circle-list-util.h stack/stack-util.c stack/stack-util.h
        stack/stack.h queue/queue_util.c queue/queue_util.h queue/queue.h deque/deque_util.c deque/deque_util.h
        deque/deque.h array-list/array-list.h array-list/array-list-util.c array-list/array-list-util.h
        binary-tree/binary-tree-util.c binary-tree/binary-tree-util.h binary-tree/binary-tree.h binary-search-tree/binary-search-tree-util.c binary-search-tree/binary-search-tree-util.h heap/heap.h heap/heap-util.c heap/heap-util.h)
add_executable(datastructures-algos-c ${SOURCE_FILES})