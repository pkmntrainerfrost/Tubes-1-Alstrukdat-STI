#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "playGame.h"
// #include "../Games/rng/rng.h"
// #include "../Games/dinerdash/dinerdash.h"
// #include "../Games/battleship/battleship.h"

void playGame(Queue *Q, List L)
{
    if (IsEmpty(*Q)){
        printf("Tidak ada permainan lagi dalam daftar Game-mu\n");
    } else {
        printf("Berikut adalah daftar Game-mu\n");
        displayQueue(*Q);

        // jadinya pake idx apa string?
        if (isSameWord(Front(*Q), stringToWord("RNG")) || isSameWord(Front(*Q), stringToWord("Diner DASH")) || isSameWord(Front(*Q), stringToWord("Battleship"))){
            printf("Loading %s ...\n", Front(*Q).buffer);
            QElType x;
            dequeue(Q, &x);
            if (isSameWord(Front(*Q), stringToWord("RNG"))){
                // rng();
                printf("jalan RNG\n");
            } else if (isSameWord(Front(*Q), stringToWord("Diner DASH"))){
                // DinerDash();
                printf("jalan Diner dash\n");
            } else if (isSameWord(Front(*Q), stringToWord("Battleship"))){
                // Battleship();
                // fungsi utamanya mana?
                printf("jalan Battleship\n");
            }
        } else if (isSameWord(Front(*Q), L.A[2]) || isSameWord(Front(*Q), L.A[3]) || isSameWord(Front(*Q), L.A[4])){
            // Game di file config default selain RNG dan diner DASH
            printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", Front(*Q).buffer);
            printf("Silahkan pilih game lain.\n");
        } else {
            // tidak ada di spek game, atau hasil createGame
            printf("GAME OVER\n");
            srand(time(NULL));
			int r = rand();
			printf("Score: %d\n", r);
        }
    }
}

int main()
{
    List L;
    createList(&L);
    insertLast(&L, stringToWord("RNG"));
    insertLast(&L, stringToWord("Diner DASH"));
    insertLast(&L, stringToWord("DINOSAUR IN EARTH"));
    insertLast(&L, stringToWord("RISEWOMAN"));
    insertLast(&L, stringToWord("EIFFEL TOWER"));
    insertLast(&L, stringToWord("Battleship")); 
    insertLast(&L, stringToWord("Tetris"));
    displayList(L);
    Queue Q;
    createQueue(&Q);
    printf("%d\n", stringToWord("RNG").length);
    enqueue(&Q, stringToWord("RNG"));
    playGame(&Q, L);
}

// compile: gcc utility/playGame.c utility/queueGame.c utility/listGame/listGame.c ADT/list/array.c ADT/queue/queue2.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/ascii/ascii.c -o driver