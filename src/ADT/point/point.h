/* File         : mesinkar.h */
/* Deskripsi    : Header ADT Mesin Kata */

#ifndef __POINT__
#define __POINT__

#include "../boolean.h"

typedef struct {
    int x;
    int y;
} Point;

#define ABSCISSA(p) (p).x
#define ORDINATE(p) (p).y

void createPoint(Point *p , int x, int y);

boolean isOrigin(Point p);

boolean isFirstQuadrant(Point p);

Point translate(Point p, int dx, int dy);

void movePoint(Point *p, int dx, int dy);

#endif