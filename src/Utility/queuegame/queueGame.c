#include <stdio.h>
#include <stdlib.h>
#include "../../Misc/io/io.h"
#include "../../Misc/ascii/ascii.h"
#include "queueGame.h"

void clearQueue(Queue *Q)
{
    QElType X;
    while (!(IsEmpty(*Q))){
        dequeue(Q, &X);
    }
}

void queueGame(Queue *queueGame, List listGame) {

    if (IsEmpty(*queueGame)) {
        printf("Antrian anda kosong\n");
    } else {
        printf("Berikut adalah daftar antrian game-mu\n");
        int j = 1;
        for (int i = (*queueGame).HEAD; i <= (*queueGame).TAIL; i++) {
            printf("%d. ",j);
            printWord(queueGame->Tab[i]);
            printf("\n");
            j = j + 1;
        }
        printf("\n");
        printf("Berikut adalah daftar game yang tersedia");
        j = 1;
        for (int i = 0; i < length(listGame); i++) {
            printf("%d. ",j);
            printWord(getElmt(listGame,i));
            printf("\n");
            j = j + 1;
        }
        printf("\n");
        printf("Nomor Game yang mau ditambahkan ke antrian: ");
        Word input;
        createWord(&input);
        boolean valid = wordInput(&input,1,10);
        if (wordToInt(input) > 0 && wordToInt(input) <= length(listGame)) {
            Word game;
            createWord(&game);
            copyWord(getElmt(listGame,wordToInt(input) - 1),&game);
            enqueue(queueGame,game);
            printf("Game berhasil ditambahkan");
        } else {
            printf("Nomor ora valid");
        }

    }
    

    // printf("Berikut adalah daftar antrian game-mu\n");
    // displayQueue(*Q);

    // listGame(L);
    
    // printf("Nomor Game yang mau ditambahkan ke antrian: ");

    // Word GameNum;
    // createWord(&GameNum);
    // startKataInput();
    // int i = 0;
    // while (!endKata){
    //     GameNum.buffer[i] = cc;
    //     startKataInput();
    // }

    // GameNum.length = i;

    // int num;
    // num = wordToInt(GameNum);

    // if (num>length(L)){
    //     printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list\n");
    // } else {
    //     enqueue(Q, L.A[num-1]);
    //     printf("Game berhasil ditambahkan ke dalam daftar antrian\n");
    // }
}