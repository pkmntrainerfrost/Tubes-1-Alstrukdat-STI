#include <stdio.h>
#include <stdlib.h>
#include "queueGame.h"

void queueGame(Queue *queueGame, List L) {

    if (IsEmpty(*queueGame)) {
        printf("Antrian anda kosong\n");
    } else {
        printf("Berikut adalah daftar antrian game-mu\n");
        displayQueue(*queueGame);
        printf("\n");

        listGame(L);
        printf("\n");

        printf("Nomor Game yang mau ditambahkan ke antrian: ");
        Word input;
        createWord(&input);
        boolean valid = wordInput(&input,1,10);
        if (wordToInt(input) > 0 && wordToInt(input) <= length(L)) {
            Word game;
            createWord(&game);
            copyWord(getElmt(L,wordToInt(input) - 1),&game);
            enqueue(queueGame,game);
            printf("Game berhasil ditambahkan ke dalam daftar antrian\n");
        } else {
            printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list\n");
        }

    }
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
//     Queue Q;
//     createQueue(&Q);
//     enqueue(&Q, stringToWord("Tetris"));
//     enqueue(&Q, stringToWord("Diner DASH"));
//     enqueue(&Q, stringToWord("RNG"));
//     queueGame(&Q,L);
//     displayQueue(Q);
//     return 0;  
// }

// compile: gcc utility/queuegame/queueGame.c Misc/io/io.c Misc/ascii/ascii.c utility/L/L.c ADT/list/array.c ADT/queue/queue2.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c -o driver