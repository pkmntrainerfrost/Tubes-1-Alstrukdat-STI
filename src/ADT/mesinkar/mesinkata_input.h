/* File         : mesinkar.h */
/* Deskripsi    : Header ADT Mesin Kata */

#ifndef __MESINKATA_INPUT__
#define __MESINKATA_INPUT__

#include "mesinkar_input.h"

#define N_MAX 50
#define BLANK ' '

typedef struct {
    char buffer[N_MAX];
    int length;
} Word;

extern boolean endKataInput;
extern Word currentKataInput;

void ignoreBlankInput();

void startKataInput();

void advKataInput();

void salinKataInput();

#endif