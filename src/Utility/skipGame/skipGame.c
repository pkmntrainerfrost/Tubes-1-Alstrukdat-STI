#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "skipGame.h"
// #include "../../Games/rng/rng.h"
// #include "../../Games/dinerdash/dinerdash.h"
// #include "../../Games/battleship/battleship.h"

void skipGame(Queue *Q, List L, int n) {

    header();

    printf("Berikut adalah daftar Game-mu\n");
    displayQueue(*Q);
    printf("\n");
    int i;
    QElType X;
    if (n>Length(*Q)){
        for(i=0; i<Length(*Q); i++){
            dequeue(Q, &X);
        }
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
    } else {
        
        for (i=0; i<n; i++){
            dequeue(Q, &X);
        }

        // jadinya pake idx apa string?
        if (isSameWord(Front(*Q), stringToWord("RNG")) || isSameWord(Front(*Q), stringToWord("Diner DASH")) || isSameWord(Front(*Q), stringToWord("Battleship"))){
            printf("Loading ");
            printWord(Front(*Q));
            printf(" ...\n");
            if (isSameWord(Front(*Q), stringToWord("RNG"))){
                // rng();
                printf("jalan RNG\n");
            } else if (isSameWord(Front(*Q), stringToWord("Diner DASH"))){
                // DinerDash();
                printf("jalan Diner DASH\n");
            } else if (isSameWord(Front(*Q), stringToWord("Battleship"))){
                // Battleship();
                // fungsi utamanya mana?
                printf("jalan Battleship\n");
            }
        } else if (isSameWord(Front(*Q), stringToWord("EIFFEL TOWER")) || isSameWord(Front(*Q), stringToWord("RISEWOMAN")) || isSameWord(Front(*Q), stringToWord("DINOSAUR IN EARTH"))){
            // Game di file config default selain RNG dan diner DASH
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
//     // listGame(L);
//     Queue Q;
//     createQueue(&Q);
//     enqueue(&Q, stringToWord("RNG"));
//     enqueue(&Q, stringToWord("Diner DASH"));
//     enqueue(&Q, stringToWord("Battleship"));
//     enqueue(&Q, stringToWord("RISEWOMAN"));
//     enqueue(&Q, stringToWord("Tetris"));
//     skipGame(&Q, L, 4);
//     return 0;
// }

// compile: gcc utility/skipGame/skipGame.c utility/playGame/playGame.c utility/queuegame/queueGame.c utility/listGame/listGame.c ADT/list/array.c ADT/queue/queue2.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/ascii/ascii.c Misc/io/io.c -o driver