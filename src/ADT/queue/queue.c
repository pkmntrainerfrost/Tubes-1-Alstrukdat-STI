#include "queue.h"
#include <stdlib.h>

Address newNode(QElType x) {

    Address a = (Address) malloc(sizeof(Node));

    if (a != NULL) {
        INFO(a) = x;
        NEXT(a) = NULL;
    }

    return a;

}

boolean isEmpty(Queue q) {

    return (ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL);

}

void createQueue(Queue *q) {

    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;

}

void enqueue(Queue *q, QElType x) {

    Address a = newNode(x);

    if (a != NULL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = a;
        } else {
            NEXT(ADDR_TAIL(*q)) = a;
        }
        ADDR_TAIL(*q) = a;   
    }

}

void dequeue(Queue *q, QElType *x) {

    *x = HEAD(*q);
    Address a = ADDR_HEAD(*q);

    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    if (ADDR_HEAD(*q) == NULL) {
        ADDR_TAIL(*q) = NULL;
    }

    free(a);

}