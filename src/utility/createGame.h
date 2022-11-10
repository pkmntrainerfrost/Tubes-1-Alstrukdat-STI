#ifndef __CREATE_GAME_H__
#define __CREATE_GAME_H__

#include "../ADT/list/array.h"
#include "../ADT/word/mesinkarakter/mesinkarakter.h"
#include "../ADT/word/word.h"

void createGame(List *L);
// I.S. List game tidak kosong
// F.S. Jika input tidak NULL, menambahkan game baru dalam di akhir list game
// Jika input NULL, gagal menambahkan game baru

// Contoh input:
// ENTER COMMAND : CREATE GAME
// Masukkan nama game yang akan ditambahkan: EXTRA1
// Game berhasil ditambahkan

#endif