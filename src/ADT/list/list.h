#ifndef __LIST__
#define __LIST__

#include "../boolean.h"
#include <stdlib.h>

#define DEFAULT_CAPACITY 10
#define IDX_UNDEF -1

typedef union {

    int integer;
    char character;

    // definisikan jenis2 elemen2 list lainnya yang dibutuhkan

} LElType;

typedef struct {

    LElType *buffer;
    int capacity;
    int nEff;

} List;

void createList(List *l);

void deleteList(List *l);

boolean isLElTypeEqual(LElType l1, LElType l2);

boolean isEmpty(List l);

boolean length(List l);

LElType getElmt(List l, int i);

void setElmt(List *l, int i, LElType v);

int indexOf(List l, LElType v);

void insertFirst(List *l, LElType v);

void insertAt(List *l, LElType v, int i);

void insertLast(List *l, LElType v);

void deleteFirst(List *l, LElType *v);

void deleteAt(List *l, LElType *v, int i);

void deleteLast(List *l, LElType *v);

void updateCapacity(List *l, boolean condition, int newCapacity);

#endif