#ifndef __LIST__
#define __LIST__

#include "../boolean.h"
#include <stdlib.h>

typedef union {

    int integer;
    char character;

    // definisikan jenis2 elemen2 list lainnya yang dibutuhkan

} LElType;

typedef struct {

    LElType buffer[100];
    int nEff;

} List;

void createList(List *l);

boolean isEmpty(List l);

boolean length(List l);

LElType getElmt(List l, int i);

void setElmt(List *l, int i, LElType v);



#endif