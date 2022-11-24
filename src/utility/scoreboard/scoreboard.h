#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <stdio.h>
#include "../../ADT/map/map.h"
#include "../../ADT/set/set.h"
#include "../../ADT/word/mesinkata/mesinkata.h"
#include "../../ADT/word/word.h"
#include "../listGame/listGame.h"
#include "../../Misc/io/io.h"
#include "../../Misc/ascii/ascii.h"

void displayscoreboard(Map M);
/*untuk menampilkan scoreboard*/

void inserttoscoreboard(Map *M, Word nama, int score);
/*menambahkan nama serta score*/

void scoreboard(Map daftarsb, int num);
void resetscoreboard(Map *daftarsb);

#endif
