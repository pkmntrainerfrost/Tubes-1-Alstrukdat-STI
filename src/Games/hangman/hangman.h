#ifndef __HANGMAN__
#define __HANGMAN__


#include "../../ADT/boolean.h"
#include "../../ADT/list/array.h"
#include "../../ADT/word/mesinkata/mesinkata.h"
#include "../../ADT/word/word.h"
#include "../../Misc/ascii/ascii.h"
#include "../../Misc/io/io.h"

void hangman();

void inputGuess(List Guesses, Word *guess);

void displayKata(List L);

#endif