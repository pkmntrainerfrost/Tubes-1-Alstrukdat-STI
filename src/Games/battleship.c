#include "battleship.h"

void initializeGrid(Grid *G) {

    int i = 0;

    for (int x = 1; x < 11; x++) {
        for (int y = 1; y < 11; y++) {

            Point P;
            createPoint(&P,x,y);

            SHIP(TILE(*G,P)) = false;
            SHOT(TILE(*G,P)) = false;

            destroyPoint(&P);

        }
    }

}

void printGrid(Grid G,boolean Enemy) {



    for (int x = 1; x < 11; x++) {

        for (int y = 1; y < 11; y++) {

            Point P;
            createPoint(&P,x,y);

            if (SHOT(TILE(G,P))) {
                printf("X");
            } else if (SHIP(TILE(G,P))) {
                if (!Enemy) {
                    printf("#");
                }
            } else {
                printf(" ");
            }

            destroyPoint(&P);

        }

        printf("\n");

    }

}

boolean shipPosValid(Point P, int Length, boolean Vertical) {

    if (Vertical) {
        return (ORDINATE(P) + Length - 1 <= 10 && ABSICSSA(P) <= 10 && isFirstQuadrant(P));
    } else {
        return (ABSICSSA(P) + Length - 1 <= 10 && ORDINATE(P) <= 10 && isFirstQuadrant(P));
    }

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