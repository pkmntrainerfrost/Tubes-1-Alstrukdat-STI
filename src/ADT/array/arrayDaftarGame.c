#include <stdio.h>
#include "arrayDaftarGame.h"

void arrayDaftarGame(ArrayGame L)
{
    if (isEmpty(L)){
        printf("Tidak ada game yang tersedia\n");
    } else {
        printf("Berikut adalah daftar game yang tersedia\n");
        int i;
        for (i=0; i<L.Neff; i++){
            printf("%d. %s\n", i+1, L.Elmt[i]);
        }
    }
}