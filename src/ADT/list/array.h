#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "../../boolean.h"
#include "../mesinkar/mesinkata_input.h"

#define Nil NULL
#define initialSize 10

#define ElType Word

typedef struct {
    ElType *buffer;
    int nEff;
    int capacity;
} List;

void createList(List *L);

void deallocateList(List *L);

boolean isElTypeEqual(ElType l1, ElType l2);

boolean isEmpty(List L);

boolean isFull(List L);

int Length(List L);

ElType getElmt(List L, int i);

void setElmt(List *L, int i, ElType X);

int indexOf(List L, ElType X);

void updateCapacity(List *L);

void insertFirst(List *L, ElType X);

void insertAt(List *L, ElType X, int idx);

void insertLast(List *L, ElType X);

void deleteFirst(List *L);

void deleteAt(List *L, int idx);

void deleteLast(List *L);

void printList(List L);

#endif // __ARRAY_H__