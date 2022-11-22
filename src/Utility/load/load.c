#include "../../ADT/boolean.h"
#include "../../ADT/list/array.h"
#include "../../ADT/word/word.h"
#include "../../ADT/word/mesinkata/mesinkata.h"

#include <stdio.h>

void LOAD(Word filename, List *ListGame, List *listHist){
    
    Word filepath;
    concateWord(stringToWord("Config/"),filename,&filepath);
    
    char filepathstr[wordLength(filepath) + 1];
    wordToString(filepath,filepathstr);

    startKata(true,filepathstr);
    int i;
    int number = wordToInt(currentKata); //baca jumlah listGame
    advKata();
    for (i=0; i < number; i++){
        insertLast(ListGame,currentKata);
        advKata();
    }
    number = wordToInt(currentKata); //baca jumlah listHist
    advKata();
    for (i=0; i < number; i++){
        insertFirst(listHist,currentKata);
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