#include "stack.h"

void CreateEmptyStack(Stack *S){
    Top(*S) = Nil;
}

boolean IsEmptyStack(Stack S){
    return Top(S) == Nil;
}

boolean IsFullStack(Stack S){
    return Top(S) == 0;
}

void Push(Stack * S, infotype X){
    Top(*S) -= 1;
    InfoTop(*S) = X;
}

void Pop(Stack * S, infotype* X){
    (*X) = InfoTop(*S);
    Top(*S) += 1;
}