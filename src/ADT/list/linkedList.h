#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "../boolean.h"
#include "../point/point.h"

#include <stdlib.h>

#define NIL NULL

typedef struct tNode* Address;

typedef struct tNode {
    Point info;
    Address next;
    Address prev;
} Node;

typedef struct {
    Address first;
    Address last;
} LinkedList;

#define LLFirst(ll) ((ll).first)
#define LLLast(ll) ((ll).last)
#define LLInfo(A) (A)->info
#define LLNext(A) (A)->next
#define LLPrev(A) (A)->prev

boolean isEmptyLL(LinkedList LL);

Address allocateNode(Point P);

void deallocateNode(Address A);

void createLL(LinkedList *LL);

void insVFirstLL(LinkedList *LL, Point P);

void insVLastLL(LinkedList *LL, Point P);

void dekVFirstLL(LinkedList *LL, Point *P);

void delVLastLL(LinkedList *LL, Point *P);

void insertFirstLL(LinkedList *LL, Address A);

void insertLastLL(LinkedList *LL, Address A);

void insertBeforeLL(LinkedList *LL, Address A, Address Prec);

void insertAfterLL(LinkedList *LL, Address A, Address Succ);

void deleteFirstLL(LinkedList *LL, Address *A);

void deleteLastLL(LinkedList *LL, Address *A);

void deleteBeforeLL(LinkedList *LL, Address *A, Address Prec);

void deleteAfterLL(LinkedList *LL, Address *A, Address Succ);

Point getElmtLL(LinkedList LL, int I);

void setElmtLL(LinkedList *LL, int I, Point P);

Address searchLL(LinkedList LL, Point P);

int lengthLL(LinkedList LL);

#endif