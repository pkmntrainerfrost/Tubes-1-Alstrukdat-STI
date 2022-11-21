#ifndef __LOAD__
#define __LOAD__

#include "../../ADT/boolean.h"
#include "../../ADT/list/array.h"
#include "../../ADT/word/word.h"
#include "../../ADT/word/mesinkata/mesinkata.h"


void LOAD(Word filename, List *ListGame, List *listHist);

boolean CHECKFILE(Word filename);

#endif