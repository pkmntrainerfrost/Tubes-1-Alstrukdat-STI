#include <stdio.h>
#include <stdlib.h>
#include "queueGame.h"

void clearQueue(Queue *Q)
{
    QElType X;
    while (!(IsEmpty(*Q))){
        dequeue(Q, &X);
    }
}

void queueGame(Queue *Q, List L)
{
    printf("Berikut adalah daftar antrian game-mu\n");
    displayQueue(*Q);

    listGame(L);
    
    printf("Nomor Game yang mau ditambahkan ke antrian: ");

    Word GameNum;
    createWord(&GameNum);
    startKataInput();
    int i = 0;
    while (!endKata){
        GameNum.buffer[i] = cc;
        startKataInput();
    }

    GameNum.length = i;

    int num;
    num = wordToInt(GameNum);

    if (num>length(L)){
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list\n");
    } else {
        enqueue(Q, L.A[num-1]);
        printf("Game berhasil ditambahkan ke dalam daftar antrian\n");
    }
}