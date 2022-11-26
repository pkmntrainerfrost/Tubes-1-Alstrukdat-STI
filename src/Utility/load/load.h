#ifndef __LOAD__
#define __LOAD__

#include "../../ADT/boolean.h"
#include "../../ADT/list/array.h"
#include "../../ADT/word/word.h"
#include "../../ADT/word/mesinkata/mesinkata.h"
#include "../../ADT/map/listMap.h"


void LOAD(Word filename, List *ListGame, List *listHist, ListMap *listMapGame);

boolean CHECKFILE(Word filename);

#endif