#include <stdio.h>
#include "linkedList.h"

int main()
{
    LinkedList LL;
    createLL(&LL);

    Point P;
    createPoint(&P, 1, 2);

    Address x = allocateNode(P);
    insertFirstLL(&LL, x);

    createPoint(&P, 3, 4);
    insVLastLL(&LL, P);

    deleteLastLL(&LL, &x);
    P = getElmtLL(LL, 1);

    setElmtLL(&LL, 1, P);

    Address y = searchLL(LL, P);

    printf("%d\n", lengthLL(LL));

    return 0;
}