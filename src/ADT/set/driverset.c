#include <stdio.h>
#include "set.h"

int main() {
    Set S;
    CreateEmpty(&S);
    if (IsEmpty(S)){
        printf("Map kosong\n");
    } else {
        printf("Map tidak kosong\n");
    }
    infotype test, test1;
    test = stringToWord("hai");
    test1 = stringToWord("halo");
    Insert(&S, test);
    Insert(&S, test1);
    if (IsMember(S, test)){
        printf("hai adalah anggota set\n");
    } else {
        printf("hai bukan anggota set\n");
    }
    printf("hahaah\n ");
    PrintSet(S);

}

// compile : gcc ADT/set/driverset.c ADT/set/set.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/ascii/ascii.c -o driver