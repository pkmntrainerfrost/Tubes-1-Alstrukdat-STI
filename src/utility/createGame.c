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
            GameName.buffer[i] = inputcc;
            i++;
        }
        advInput();
    }

    GameName.length = i;
    insertLast(L, GameName);
}

// int main()
// {
//     List L;
//     createList(&L);
//     ElType test;
//     test.length = 3;
//     test.buffer[0] = 'h';
//     test.buffer[1] = 'a';
//     test.buffer[2] = 'i';
//     insertLast(&L, test);
//     createGame(&L);
//     printList(L);
//     return 0;
// }