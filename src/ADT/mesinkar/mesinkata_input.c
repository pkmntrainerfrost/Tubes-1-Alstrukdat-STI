#include "mesinkata_input.h"
#include "mesinkar_input.h"
#include <stdio.h>

boolean endKataInput;
Word currentKataInput;

void ignoreBlankInput() {

    while (inputcc == BLANK) {
        advInput();
    }

}

void startKataInput() {

    startInput();
    ignoreBlankInput();

    if (inputcc == INPUTMARK) {
        endKataInput = true;
    } else {
        endKataInput = false;
        salinKataInput();
    }

}

void advKataInput() {

    ignoreBlankInput();

    if (inputcc == INPUTMARK) {
        endKataInput = true;
    } else {
        salinKataInput();
    }

}

void salinKataInput() {

    int i = 0;

    while ((inputcc != INPUTMARK) && (inputcc != BLANK)) {
        currentKataInput.buffer[i] = inputcc;
        advInput();
        i = i + 1;
    }

    currentKataInput.length = i;

}