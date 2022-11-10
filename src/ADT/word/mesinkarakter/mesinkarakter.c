/* FILE         : mesinkarakter.c */
/* DESKRIPSI    : Implementasi ADT Mesin Karakter */

#include <stdio.h>
#include "mesinkarakter.h"

char cc;

boolean isFile;
boolean eoi;

static FILE *file;
static int retval;

void start(boolean fileInput, char *filename) {

    isFile = fileInput;

    if (fileInput) {
        file = fopen(filename,"r");
    } else {
        file = stdin;
    }
    
    adv();

}

void adv() {    

    retval = fscanf(file, "%c", &cc);

    if (isFile) {
        eoi = (retval != 1);
    } else {
        eoi = (cc == INPUTMARK);
    }

    if (isFile && eoi) {
        fclose(file);
    }

}