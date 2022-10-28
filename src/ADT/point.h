/* File         : mesinkar.h */
/* Deskripsi    : Header ADT Mesin Kata */

#ifndef __POINT__
#define __POINT__

#include "../boolean.h"

typedef struct {
    int x;
    int y;
} Point;

#define ABSICSSA(p) (p).x
#define ORDINATE(p) (p).y

void createPoint(Point *P , int x, int y);

boolean isOrigin(Point P);

void readPoint(Point *P);

void displayPoint(Point *P);

Point movePoint(Point P, int dx, int dy);

#endif