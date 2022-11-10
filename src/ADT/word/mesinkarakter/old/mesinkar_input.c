#include <stdio.h>
#include <stdlib.h>
#include "mesinkar_input.h"

char inputcc;
boolean eoi;

static FILE *inputRibbon;
static int inputRetval;

void startInput() {

    inputRibbon = stdin;
    advInput();

}

void advInput() {

    inputRetval = fscanf(stdin, "%c", &inputcc);
    eoi = (inputcc == INPUTMARK);

}

/*
int main() {

    for (int i = 0; i < 10; i++) {

        start();

        while (inputcc != INPUTMARK) {
            printf("%c",inputcc);
            advInput();
        }

        printf("\n");

        printf("\033[H\033[J");

    }

}
*/