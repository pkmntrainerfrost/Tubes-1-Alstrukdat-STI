#include <stdio.h>
#include "set.h"

int main() {
    Set S;
    CreateEmptySet(&S);
    if (IsEmptySet(S)){
        printf("Set kosong\n");
    } else {
        printf("Set tidak kosong\n");
    }
    infotypeSet test, test1;
    test = stringToWord("hai");
    test1 = stringToWord("halo");
    InsertSet(&S, test);
    InsertSet(&S, test1);
    if (IsMemberSet(S, test)){
        printf("hai adalah anggota set\n");
    } else {
        printf("hai bukan anggota set\n");
    }

    PrintSet(S);

    boolean valid = InsertSet(&S, test);
    if (valid){
        printf("true\n");
    } else {
        printf("false\n");
    }

}

// compile : gcc ADT/set/driverset.c ADT/set/set.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/ascii/ascii.c -o driver