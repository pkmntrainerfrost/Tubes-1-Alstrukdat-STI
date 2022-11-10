#include <stdio.h>
#include <stdlib.h>
#include "queue2.h"

void createQueue (Queue *Q)
{
    (*Q).Tab = (QElType *) malloc (defaultCapacity * sizeof(QElType));
    if ((*Q).Tab == NULL){  // Alokasi gagal
        (*Q).MaxEl = 0;
    } else {
        (*Q).HEAD = IDX_UNDEF;
        (*Q).TAIL = IDX_UNDEF;
        (*Q).MaxEl = defaultCapacity;
    }
}

boolean IsEmpty (Queue Q)
{
    return (Q.HEAD == IDX_UNDEF && Q.TAIL == IDX_UNDEF);
}

boolean IsFull (Queue Q)
{
    return (Length(Q) == Q.MaxEl);
}

int Length (Queue Q)
{
    return (Q.TAIL - Q.HEAD + 1);
}

void DeleteQueue (Queue *Q)
{
    (*Q).HEAD = IDX_UNDEF;
    (*Q).TAIL = IDX_UNDEF;
    (*Q).MaxEl = 0;
    free((*Q).Tab);
}

void updateCapacity(Queue *Q)
{
    int newCapacity = (*Q).MaxEl * 2;
    QElType *newTab = (QElType *) malloc (newCapacity * sizeof(QElType));
    if (newTab != NULL){        // Alokasi berhasil
        int i = 0;
        while (i < (*Q).MaxEl){
            newTab[i] = (*Q).Tab[i];
            i++;
        }

        free((*Q).Tab);

        (*Q).Tab = (QElType *) malloc (newCapacity * sizeof(QElType));
        i = 0;
        while (i < (*Q).MaxEl){
            (*Q).Tab[i] = newTab[i];
            i++;
        }

        free(newTab);

        (*Q).MaxEl = newCapacity;
    }
}

void enqueue (Queue * Q, QElType X)
{
    if (IsEmpty(*Q)){
        (*Q).HEAD = 0;
        (*Q).TAIL = 0;
    } else {
        if ((*Q).TAIL == ((*Q).MaxEl - 1)){
            if (IsFull(*Q)){
                updateCapacity(Q);
            } else {        // queue penuh semu
                int i;
                for (i = (*Q).HEAD; i<=(*Q).TAIL; i++){
                    (*Q).Tab[i-(*Q).HEAD] = (*Q).Tab[i];
                }
                (*Q).TAIL -= (*Q).HEAD;
                (*Q).HEAD = 0;
            }
        }
        (*Q).TAIL++;  
    }
    (*Q).Tab[(*Q).TAIL] = X;
}

void dequeue (Queue *Q, QElType *X)
{
    *X = Front(*Q);
    if(Length(*Q) == 1){
        (*Q).HEAD = IDX_UNDEF;
        (*Q).TAIL = IDX_UNDEF;
    } else {
        (*Q).HEAD++;
    }
}

QElType Front (Queue Q)
{
    return Q.Tab[Q.HEAD];
}     

boolean isSameWord(QElType X, QElType Y)
{
    if (X.length == Y.length){
        int i;
        for(i=0; i<X.length;i++){
            if(X.buffer[i] != Y.buffer[i]){
                return false;
            }
        }       
    } else {
        return false;
    }
    return true;
}

boolean isMember(Queue Q, QElType X)
{
    int i = Q.HEAD;
    while (i <= Q.TAIL){
        if (isSameWord(Q.Tab[i], X)){
            return true;
        }
        i++;
    }
    return false;
}

void displayQueue(Queue Q)
{
    if (IsEmpty(Q)){
        printf("Queue kosong\n");
    } else {
        int i;
        printf("[");
        printf("%s", Q.Tab[Q.HEAD].buffer);
        for (i = Q.HEAD+1; i<=Q.TAIL; i++){
            printf(", %s", Q.Tab[i].buffer);
        }
        printf("]\n");
    }
}

// int main()
// {
//     Queue Q;
//     QElType X;
//     createQueue(&Q);
//     printf("(kosong)\n");
//     displayQueue(Q);
//     // queue kosong
//     X.length = 3;
//     X.buffer[0] = 'h';
//     X.buffer[1] = 'a';
//     X.buffer[2] = 'i';
//     enqueue(&Q, X);
//     printf("(hai)\n");
//     displayQueue(Q);
//     printf("(1)\n");
//     printf("%d\n", Q.MaxEl);
//     QElType Y;
//     Y.length = 3;
//     Y.buffer[0] = 'w';
//     Y.buffer[1] = 'o';
//     Y.buffer[2] = 'w';
//     enqueue(&Q, Y);
//     printf("(hai, wow)\n");
//     displayQueue(Q);
//     printf("(2)");
//     printf("%d\n", Q.MaxEl);
//     dequeue(&Q, &X);
//     printf("(wow)\n");
//     displayQueue(Q);
//     printf("(wow)\n");
//     printf("%s\n", Front(Q).buffer);
//     printf("(2)\n");
//     printf("%d\n", Q.MaxEl);
//     if (isMember(Q, X)){
//         printf("hai ada\n");
//     } else {
//         printf("hai ga ada\n");
//     }
//     enqueue(&Q, X);
//     if(isMember(Q, X)){
//         printf("hai ada\n");
//     } else {
//         printf("hai ga ada\n");
//     }
//     printf("(wow)");
//     printf("%s\n", Front(Q).buffer);
//     return 0;
// }

//compile: gcc ADT/queue/queue2.c ADT/mesinkar/mesinkata_input.c ADT/mesinkar/mesinkar_input.c -o coba