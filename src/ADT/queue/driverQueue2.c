#include <stdio.h>
#include "queue2.h"
#include "../word/word.h"

int main()
{
    Queue Q;
    QElType X, Y;
    createQueue(&Q);
    X = stringToWord("hai");
    enqueue(&Q, X);
    displayQueue(Q);
    printf("%d\n", Q.MaxEl);
    Y = stringToWord("halo");
    enqueue(&Q, Y);
    printf("%d\n", Q.MaxEl);
    dequeue(&Q, &X);
    displayQueue(Q);
    printf("%s\n", Front(Q).buffer);
    if (isMember(Q, X)){
        printf("hai ada\n");
    } else {
        printf("hai ga ada\n");
    }
    return 0;
}