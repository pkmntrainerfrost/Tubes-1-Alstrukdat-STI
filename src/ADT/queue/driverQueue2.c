#include <stdio.h>
#include "queue2.h"

int main()
{
    Queue Q;
    QElType X;
    createQueue(&Q);
    printf("(kosong)\n");
    displayQueue(Q);
    // queue kosong
    X.length = 3;
    X.buffer[0] = 'h';
    X.buffer[1] = 'a';
    X.buffer[2] = 'i';
    enqueue(&Q, X);
    printf("(hai)\n");
    displayQueue(Q);
    printf("(1)\n");
    printf("%d\n", Q.MaxEl);
    QElType Y;
    Y.length = 3;
    Y.buffer[0] = 'w';
    Y.buffer[1] = 'o';
    Y.buffer[2] = 'w';
    enqueue(&Q, Y);
    printf("(hai, wow)\n");
    displayQueue(Q);
    printf("(2)");
    printf("%d\n", Q.MaxEl);
    dequeue(&Q, &X);
    printf("(wow)\n");
    displayQueue(Q);
    printf("(wow)\n");
    printf("%s\n", Front(Q).buffer);
    printf("(2)\n");
    printf("%d\n", Q.MaxEl);
    if (isMember(Q, X)){
        printf("hai ada\n");
    } else {
        printf("hai ga ada\n");
    }
    enqueue(&Q, X);
    if(isMember(Q, X)){
        printf("hai ada\n");
    } else {
        printf("hai ga ada\n");
    }
    printf("(wow)");
    printf("%s\n", Front(Q).buffer);
    return 0;
}

//compile: gcc ADT/queue/driverQueue2.c ADT/queue/queue2.c ADT/mesinkar/mesinkata_input.c ADT/mesinkar/mesinkar_input.c -o coba