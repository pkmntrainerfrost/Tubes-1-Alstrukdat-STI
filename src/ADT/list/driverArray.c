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
    if (isElTypeEqual(test, test1)) {
        printf("Sama\n");
    } else {
        printf("Tidak sama\n");
    }
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
    insertFirst(&L, test1);
    printf("%d\n", indexOf(L, test1));
    printf("%d\n", length(L));
    updateCapacity(&L);
    printf("%d\n", length(L));
    printf("%s\n", wordToString(getElmt(L, 0)));
    setElmt(&L, 0, test2);
    ElType get;
    get = getElmt(L, 0);
    printf("%s\n", get.buffer);
    displayList(L);
    test1 = stringToWord("hai");
    if (isElTypeEqual(test, test1)) {
        printf("Sama\n");
    } else {
        printf("Tidak sama\n");
    }
    displayList(L);
    deleteFirst(&L);
    displayList(L);
    deleteLast(&L);
    displayList(L);
    deallocateList(&L);
    displayList(L);
    return 0;
}