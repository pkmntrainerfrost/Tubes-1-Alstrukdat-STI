/* File         : mesinkar.h */
/* Deskripsi    : Header Game Battleship */

#ifndef __BATTLESHIP__
#define __BATTLESHIP__

#include "../../ADT/point/point.h"
#include "../../ADT/boolean.h"
#include "../random.h"
#include "../../ADT/word/word.h"
#include "../../Misc/io/io.h"
#include "../../Utility/splash.h"

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

#define NAME(s) (s).name
#define POSITION(s) (s).position
#define VERTICAL(s) (s).vertical
#define SUNK(s) (s).sunk
#define SHIPLENGTH(s) (s).length

typedef struct {
    Tile tiles[TILECOUNT];
    Ship ships[SHIPCOUNT];
    boolean enemy;
} Grid;

#define TILE(g,p) (g).tiles[((ABSICSSA(p)) * 10 + (ORDINATE(p)))]
#define SHIP(g,i) (g).ships[i]
#define ENEMY(g)  (g).enemy

#endif