/* File         : mesinkar.h */
/* Deskripsi    : Header ADT Mesin Kata */

#ifndef __MESINKATA_INPUT__
#define __MESINKATA_INPUT__

#include "../word.h"

extern boolean endKataInput;
extern Word currentKataInput;

void ignoreBlankInput();

void startKataInput();

void advKataInput();

void salinKataInput();

#endif