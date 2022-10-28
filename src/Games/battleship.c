#include "battleship.h"

void initializeGrid(Grid *G) {

    int i = 0;

    for (int x = 1; x < 11; x++) {
        for (int y = 1; y < 11; y++) {

            Point P;
            createPoint(&P,x,y);

            SHIP(TILE(*G,P)) = false;
            SHOT(TILE(*G,P)) = false;

        }
    }

}

boolean shipPosValid(Point P, int Length, boolean Vertical) {
    
}

void placeShip(Grid *G, Point P, int Length, boolean Vertical) {

    /* Meletakkan kapal pada Grid */
    /* I.S. : G terinisialisasi, posisi kapal valid */
    /* F.S. : Kapal terletak dalam Grid */

    if (Vertical) {
        for (int i = 0; i < Length; i++) {
            SHIP(TILE(*G,P)) = true;
            P = movePoint(P,0,1);
        }
    } else {
        for (int i = 0; i < Length; i++) {
            SHIP(TILE(*G,P)) = true;
            P = movePoint(P,1,0);
        }
    }

}