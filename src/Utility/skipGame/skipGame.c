#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "skipGame.h"

void skipGame(Queue *Q, List L, int n) {

    header();

    printf("Berikut adalah daftar game dalam antrian Anda.\n");
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

        QElType y;
        dequeue(Q, &y);

        if (isSameWord(y, stringToWord("RNG")) || isSameWord(y, stringToWord("Diner DASH")) || isSameWord(y, stringToWord("Battleship"))){
            printf("Loading ");
            printWord(y);
            printf(" ...\n");
            printf("\nLoading selesai! Tekan [ENTER] untuk memasuki permainan...\n");
            blankInput();
            if (isSameWord(y, stringToWord("RNG"))){
                rng();
            } else if (isSameWord(y, stringToWord("Diner DASH"))){
                dinerDash();
            } else if (isSameWord(y, stringToWord("Battleship"))){
                battleship();
            }
        } else if (isSameWord(y, stringToWord("EIFFEL TOWER")) || isSameWord(y, stringToWord("RISEWOMAN")) || isSameWord(y, stringToWord("DINOSAUR IN EARTH"))){
            // Game di file config default selain RNG dan diner DASH
            printf("Game ");
            printWord(y);
            printf(" masih dalam maintenance, belum dapat dimainkan.\n");
            printf("Silahkan pilih game lain.\n");
            printf("\nTekan [ENTER] untuk kembali ke menu utama...\n");
            blankInput();
        } else {
            // tidak ada di spek game, atau hasil createGame
            printf("Loading ");
            printWord(y);
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
//     // listGame(L);
//     Queue Q;
//     createQueue(&Q);
//     enqueue(&Q, stringToWord("RNG"));
//     enqueue(&Q, stringToWord("Diner DASH"));
//     enqueue(&Q, stringToWord("Battleship"));
//     enqueue(&Q, stringToWord("RISEWOMAN"));
//     enqueue(&Q, stringToWord("RNG"));
//     skipGame(&Q, L, 4);
//     return 0;
// }

// compile: gcc Utility/skipGame/skipGame.c Utility/playGame/playGame.c Games/rng/rng.c Games/random.c Games/dinerdash/dinerdash.c ADT/queue/prioqueue.c Utility/queuegame/queueGame.c Utility/listGame/listGame.c ADT/list/array.c ADT/queue/queue2.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/ascii/ascii.c Misc/io/io.c -o driver