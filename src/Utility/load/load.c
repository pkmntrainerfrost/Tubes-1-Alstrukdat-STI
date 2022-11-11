#include "../../ADT/boolean.h"
#include "../../ADT/list/array.h"
#include "../../ADT/word/word.h"
#include "../../ADT/word/mesinkata/mesinkata.h"

#include <stdio.h>

void LOAD(Word filename, List *ListGame){
    
    Word filepath;
    concateWord(stringToWord("Config/"),filename,&filepath);
    
    char filepathstr[wordLength(filepath) + 1];
    wordToString(filepath,filepathstr);

    startKata(true,filepathstr);
    advKata();

    while (!endKata) {
        insertLast(ListGame,currentKata);
        advKata();
    }

}

boolean CHECKFILE(Word filename) {

    Word filepath;
    concateWord(stringToWord("Config/"),filename,&filepath);
    
    char filepathstr[wordLength(filepath) + 1];
    wordToString(filepath,filepathstr);

    FILE * test;
    test = fopen(filepathstr,"r");

    if (test) {
        fclose(test);
        return false;
    } else {
        return true;
    }

}