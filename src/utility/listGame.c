#include <stdio.h>
#include "listGame.h"

void listGame(List L)
{
    if (isEmpty(L)){
        printf("Tidak ada game yang tersedia\n");
    } else {
        printf("Berikut adalah daftar game yang tersedia\n");
        displayList(L);
    }
}