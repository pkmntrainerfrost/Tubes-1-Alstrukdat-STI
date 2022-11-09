#include <stdio.h>
#include <stdlib.h>
#include "circularqueue.h"

boolean IsEmpty (Queue Q)
{
    return (Q.HEAD == NIL && Q.TAIL == NIL);
}

boolean IsFull (Queue Q)
{
    return (Length(Q) == Q.MaxEl);
}

int Length (Queue Q)
{
    if (IsEmpty(Q)){
        return 0;
    } else {
        if (Q.HEAD <= Q.TAIL){
            return (Q.TAIL - Q.HEAD + 1);
        } else { // Q.HEAD > Q.TAIL
            return (Q.MaxEl - (Q.HEAD - Q.TAIL - 1));
        }
    }
}

int MaxLength (Queue Q)
{
    return (Q.MaxEl);
}

void createQueue (Queue *Q)
{
    (*Q).Tab = (ElType *) malloc (defaultCapacity * sizeof(ElType));
    if ((*Q).Tab == NULL){
        (*Q).MaxEl = 0;
    } else {
        (*Q).HEAD = NIL;
        (*Q).TAIL = NIL;
        (*Q).MaxEl = defaultCapacity;
    }
}

void DeleteQueue (Queue * Q)
{
    (*Q).HEAD = NIL;
    (*Q).TAIL = NIL;
    (*Q).MaxEl = 0;
    free((*Q).Tab);
}

void enqueue (Queue * Q, ElType X)
{
    if (IsEmpty(*Q)){
        (*Q).HEAD = 0;
        (*Q).TAIL = 0;
    } else {
        if ((*Q).TAIL == (*Q).MaxEl-1){
            (*Q).TAIL = 0;
        } else {
            (*Q).TAIL++;
        }
    }
    (*Q).Tab[(*Q).TAIL] = X;
}

ElType dequeue (Queue * Q)
{
    ElType val = Front(*Q);
    if(Length(*Q) == 1){
        (*Q).HEAD = NIL;
        (*Q).TAIL = NIL;
    } else {
        (*Q).HEAD = ((*Q).HEAD + 1) % (*Q).MaxEl;
    }
    return val;
}

ElType Front (Queue Q)
{
    return Q.Tab[Q.HEAD];
}     

boolean isMember(Queue Q, ElType X)
{
    int i;
    if (IsEmpty(Q)){
        return false;
    } else {
        if (Q.HEAD <= Q.TAIL){
            for (i = Q.HEAD; i <= Q.TAIL; i++){
                if (Q.Tab[i].length == X.length){
                    int j; 
                    for (j=0; j<X.length; j++){
                        if (Q.Tab[i].buffer[j] != X.buffer[j]){
                            return false;
                        }
                    }
                    return true;
                }
            }
        } else { // Q.HEAD > Q.TAIL
            for (i = Q.HEAD; i <= Q.MaxEl-1; i++){
                if (Q.Tab[i].length == X.length){
                    int j; 
                    for (j=0; j<X.length; j++){
                        if (Q.Tab[i].buffer[j] != X.buffer[j]){
                            return false;
                        }
                    }
                    return true;
                }
            }
            for (i = 0; i <= Q.TAIL; i++){
                if (Q.Tab[i].length == X.length){
                    int j; 
                    for (j=0; j<X.length; j++){
                        if (Q.Tab[i].buffer[j] != X.buffer[j]){
                            return false;
                        }
                    }
                    return true;
                }
            }
        }
    }
    return false;
}