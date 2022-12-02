#include <stdio.h>
#include "linkedList.h"

int main()
{
    printf("hai");
    LinkedList LL;
    createLL(&LL);

    printf("halo");
    Point P;
    createPoint(&P, 1, 2);

    printf("wuh");
    Address x = allocateNode(P);
    insertFirstLL(&LL, x);

    printf("yew");
    createPoint(&P, 3, 4);

    printf("haiii");
    insVLastLL(&LL, P);

    printf("hehe");
    // deleteLastLL(&LL, &x);
    deleteFirstLL(&LL, &x);
    P = getElmtLL(LL, 1);

    printf("hashda");
    setElmtLL(&LL, 1, P);

    printf("llele");
    Address y = searchLL(LL, P);
    if (y != NIL) {
        printf("P ada di LL\n");
    } else {
        printf("P tidak ada di LL\n");
    }

    printf("hai");

    printf("%d\n", lengthLL(LL));

    // gajalan
    printf("%d %d\n", ABSCISSA(getElmtLL(LL, lengthLL(LL))), ORDINATE(getElmtLL(LL, lengthLL(LL))));

    return 0;
}

// compile : gcc src/ADT/point/point.c src/ADT/list/linkedList.c src/ADT/list/driverLinkedList.c -o driver