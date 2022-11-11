#include <stdio.h>
#include "deleteGame.h"

void deleteGame(List *L, Queue Q)
{
    listGame(*L);
    printf("\n");

    printf("Masukkan nomor game yang akan dihapus: ");
    Word input;
    createWord(&input);
    boolean valid = wordInput(&input,1,10);
    if (wordToInt(input) > 0 && wordToInt(input) <= length(*L)) {
        if (wordToInt(input)>=1 && wordToInt(input)<=6){
            // 5 game pertama gan game bonus pada urutan ke 6 pada file konfigurasi tidak dapat dihapus
            printf("Game gagal dihapus\n");
        } else if (wordToInt(input) > 6 && wordToInt(input) <= length(*L)) {
            if (!(IsEmpty(Q))){
                if (!(isMember(Q, getElmt(*L,wordToInt(input)-1)))){
                    deleteAt(L, wordToInt(input)-1);
                    printf("Game berhasil dihapus\n");
                } else {
                    printf("Game ada di antrian game-mu\n");
                    printf("Game gagal dihapus\n");
                }
            }
        }
    } else {    // wordToInt(input) <= 0 || wordToInt(input) > length(*L)
        printf("Nomor game tidak valid\n");
        printf("Game gagal dihapus\n");
    }
    printf("\n");
}

// int main()
// {
//     List L;
//     createList(&L);
//     insertLast(&L, stringToWord("RNG"));
//     insertLast(&L, stringToWord("Diner DASH"));
//     insertLast(&L, stringToWord("DINOSAUR IN EARTH"));
//     insertLast(&L, stringToWord("RISEWOMAN"));
//     insertLast(&L, stringToWord("EIFFEL TOWER"));
//     insertLast(&L, stringToWord("Battleship")); 
//     insertLast(&L, stringToWord("Tetris"));
//     displayList(L);
//     printf("\n");
//     Queue Q;
//     createQueue(&Q);
//     enqueue(&Q, stringToWord("RNG"));
//     enqueue(&Q, stringToWord("Diner DASH"));
//     enqueue(&Q, stringToWord("RNG"));
//     displayQueue(Q);
//     printf("\n");
//     deleteGame(&L,Q);
//     displayList(L);
//     return 0;
// }

// compile: gcc utility/deleteGame/deleteGame.c utility/listGame/listGame.c ADT/list/array.c ADT/queue/queue2.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/io/io.c Misc/ascii/ascii.c -o driver
