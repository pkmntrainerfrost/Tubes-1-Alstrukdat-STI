#include <stdio.h>
#include "deleteGame.h"

void deleteGame(List *L, Queue Q)
{
    listGame(*L);
    int num;
    printf("Masukkan nomor game yang akan dihapus: ");
    Word GameNum;
    createWord(&GameNum);
    startKataInput();
    int i = 0;
    while (!endKataInput){
        GameNum.buffer[i] = inputcc;
        startKataInput();
    }

    GameNum.length = i;

    int num;
    wordToInt(&num, GameNum);   

    if (num>=1 && num<=5){
        // 5 game pertama pada file konfigurasi tidak dapat dihapus
        printf("Game gagal dihapus\n");
    } else {
        if (!(IsEmpty(Q))){
            // jika queue game tidak kosong
            if (!(isMember(Q, (*L).A[num-1]))){
                // jika game yang akan dihapus tidak ada di queue
                deleteAt(L, num-1);
                printf("Game berhasil dihapus\n");
            } else {
                printf("Game gagal dihapus\n");
            }
        }
    }
}

// int main()
// {
//     List L;
//     createList(&L);
//     Queue Q;
//     createQueue(&Q);
//     Word satu;
//     satu.length = 4;
//     satu.buffer[0] = 's';
//     satu.buffer[1] = 'a';
//     satu.buffer[2] = 't';
//     satu.buffer[3] = 'u';
//     enqueue(&Q,satu);
//     insertLast(&L,satu);
//     printQueue(Q);
//     deleteGame(&L,Q);
//     printList(L);

//     return 0;
// }
