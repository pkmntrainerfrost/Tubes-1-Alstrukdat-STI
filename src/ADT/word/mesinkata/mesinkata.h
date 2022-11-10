/* File         : mesinkata.h */
/* Deskripsi    : Header ADT Mesin Kata */

#ifndef __MESINKATA__
#define __MESINKATA__

#include "../mesinkarakter/mesinkarakter.h"
#include "../word.h"

#define FILEBLANK '\n'
#define INPUTBLANK ' '

extern boolean endKata;
extern Word currentKata;

void ignoreBlank();

void startKata(boolean fileInput, char *filename);

void advKata();

void salinKata();

#endif