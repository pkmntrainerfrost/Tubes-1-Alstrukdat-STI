#include <stdio.h>
#include "createGame.h"

void createGame(List *L)
{
    printf("Masukkan nama game yang akan ditambahkan: ");
    // jika list penuh
    if (isFull(*L)) {
        updateCapacity(L);
    }   

    Word GameName;
    createWord(&GameName);

    int i = 0;
    startInput();

    while (!eoi) {
        if (i < N_MAX) {
            GameName.buffer[i] = cc;
            i++;
        }
        advInput();
    }

    GameName.length = i;
    insertLast(L, GameName);
}