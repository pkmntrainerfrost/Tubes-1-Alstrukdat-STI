#include <stdio.h>
#include "playGame.h"
#include "../Games/rng/rng.h"
#include "../Games/dinerdash/dinerdash.h"
#include "../Games/battleship/battleship.h"

void playGame(Queue *Q)
{
    if (IsEmpty(*Q)){
        printf("Antrian game kosong\n");
    } else {
        printf("Berikut adalah daftar Game-mu\n");
        displayQueue(*Q);

        if (isSameWord(Front(*Q), stringToWord("RNG")) || isSameWord(Front(*Q), stringToWord("Diner DASH")) || isSameWord(Front(*Q), stringToWord("Battleship"))){
            printf("Loading %s ...\n", Front(*Q).buffer);
            QElType x;
            dequeue(Q, &x);
            if (isSameWord(Front(*Q), stringToWord("RNG"))){
                rng();
            } else if (isSameWord(Front(*Q), stringToWord("Diner DASH"))){
                DinerDash();
            } else if (isSameWord(Front(*Q), stringToWord("Battleship"))){
                // Battleship();
                // fungsi utamanya mana?
            }
        } else {
            // tidak ada di spek game
            // tambahin keluar skor random
            printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", Front(*Q).buffer);
            printf("Silahkan pilih game lain.\n");
        }
    }
}