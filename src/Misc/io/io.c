/* File         : io.c */
/* Deskripsi    : Implementasi mesin karakter-kata untuk input/output + stringops */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "io.h"
#include "../../ADT/list/array.h"
#include "../../ADT/word/word.h"
#include "../../ADT/word/mesinkata/mesinkata.h"

int wordInput(Word *w, int min, int max) {

    createWord(w);

    start(false,"");

    int i = 0;
    while (!eoi) {
        if (i < N_MAX && i < max) {
            w->buffer[i] = cc;
            i = i + 1;
        }
        adv();
    }

    wordLength(*w) = i; 

    if (wordLength(*w) < min) {
        return INVALID_INPUT;
    } else {
        return VALID_INPUT;
    }

}

int multiWordInput(List *input, int min, int count) {

    startKata(false,"");

    int i = 0;
    while (!endKata && i < count) {
        insertAt(input,currentKata,i);
        advKata();
        i = i + 1;
    }

    if (length(*input) < min) {
        return INVALID_INPUT;
    } else {
        return VALID_INPUT;
    }

}
