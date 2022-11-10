#include <stdio.h>
#include "playGame.h"

void playGame(Queue *Q)
{
    if (IsEmpty(*Q)){
        printf("Antrian game kosong\n");
    } else {
        printf("Berikut adalah daftar Game-mu\n");
        displayQueue(*Q);

        if (isSameWord(Front(*Q), stringToWord("RNG")) || isSameWord(Front(*Q), stringToWord("Diner DASH"))){
            // RNG atau diner dash
            // belum tambahin game buatan
            printf("Loading %s ...\n", Front(*Q).buffer);
            QElType x;
            dequeue(Q, &x);
        } else {
            // tidak ada di spek game
            printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", Front(*Q).buffer);
            printf("Silahkan pilih game lain.\n");
        }
    }
}