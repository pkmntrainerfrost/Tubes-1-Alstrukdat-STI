#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "../../boolean.h"
#include "../word/mesinkata/mesinkata.h"

#define Nil NULL
#define initialSize 10

#define ElType Word

typedef struct {
    ElType *A;
    int nEff;
    int capacity;
} List;

void createList(List *L);

void deallocateList(List *L);

boolean isElTypeEqual(ElType l1, ElType l2);

boolean isEmpty(List L);

boolean isFull(List L);

int length(List L);

ElType getElmt(List L, int i);

void updateCapacity(List *L);

void insertAt(List *L, ElType X, int idx);

void deleteAt(List *L, int idx);

void displayList(List L);

#endif // __ARRAY_H__