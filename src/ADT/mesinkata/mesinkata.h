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
} Kata;

extern boolean endKata;
extern Kata currentKata;

void ignoreBlank();

void startKata();

void advKata();

void salinKata();

#endif