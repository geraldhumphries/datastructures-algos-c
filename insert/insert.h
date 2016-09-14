//
// Created by ghumphries on 9/11/2016.
//

#ifndef GAMEENTRIES_INSERT_H
#define GAMEENTRIES_INSERT_H

#include "game_entry.h"

void build_game_entries_and_insert();
void insert(struct game_entry * entries, int count, struct game_entry to_insert);

#endif //GAMEENTRIES_INSERT_H
