/* File: listGame.h */
/* Menggunakan ADT array */

#ifndef LISTGAME_H
#define LISTGAME_H

/* ADT lain yang dipakai */
#include "../ADT/list/array.h"
#include "../ADT/mesinkar/mesinkata_input.h"
#include "../Misc/io/io.h"

void listGame(List L);
// I.S. List L terdefinisi
// F.S. Jika List kosong menampilkan pesan list kosong
// Jika List tidak kosong, menampilkan daftar game yang disediakan oleh sistem

// Contoh Output:
// ENTER COMMAND: LIST GAME
// Berikut adalah daftar game yang tersedia
// 1. RNG
// 2. LUNCH SLOW
// 3. DINASOUR IN EARTH
// 4. RISEWOMAN
// 5. EIFFEL TOWER

#endif