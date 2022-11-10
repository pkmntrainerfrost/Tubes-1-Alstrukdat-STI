#include <stdio.h>
#include "array.h"
#include "../mesinkar/mesinkata_input.h"
#include "../../Misc/io/io.h"

int main()
{
    List L;
    createList(&L);
    if (isEmpty(L)) {
        printf("List kosong\n");
    }
    ElType test, test1, test2;
    test = stringToWord("hai");
    test1 = stringToWord("halo");
    test2 = stringToWord("oit");
    insertLast(&L, test);
    printf("%d\n", length(L));
    if (isEmpty(L)) {
        printf("List kosong\n");
    }
    if (isFull(L)) {
        printf("List penuh\n");
    } else {
        printf("List tidak penuh\n");
    }
    insertLast(&L, test1);
    printf("%d\n", length(L));
    printf("%s\n", wordToString(getElmt(L, 0)));
    setElmt(&L, 0, test2);
    displayList(L);
    return 0;
}

// void deallocateList(List *L);

// boolean isElTypeEqual(ElType l1, ElType l2);

// void setElmt(List *L, int i, ElType X);

// int indexOf(List L, ElType X);

// void updateCapacity(List *L);

// void insertFirst(List *L, ElType X);

// void insertAt(List *L, ElType X, int idx);

// void insertLast(List *L, ElType X);

// void deleteFirst(List *L);

// void deleteAt(List *L, int idx);

// void deleteLast(List *L);