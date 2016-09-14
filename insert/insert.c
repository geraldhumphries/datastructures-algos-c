//
// Created by ghumphries on 9/11/2016.
//

#include "insert.h"
#include "game_entry.h"

void build_game_entries_and_insert() {
    struct game_entry entries[2];
    struct game_entry game_entry1;
    struct game_entry game_entry2;
    game_entry1.name = "test";
    game_entry1.score = 20;
    entries[0] = game_entry1;
    game_entry2.name = "test2";
    game_entry2.score = 10;
    entries[1] = game_entry2;
    struct game_entry game_entry3;
    game_entry3.name = "tes3";
    game_entry3.score = 30;

    insert(entries, sizeof(entries) / sizeof(struct game_entry), game_entry3);
}

void insert(struct game_entry * entries, int count, struct game_entry to_insert) {
    if (entries[count - 1].score < to_insert.score) {
        entries[count - 1] = to_insert;
        for (int i = count; i > 1; i--) {
            if (entries[i - 1].score > entries[i - 2].score) {
                struct game_entry temp = entries[i - 2];
                entries[i - 2] = entries[i - 1];
                entries[i - 1] = temp;
            }
        }
    }
}