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
//     test = stringToWord("hai");
//     insertLast(&L, test);
//     createGame(&L);
//     printList(L);
//     return 0;
// }