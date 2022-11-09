#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void createList(List *L)
{
    (*L).A = (ElType*) malloc (initialSize * sizeof(ElType));
    (*L).capacity = initialSize;
    (*L).nEff = 0;
}

void deallocateList(List *L)
{
    free((*L).A);
    (*L).capacity = 0;
    (*L).nEff = 0;
}

boolean isElTypeEqual(ElType l1, ElType l2)
{
    if (l1.length == l2.length){
        int i = 0;
        while (i < l1.length){
            if (l1.buffer[i] != l2.buffer[i]){
                return false;
            }
            i++;
        }
        return true;
    }
}

boolean isEmpty(List L)
{
    return (L.nEff == 0);
}

boolean isFull(List L)
{
    return (L.nEff == L.capacity);
}

int length(List L)
{
    return (L.nEff);
}

ElType getElmt(List L, int i)
{
    return (L.A[i]);
}

void setElmt(List *L, int i, ElType X)
{
    (*L).A[i] = X;
}

int indexOf(List L, ElType X)
{
    boolean found = false;
    int i = 0;

    while (i < length(L) && !found) {
        if (isElTypeEqual(getElmt(L,i),X)) {
            found = true;
        } else {
            i++;
        }
    }

    if (found) {
        return i;
    } else {
        return -1;
    }
}

void updateCapacity(List *L)
{
    int newCapacity = 2 * (*L).capacity;

    ElType *newBuffer = (ElType*) malloc (newCapacity * sizeof(ElType));

    int i;
    for(i = 0; i < length(*L); i++){
        newBuffer[i] = getElmt(*L,i);
    }

    free((*L).A);
    
    (*L).A = (ElType*) malloc (newCapacity * sizeof(ElType));

    for(i = 0; i < length(*L); i++){
        (*L).A[i] = newBuffer[i];
    }

    free(newBuffer);

    (*L).capacity = newCapacity;
}

void insertFirst(List *L, ElType X)
{
    if (isFull(*L)) {
        updateCapacity(L);
    }
    
    insertAt(L, X, 0);
}

void insertAt(List *L, ElType X, int idx)
{
    if (isFull(*L)) {
        updateCapacity(L);
    }

    int i;
    for (i = length(*L); i > idx; i--) {
        (*L).A[i] = (*L).A[i-1];
    }
    (*L).A[idx] = X;
    (*L).nEff++;
}

void insertLast(List *L, ElType X)
{
    insertAt(L, X, length(*L));
}

void deleteFirst(List *L)
{
    deleteAt(L, 0);
}

void deleteAt(List *L, int idx)
{
    int i;
    for (i = idx; i < length(*L); i++) {
        (*L).A[i] = (*L).A[i+1];
    }
    (*L).nEff--;
}

void deleteLast(List *L)
{
    deleteAt(L, length(*L)-1);
}

void printList(List L)
{
    int i;
    printf("[");
    printf("%d", L.A[0]);
    for (i = 0; i < length(L); i++) {
        printf(", %d", L.A[i]);
    }
    printf("]");
}