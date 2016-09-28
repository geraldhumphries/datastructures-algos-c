cmake_minimum_required(VERSION 3.6)
project(ds-and-algo-c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11 ")

set(SOURCE_FILES main.c insert/insert.c insert/insert.h insert/game_entry.h linked-list/linked-list.h linked-list/linked-list-util.c linked-list/linked-list-util.h
        circle-linked-list/circle-linked-list.h circle-linked-list/circle-linked-list-util.c circle-linked-list/circle-linked-list-util.h)
add_executable(ds-and-algo-c ${SOURCE_FILES})