#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "playGame.h"

void playGame(Queue *Q, List L)
{
    if (IsEmpty(*Q)){
        printf("Tidak ada permainan lagi dalam daftar Game-mu\n");
    } else {
        printf("Berikut adalah daftar Game-mu\n");
        displayQueue(*Q);
        printf("\n");

        if (isSameWord(Front(*Q), stringToWord("RNG")) || isSameWord(Front(*Q), L.A[0]) || isSameWord(Front(*Q), stringToWord("Diner DASH")) || isSameWord(Front(*Q), L.A[1]) || isSameWord(Front(*Q), stringToWord("Battleship")) || isSameWord(Front(*Q),L.A[5])){
            printf("Loading ");
            printWord(Front(*Q));
            printf(" ...\n");
            if (isSameWord(Front(*Q), stringToWord("RNG")) || isSameWord(Front(*Q), L.A[0])){
                rng();
            } else if (isSameWord(Front(*Q), stringToWord("Diner DASH")) || isSameWord(Front(*Q), L.A[1])){
                dinerDash();
            } else if (isSameWord(Front(*Q), stringToWord("Battleship")) || isSameWord(Front(*Q), L.A[5])){
                // Battleship();
                // fungsi utamanya mana? 
                printf("jalan Battleship\n");
            }
        } else if (isSameWord(Front(*Q), L.A[2]) || isSameWord(Front(*Q), L.A[3]) || isSameWord(Front(*Q), L.A[4])){
            // Game di file config default selain RNG dan diner DASH dan battleship
            printf("Game ");
            printWord(Front(*Q));
            printf(" masih dalam maintenance, belum dapat dimainkan.\n");
            printf("Silahkan pilih game lain.\n");
        } else {
            // tidak ada di spek game, atau hasil createGame
            printf("Loading ");
            printWord(Front(*Q));
            printf(" ...\n");
            printf("GAME OVER\n");
            srand(time(NULL));
			int r = rand();
			printf("Score: %d\n", r);
        }

        QElType x;
        dequeue(Q, &x);
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