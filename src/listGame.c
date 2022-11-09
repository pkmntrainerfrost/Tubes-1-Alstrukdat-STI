#include <stdio.h>
#include "listGame.h"

void listGame(List L)
{
    if (isEmpty(L)){
        printf("Tidak ada game yang tersedia\n");
    } else {
        printf("Berikut adalah daftar game yang tersedia\n");
        int i;
        for (i=0; i<L.nEff; i++){
            printf("%d. %s\n", i+1, L.A[i].buffer);
        }
    }
}

// int main()
// {
//     List L;
//     createList(&L);
//     // listGame(L);
//     ElType test;
//     test.Length = 3;
//     test.TabWord[0] = 'h';
//     test.TabWord[1] = 'a';
//     test.TabWord[2] = 'i';
//     insertLast(&L, test);
//     test.Length = 4;
//     test.TabWord[0] = 'h';
//     test.TabWord[1] = 'a';
//     test.TabWord[2] = 'l'; 
//     test.TabWord[3] = 'o';
//     insertLast(&L, test); 
//     listGame(L);
//     return 0;
// }
