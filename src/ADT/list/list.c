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

boolean isLElTypeEqual(LElType l1, LElType l2) {

    return (l1 == l2);

}

boolean isEmpty(List l) {

    return (l.nEff == 0);

}

boolean isFull(List l) {

    return (l.nEff == l.capacity);

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

int indexOf(List l, LElType v) {

    boolean found = false;
    int i = 0;

    while (i < length(l) && !false) {
        if (isLElTypeEqual(getElmt(l,i),v)) {
            found = true;
        }
        i++;
    }

    if (found) {
        return (i - 1);
    } else {
        return (IDX_UNDEF);
    }

}

void insertFirst(List *l, LElType v) {

    updateCapacity(l, isFull(*l), l->capacity * 2);

    for (int i = length(*l); i > 0; i--) {
        l->buffer[i] = l->buffer[i - 1];
    }

    l->buffer[0] = v;
    l->nEff = length(*l) + 1;

}

void insertAt(List *l, LElType v, int i) {

    updateCapacity(l, isFull(*l), l->capacity * 2);

    for (int j = length(*l); j > i; j--) {
        l->buffer[j] = l->buffer[j - 1];
    }

    l->buffer[i] = v;
    l->nEff = length(*l) + 1;

}

void insertLast(List *l, LElType v) {

    updateCapacity(l, isFull(*l), l->capacity * 2);

    l->buffer[length(*l)] = v;
    l->nEff = length(*l) + 1;

}

void deleteFirst(List *l, LElType *v) {

    updateCapacity(l, (length(*l) < l->capacity / 2) && (l->capacity > DEFAULT_CAPACITY), l->capacity / 2);

    *v = getElmt(*l,0);

    for (int i = 0; i < length(*l) - 1; i++) {
        l->buffer[i] = l->buffer[i + 1];
    }

    l->nEff = length(*l) - 1;

}

void deleteAt(List *l, LElType *v, int i) {

    updateCapacity(l, (length(*l) < l->capacity / 2) && (l->capacity > DEFAULT_CAPACITY), l->capacity / 2);

    *v = getElmt(*l,i);

    for (int j = i; j < length(*l) - 1; j++) {
        l->buffer[j] = l->buffer[j + 1];
    }

    l->nEff = length(*l) - 1;

}

void deleteLast(List *l, LElType *v) {

    updateCapacity(l, (length(*l) < l->capacity / 2) && (l->capacity > DEFAULT_CAPACITY), l->capacity / 2);

    *v = getElmt(*l,length(*l) - 1);

    l->nEff = length(*l) - 1;

}

void updateCapacity(List *l, boolean condition, int newCapacity) {

    if (condition) {

        LElType *newBuffer = (LElType*) malloc (newCapacity * sizeof(LElType));

        for (int i = 0; i < length(*l); i++) {
            newBuffer[i] = getElmt(*l,i);
        }

        free(l->buffer);

        l->buffer = (LElType*) malloc (newCapacity * sizeof(LElType));

        for (int i = 0; i < length(*l); i++) {
            l->buffer[i] = newBuffer[i];
        }

        free(newBuffer);

        l->capacity = newCapacity;

    }

}
