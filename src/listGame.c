#include <stdio.h>
#include "listGame.h"

void ListGame(List L)
{
    if (isEmpty(L)){
        printf("Tidak ada game yang tersedia\n");
    } else {
        printf("Berikut adalah daftar game yang tersedia\n");
        int i;
        for (i=0; i<L.nEff; i++){
            printf("%d. %s\n", i+1, L.buffer[i].character);
        }
    }
}
