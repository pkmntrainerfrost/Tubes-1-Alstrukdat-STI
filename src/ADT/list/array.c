#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void createList(List *L)
{
    (*L).buffer = (ElType*) malloc (initialSize * sizeof(ElType));
    (*L).capacity = initialSize;
    (*L).nEff = 0;
}

void deallocateList(List *L)
{
    free((*L).buffer);
    (*L).capacity = 0;
    (*L).nEff = 0;
}

boolean isElTypeEqual(ElType l1, ElType l2)
{
    if (l1.Length == l2.Length){
        int i = 0;
        while (i < l1.Length){
            if (l1.TabWord[i] != l2.TabWord[i]){
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

int Length(List L)
{
    return (L.nEff);
}

ElType getElmt(List L, int i)
{
    return (L.buffer[i]);
}

void setElmt(List *L, int i, ElType X)
{
    (*L).buffer[i] = X;
}

int indexOf(List L, ElType X)
{
    boolean found = false;
    int i = 0;

    while (i < Length(L) && !found) {
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
    (*L).capacity = (*L).capacity * 2;
    (*L).buffer = (ElType*) realloc ((*L).buffer, (*L).capacity * sizeof(ElType));
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
    for (i = Length(*L); i > idx; i--) {
        (*L).buffer[i] = (*L).buffer[i-1];
    }
    (*L).buffer[idx] = X;
    (*L).nEff++;
}

void insertLast(List *L, ElType X)
{
    insertAt(L, X, Length(*L));
}

void deleteFirst(List *L)
{
    deleteAt(L, 0);
}

void deleteAt(List *L, int idx)
{
    int i;
    for (i = idx; i < Length(*L); i++) {
        (*L).buffer[i] = (*L).buffer[i+1];
    }
    (*L).nEff--;
}

void deleteLast(List *L)
{
    deleteAt(L, Length(*L)-1);
}

void printList(List L)
{
    int i;
    printf("[");
    printf("%d", L.buffer[0]);
    for (i = 0; i < Length(L); i++) {
        printf(", %d", L.buffer[i]);
    }
    printf("]");
}