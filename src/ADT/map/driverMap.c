#include <stdio.h>
#include "map.h"

int main()
{
    Map M;
    CreateEmptyMap(&M);
    if (IsEmptyMap(M)){
        printf("Map kosong\n");
    } else {
        printf("Map tidak kosong\n");
    }
    keytype test, test1;
    test = stringToWord("hai");
    test1 = stringToWord("halo");
    valuetype testInfo, test1Info;
    testInfo = 10;
    test1Info = 20;
    InsertMap(&M, test, testInfo);
    InsertMap(&M, test1, test1Info);
    PrintMap(M, stringToWord("MAP-1"));
    DeleteMap(&M, test);
    PrintMap(M, stringToWord("MAP-NEW"));
    printf("%d\n", Value(M, test));
    printf("%d\n", Value(M, test1));
    inputData(&M, testInfo);
    PrintMap(M, stringToWord("NEW"));
    return 0;
}

// compile : gcc ADT/list/array.c ADT/map/driverMap.c ADT/map/map.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/ascii/ascii.c Misc/io/io.c -o driver