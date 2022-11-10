/* File         : mesinkar.c */
/* Deskripsi    : Implementasi ADT Mesin Karakter */

#include <stdio.h>
#include <stdlib.h>
#include "mesinkar.h"

char cc;
boolean eoi;

static FILE *file;
static int retval;

void start(char *filename) {

    file = stdin;
    adv();

}

void adv() {

    retval = fscanf(file, "%c", &cc);
    eoi = (cc == MARK);
    if (eoi) {
        fclose(file);
    }

}