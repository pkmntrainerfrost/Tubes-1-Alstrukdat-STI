#include <stdio.h>
#include "listMap.h"
#include "../../Utility/start/start.h"


int main()
{
    // List Game;
    // createList(&Game);
    // START(&Game);
    // displayList(Game);

    Map M1, M2, M3;
    CreateEmptyMap(&M1);
    CreateEmptyMap(&M2);

    List Game;
    createList(&Game);
    insertLast(&Game, stringToWord("hangman"));
    insertLast(&Game, stringToWord("rng"));
    insertLast(&Game, stringToWord("diner"));
    insertLast(&Game, stringToWord("tower"));
    displayList(Game);

    Map maphangman, maprng, mapdiner, maptower;
    CreateEmptyMap(&maphangman);
    CreateEmptyMap(&maprng);
    CreateEmptyMap(&mapdiner);
    CreateEmptyMap(&maptower);

    ListMap L;
    createListMap(&L);
    insertListMap(&L, maphangman);
    insertListMap(&L, maprng);
    insertListMap(&L, mapdiner);
    insertListMap(&L, maptower);

    inputDataListMap(&L, 1, 10);

    displayListMap(L, Game);

    // ListMap L;
    // createListMap(&L);

    // keytype test, test1;
    // test = stringToWord("hai");
    // test1 = stringToWord("halo");
    // valuetype testInfo, test1Info;
    // testInfo = 10;
    // test1Info = 20;
    // InsertMap(&M1, test, testInfo);
    // InsertMap(&M1, test1, test1Info);

    // test = stringToWord("heyo");
    // test1 = stringToWord("yohe");
    // testInfo = 30;
    // test1Info = 40;
    // InsertMap(&M2, test, testInfo);
    // InsertMap(&M2, test1, test1Info);  

    // insertListMap(&L, M1);
    // insertListMap(&L, M2);
    // displayListMap(L);
    // inputDataListMap(&L, 0, 100);
    // // displayListMap(L);
    return 0;
}

//compile : gcc Utility/start/start.c ADT/list/array.c ADT/map/map.c ADT/map/driverListMap.c ADT/map/listMap.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/ascii/ascii.c Misc/io/io.c -o driver