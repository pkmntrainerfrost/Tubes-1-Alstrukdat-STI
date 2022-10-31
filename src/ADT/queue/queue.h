/* File : queue.h */
/* Deskripsi : Queue Struktur Berkait */

#ifndef __QUEUE__
#define __QUEUE__

#include "../boolean.h"
#include <stdlib.h>

#define NIL NULL
 
typedef union {

    int integer;
    char character;

    // definisikan elemen2 queue lainnya yang dibutuhkan

} QElType;

typedef struct node* Address;

typedef struct node {
    
    QElType info;
    Address next;

} Node;

typedef struct {

    Address addrHead;
    Address addrTail;

} Queue;

#define NEXT(n) (n)->next
#define INFO(n) (n)->info

#define ADDR_HEAD(q) (q).addrHead
#define ADDR_TAIL(q) (q).addrTail
#define      HEAD(q) (q).addrHead->info

Address newNode(QElType x);

boolean isEmpty(Queue q);

void createQueue(Queue *q);

void enqueue(Queue *q, QElType x);

void dequeue(Queue *q, QElType *x);

#endif