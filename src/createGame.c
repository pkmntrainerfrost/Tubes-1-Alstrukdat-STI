#include <stdio.h>
#include "createGame.h"
#include "Misc/io/io.h"

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
}

// int main()
// {
//     List L;
//     createList(&L);
//     ElType test;
//     test.Length = 3;
//     test.TabWord[0] = 'h';
//     test.TabWord[1] = 'a';
//     test.TabWord[2] = 'i';
//     insertLast(&L, test);
//     createGame(&L);
//     printList(L);
//     return 0;
// }