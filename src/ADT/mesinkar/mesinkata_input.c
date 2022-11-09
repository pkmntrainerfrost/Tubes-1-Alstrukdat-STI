#include "mesinkata_input.h"
#include "mesinkar_input.h"

boolean endKataInput;
Kata currentKataInput;

void ignoreBlankInput() {

    while (inputcc == BLANK) {
        adv();
    }

}

void startKata() {

    start();
    ignoreBlank();

    if (inputcc == INPUTMARK) {
        endKataInput = true;
    } else {
        endKataInput = false;
        salinKata();
    }

}

void advKata() {

    ignoreBlank();

    if (inputcc == INPUTMARK) {
        endKataInput = true;
    } else {
        salinKata();
    }

}

void salinKata() {

    int i = 0;

    while ((inputcc != INPUTMARK) && (inputcc != BLANK)) {
        currentKataInput.buffer[i] = inputcc;
        adv();
        i = i + 1;
    }

    currentKataInput.length = i;

}