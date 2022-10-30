/* File         : mesinkar.h */
/* Deskripsi    : Header Game Battleship */

#ifndef __BATTLESHIP__
#define __BATTLESHIP__

#include "../ADT/point.h"
#include "../boolean.h"

#define TILECOUNT 100
#define SHIPCOUNT 5

typedef struct {
    boolean ship;
    boolean shot;
} Tile;

#define HAS_SHIP(t) (t).ship
#define WAS_SHOT(t) (t).shot

typedef struct {
    char *name;
    Point position;
    boolean vertical;
    boolean sunk;
    int length;
} Ship;

#define POSITION(s) (s).position
#define SUNK(s) (s).sunk
#define SHIPLENGTH(s) (s).length

typedef struct {
    Tile tiles[TILECOUNT];
    Ship ships[SHIPCOUNT];
} Grid;

#define TILE(g,p) (g).tiles[((ABSICSSA(p) - 1) * 10 + (ORDINATE(p)) - 1)]
#define SHIP(g,i) (g).ships[i]

/*

#define CAPACITY : integer = 100;

typedef struct {
    boolean ship;
    boolean shot;
} Tile;

#define SHIP(t) (t).ship
#define SHOT(t) (t).shot

typedef struct {
    Point position;
    boolean vertical;
    boolean sunk;
    int length;
} Ship;

#define SUNK(s) (s).sunk 

typedef struct {
    Tile tiles[100];
    Ship carrier;
    Ship battleship;
    Ship cruiser;
    Ship submarine;
    Ship destroyer;
} Grid;

#define TILE(g,p) (g).tiles[((ABSICSSA(p) - 1) * 10 + (ORDINATE(p)) - 1)]

void initializeGrid(Grid *G);

*/


#endif