/* File: queueGame.h */
/* Menggunakan ADT queue */

#ifndef PLAYGAME_H
#define PLAYGAME_H

/* ADT lain yang dipakai */
#include "../../ADT/boolean.h"
#include "../queuegame/queueGame.h"
#include "../../Games/rng/rng.h"
#include "../../Games/dinerdash/dinerdash.h"
#include "../../Games/battleship/battleship.h"

void playGame(Queue *Q, List L, List *listHist);
// Game yang dimainkan adalah game dengan antrian pertama di antrian game
// Game yang dapat dimainkan adalah game yang ada di spek game

#endif