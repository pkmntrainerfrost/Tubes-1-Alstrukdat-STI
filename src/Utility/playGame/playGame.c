#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "playGame.h"

void playGame(Queue *Q, List L)
{
    if (IsEmpty(*Q)){
        printf("Antrian Anda kosong.\n");
    } else {
        printf("Berikut adalah daftar Game di dalam antrian Anda.\n");
        displayQueue(*Q);
        printf("\n");
        QElType x;
        dequeue(Q, &x);
        if (isSameWord(x, stringToWord("RNG")) || isSameWord(x, stringToWord("Diner DASH")) || isSameWord(x, stringToWord("Battleship"))){
            printf("Loading ");
            printWord(x);
            printf(" ...\n");
            printf("\nLoading selesai! Tekan [ENTER] untuk memasuki permainan...\n");
            blankInput();
            if (isSameWord(x, stringToWord("RNG"))){
                rng();
            } else if (isSameWord(x, stringToWord("Diner DASH"))){
                dinerDash();
            } else if (isSameWord(x, stringToWord("Battleship"))){
                battleship();
            }
        } else if (isSameWord(x, stringToWord("EIFFEL TOWER")) || isSameWord(x, stringToWord("RISEWOMAN")) || isSameWord(x, stringToWord("DINOSAUR IN EARTH"))){
            // Game di file config default selain RNG dan diner DASH
            printf("Game ");
            printWord(x);
            printf(" masih dalam maintenance, belum dapat dimainkan.\n");
            printf("Silahkan pilih game lain.\n");
            printf("\nTekan [ENTER] untuk kembali ke menu utama...\n");
            blankInput();
        } else {
            // tidak ada di spek game, atau hasil createGame
            printf("Loading ");
            printWord(x);
            printf(" ...\n");
            printf("GAME OVER\n");
			int r = random_range(0,100);
			printf("Score: %d\n", r);
            printf("\nTekan [ENTER] untuk kembali ke menu utama...\n");
            blankInput();
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
//     displayList(L);
//     Queue Q;
//     createQueue(&Q);
//     enqueue(&Q, stringToWord("RNG"));
//     enqueue(&Q, stringToWord("Diner DASH"));
//     enqueue(&Q, stringToWord("RNG"));
//     playGame(&Q, L);
//     displayQueue(Q);
//     return 0;
// }

// compile: gcc utility/playGame/playGame.c utility/queuegame/queueGame.c utility/listGame/listGame.c Games/rng/rng.c Games/random.c Games/dinerdash/dinerdash.c ADT/list/array.c ADT/queue/queue2.c ADT/queue/prioqueue.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/io/io.c Misc/ascii/ascii.c -o driver
// battleship blm jalan