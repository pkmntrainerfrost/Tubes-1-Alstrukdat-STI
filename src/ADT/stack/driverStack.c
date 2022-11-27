#include <stdio.h>
#include "stack.h"

int main()
{
    Stack S;
    CreateEmptyStack(&S);
    if (IsEmptyStack(S)){
        printf("Stack kosong\n");
    } else {
        printf("Stack tidak kosong\n");
    }
    Push(&S, 5);
    Push(&S, 3);
    Push(&S, 1);
    infotype X;
    Pop(&S, &X);
    return 0;
}

// compile : gcc src/ADT/stack/stack.c src/ADT/stack/driverStack.c -o driver