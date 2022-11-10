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

// int main()
// {
//     List L;
//     createList(&L);
//     // listGame(L);
//     ElType test;
//     test = stringToWord("hai");
//     insertLast(&L, test);
//     test = stringToWord("halo");
//     insertLast(&L, test); 
//     listGame(L);
//     return 0;
// }
