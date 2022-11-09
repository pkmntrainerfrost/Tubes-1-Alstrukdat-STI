#include <stdio.h>
#include "createGame.h"

void createGame(List *L)
{
    printf("Masukkan nama game yang akan ditambahkan: ");
    // jika list penuh
    if (isFull(*L)) {
        updateCapacity(L);
    }   

    STARTWORD();
    while (!EndWord){
        insertLast(L, currentWord);
        STARTWORD();
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