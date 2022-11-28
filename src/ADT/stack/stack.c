#include <stdio.h>
#include "stack.h"

void CreateEmptyStack(Stack *S){
    Top(*S) = Nill;
}

boolean IsEmptyStack(Stack S){
    return Top(S) == Nill;
}

boolean IsFullStack(Stack S){
    return Top(S) == MaxEl-1;
}

void Push(Stack * S, infotypeStack X){
    Top(*S) += 1;
    InfoTop(*S) = X;
}

void Pop(Stack * S, infotypeStack* X){
    (*X) = InfoTop(*S);
    Top(*S) -= 1;
}

Stack CopyStack(Stack S){
    Stack temp, B;
    CreateEmptyStack(&temp);
    CreateEmptyStack(&B);

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