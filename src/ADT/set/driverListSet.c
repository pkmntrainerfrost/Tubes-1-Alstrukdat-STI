#include <stdio.h>
#include "listSet.h"

int main()
{
    Set sRNG, sDiner, sHangman;
    CreateEmptySet(&sRNG);
    CreateEmptySet(&sDiner);
    CreateEmptySet(&sHangman);

    ListSet S;
    createListSet(&S);
    if (isEmptyListSet(S)){
        printf("List kosong\n");
    } else {
        printf("List tidak kosong\n");
    }

    insertListSet(&S, sRNG);
    insertListSet(&S, sDiner);
    insertListSet(&S, sHangman);

    displayListSet(S);

    if (insertElmt(&S, 1, stringToWord("hai"))){
        printf("true\n");
    } else {
        printf("false\n");
    }

    displayListSet(S);

    if (insertElmt(&S, 1, stringToWord("hai"))){
        printf("true\n");
    } else {
        printf("false\n");
    }

    displayListSet(S);

    deallocateListSet(&S);
    displayListSet(S);

    return 0;
}

// compile : gcc src/ADT/set/driverListSet.c src/ADT/set/listSet.c src/ADT/set/set.c src/ADT/word/mesinkata/mesinkata.c src/ADT/word/mesinkarakter/mesinkarakter.c src/ADT/word/word.c src/Misc/ascii/ascii.c -o driver