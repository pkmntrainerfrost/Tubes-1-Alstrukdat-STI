/* File         : mesinkar.h */
/* Deskripsi    : Header ADT Mesin Kata */

#ifndef __MESINKATA__
#define __MESINKATA__

#include "mesinkar.h"

#define N_MAX 50
#define BLANK ' '

typedef struct {
    char buffer[N_MAX];
    int length;
} Word;

extern boolean endKata;
extern Word currentKata;

void ignoreBlank();

void startKata();

void advKata();

void salinKata();

#endif