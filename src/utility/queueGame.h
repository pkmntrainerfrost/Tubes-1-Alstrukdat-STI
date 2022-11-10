/* File: queueGame.h */
/* Menggunakan ADT queue */

#ifndef QUEUEGAME_H
#define QUEUEGAME_H

/* ADT lain yang dipakai */
#include "boolean.h"
#include "../ADT/queue/queue2.h"
#include "../ADT/mesinkar/mesinkata_input.h"
#include "../Misc/io/io.h"
#include "listGame.h"

void clearQueue(Queue *Q);
// List dalam queue akan hilang ketika pemain menjalankan command QUIT

void queueGame(Queue *Q, List L);
// mendaftarkan permainan ke dalam list

#endif