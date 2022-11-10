#include "mesinkata.h"
#include "../word.h"
#include <stdio.h>

int main() {

    startKata(false,"");

    while (!endKata) {
        printWord(currentKata);
        printf("\n");
        advKata();
    }

    startKata(true,"test.txt");

    while (!endKata) {
        printWord(currentKata);
        printf("\n");
        advKata();
    }

}