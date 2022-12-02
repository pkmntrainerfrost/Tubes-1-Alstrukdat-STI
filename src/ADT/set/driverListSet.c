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

// compile : gcc ADT/set/driverListSet.c ADT/set/listSet.c ADT/set/set.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/ascii/ascii.c -o driver