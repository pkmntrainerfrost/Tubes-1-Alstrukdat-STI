#ifndef __LISTSET__
#define __LISTSET__

#include "../boolean.h"
#include "set.h"

#define Nil 0
#define defaultSizeSet 10

#define ElTypeSet Set

typedef struct {
    ElTypeSet *ElmtListSet;
    int nEff;
    int capacityListSet;
} ListSet;

void createListSet(ListSet *L);

void deallocateListSet(ListSet *L);

void updateCapacityListSet(ListSet *L);

boolean isEmptyListSet(ListSet L);

boolean isFullListSet(ListSet L);

void insertListSet(ListSet *L, Set S);

void deleteListSet(ListSet *L, int idx);

boolean insertElmt(ListSet *L, int idx, infotypeSet Elmt);
// true jika elmt list tidak ada di set dalam list set lalu menambah elmt ke set dalam list set
// false jika elmt list sudah ada di set dalam list set. Mengeluarkan pesan eror, list set tetap.

void displayListSet(ListSet S);

#endif