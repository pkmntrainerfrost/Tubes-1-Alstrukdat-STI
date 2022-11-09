#include "mesinkata.h"

boolean endKata;
Word currentKata;

void ignoreBlank() {

    while (cc == BLANK) {
        adv();
    }

}

void startKata() {

    start();
    ignoreBlank();

    if (cc == MARK) {
        endKata = true;
    } else {
        endKata = false;
        salinKata();
    }

}

void advKata() {

    ignoreBlank();

    if (cc == MARK) {
        endKata = true;
    } else {
        salinKata();
    }

}

void salinKata() {

    int i = 0;

    while ((cc != MARK) && (cc != BLANK)) {
        currentKata.buffer[i] = cc;
        adv();
        i = i + 1;
    }

    currentKata.length = i;

}