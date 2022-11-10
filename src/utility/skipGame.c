#include <stdio.h>
#include "skipGame.h"

void skipGame(Queue *Q, int n)
{
    printf("Berikut adalah daftar Game-mu\n");
    displayQueue(*Q);

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
        printf("Loading %s ...\n", Front(*Q).buffer);      
    }
}