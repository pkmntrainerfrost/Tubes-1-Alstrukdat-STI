#include <stdio.h>
#include "deleteGame.h"

void deleteGame(List *L, Queue Q)
{
    listGame(*L);
    printf("Masukkan nomor game yang akan dihapus: ");
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

    if (num>=1 && num<=5){
        // 5 game pertama pada file konfigurasi tidak dapat dihapus
        printf("Game gagal dihapus\n");
    } else {
        if (!(IsEmpty(Q))){
            if (num>length(*L)){   
                printf("Nomor game tidak valid.\n");
                printf("Game gagal dihapus.\n");
            } else {
                // jika queue game tidak kosong
                if (!(isMember(Q, (*L).A[num-1]))){
                    // jika game yang akan dihapus tidak ada di queue
                    deleteAt(L, num-1);
                    printf("Game berhasil dihapus\n");
                } else {
                    printf("Game ada di queue game\n");
                    printf("Game gagal dihapus\n");
                }
            }
        }
    }
}

