/* File         : mesinkar.h */
/* Deskripsi    : Header Game Battleship */

#ifndef __BATTLESHIP__
#define __BATTLESHIP__

#include "../ADT/point.h"
#include "../boolean.h"

#define CAPACITY : integer = 100;

typedef struct {
    boolean ship;
    boolean shot;
} Tile;

#define SHIP(t) (t).ship
#define SHOT(t) (t).shot

typedef struct {
    Tile tiles[100];
} Grid;

#define TILE(g,p) (g).tiles[((ABSICSSA(p) - 1) * 10 + (ORDINATE(p)) - 1)]

void initializeGrid(Grid *G);

#endif