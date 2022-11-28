#include "stack.h"
#include "../../ADT/boolean.h"
#include <stdio.h>

void CreateEmpty(Stack *S){
    Top(*S) = Nill;
}

boolean IsEmptyStack(Stack S){
    return Top(S) == Nill;
}

boolean IsFullStack(Stack S){
    return Top(S) == MaxEl-1;
}

void Push(Stack * S, infotype X){
    Top(*S) += 1;
    InfoTop(*S) = X;
}

void Pop(Stack * S, infotype* X){
    (*X) = InfoTop(*S);
    Top(*S) -= 1;
}

Stack CopyStack(Stack S){
    Stack temp, B;
    CreateEmpty(&temp);
    CreateEmpty(&B);

    while (!IsEmptyStack((S))){
        int popped;
        Pop(&S, &popped);
        Push(&temp, popped);
    }

    while (!IsEmptyStack((temp))){
        int popped;
        Pop(&temp, &popped);
        Push(&B, popped);
    }

    return B;
}