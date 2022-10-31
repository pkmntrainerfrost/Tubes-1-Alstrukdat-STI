#include "point.h"

void createPoint(Point *p , int x, int y) {

    ABSCISSA(*p) = x;
    ORDINATE(*p) = y;

}

boolean isOrigin(Point p) {

    return (ABSCISSA(p) == 0 && ORDINATE(p) == 0);

}

boolean isFirstQuadrant(Point p) {

    return (ABSCISSA(p) > 0 && ORDINATE(p) > 0);

}

Point translate(Point p, int dx, int dy) {

    Point np;

    createPoint(&np, ABSCISSA(p) + dx, ORDINATE(p) + dy);

    return np;

}

void movePoint(Point *p, int dx, int dy) {

    ABSCISSA(*p) = ABSCISSA(*p) + dx;
    ORDINATE(*p) = ORDINATE(*p) + dy;

}