#include <stdio.h>
#include "createGame.h"

void createGame(List *L)
{
    printf("Masukkan nama game yang akan ditambahkan: ");
    List input;
    createList(&input);
    boolean valid = multiWordInput(&input,1,10);
    displayList(input);
    Word temp;
    createWord(&temp);
    int i;
    for(i=0; i<wordLength(input.A[0]); i++){
        temp.buffer[i] = input.A[0].buffer[i];
    }
    deleteFirst(&input);
    printWord(temp);
    while (length(input) > 0) {
        printf(" ");
        copyWord(getElmt(input,0), &temp);
        for (i=0; i<wordLength(input.A[0]); i++){
            temp.buffer[wordLength(temp)+i] = input.A[0].buffer[i];
        }
        printWord(temp);
        deleteFirst(&input);
    }
    printWord(temp);
    // ???????
    // Word GameName;
    // createWord(&GameName);

    // int i = 0;
    // startInput();

    // while (!eoi) {
    //     if (i < N_MAX) {
    //         GameName.buffer[i] = cc;
    //         i++;
    //     }
    //     advInput();
    // }

    // GameName.length = i;
    // insertLast(L, GameName);
}

int main()
{
    List L;
    createList(&L);
    createGame(&L);
    return 0;
}

// compile: gcc utility/createGame.c utility/listGame/listGame.c ADT/list/array.c ADT/queue/queue2.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/io/io.c Misc/ascii/ascii.c -o driver 