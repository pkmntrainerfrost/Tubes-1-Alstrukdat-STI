#include "list.h"
#include <stdlib.h>

void createList(List *l) {

    l->buffer = (LElType*) malloc (DEFAULT_CAPACITY * sizeof(LElType));
    l->capacity = DEFAULT_CAPACITY;
    l->nEff = 0;

}

void deleteList(List *l) {

    free(l->buffer);

}

boolean isEmpty(List l) {

    return (l.nEff == 0);

}

boolean length(List l) {

    return (l.nEff);

}

LElType getElmt(List l, int i) {

    return (l.buffer[i]);

}

void setElmt(List *l, int i, LElType v) {


    l->buffer[i] = v;

}

int indexOf(List l, LElType v);

void insertFirst(List *l, LElType v);

void insertAt(List *l, LElType v, int i);

void insertLast(List *l, LElType v);

void deleteFirst(List *l, LElType *v);

void deleteAt(List *l, LElType *v, int i);

void deleteLast(List *l, LElType *v);
