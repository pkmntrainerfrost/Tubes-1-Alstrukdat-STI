#include <stdio.h>
#include "array.h"
#include "../word/word.h"

int main()
{
    List L;
    createList(&L);
    if (isEmpty(L)) {
        printf("List kosong\n");
    }
    ElType test, test1;
    test = stringToWord("hai");
    test1 = stringToWord("halo");
    if (isElTypeEqual(test, test1)) {
        printf("Sama\n");
    } else {
        printf("Tidak sama\n");
    }
    insertFirst(&L, test);
    printf("%d\n", length(L));
    if (isFull(L)) {
        printf("List penuh\n");
    } else {
        printf("List tidak penuh\n");
    }
    insertLast(&L, test1);
    printf("%d\n", length(L));
    updateCapacity(&L);
    printf("%d\n", length(L));
    char *s;
    wordToString(getElmt(L, 0), s);
    printf("%s\n", s);
    deleteAt(&L, 0);
    displayList(L);
    deallocateList(&L);
    displayList(L);
    return 0;
}