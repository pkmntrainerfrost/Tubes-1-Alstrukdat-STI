#ifndef __HANGMAN__
#define __HANGMAN__

#include "man.h"
#include "../../ADT/boolean.h"
#include "../../ADT/list/array.h"
#include "../../ADT/word/mesinkata/mesinkata.h"
#include "../../ADT/word/word.h"
#include "../../Misc/ascii/ascii.h"
#include "../../Misc/io/io.h"
#include "../../Utility/splash.h"
#include "../random.h"

void inputGuess(List Guesses, Word *guess);

void displayKata(List L);

void toContinue();

void readListKata(List *ListKata);

void addToListKata(List *L);

void saveListKata(List L);

void playHangman(List L);

void hangman();

#endif