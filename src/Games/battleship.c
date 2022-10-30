#include "battleship.h"

// AI
// Yor Forger -> nembak asal (kalo gk sempet, implement yg ini aja)
// Loid Forger -> lebih pinter, strategi 
// Anya Forger -> hax (baca pikiran), harus bener terus ato nggak auto kalah

void initializeGrid(Grid *G, boolean Enemy) {

    int i = 0;

    for (int x = 1; x < 11; x++) {
        for (int y = 1; y < 11; y++) {

            Point P;
            createPoint(&P,x,y);

            HAS_SHIP(TILE(*G,P)) = false;
            WAS_SHOT(TILE(*G,P)) = false;
            ENEMY(*G) = Enemy;

        }
    }

}

void createShip(Ship *S, char *N, Point P, boolean V, int L) {

    NAME(*S) = N;
    POSITION(*S) = P;
    VERTICAL(*S) = V;
    SHIPLENGTH(*S) = L;
    SUNK(*S) = false;

}

void placeShipPlayer(Grid *G) {

    

}

boolean shipPosValid(Grid G, Point P, Ship S) {

    boolean Valid = false;

    if (VERTICAL(S)) {
        if (ORDINATE(P) + LENGTH(S) - 1 <= 10 && ABSICSSA(P) <= 10 && isFirstQuadrant(P)) {
            int i = 0;
            boolean Overlap = false;
            while (!Overlap && i <= LENGTH(S)) {
                if (HAS_SHIP(TILE(G,P))) {
                    Overlap = true;
                }
                movePoint(&P,0,1);
                i = i + 1;
            }
            Valid = !Overlap;
        }
    } else {
        if (ABSICSSA(P) + LENGTH(S) - 1 <= 10 && ORDINATE(P) <= 10 && isFirstQuadrant(P)) {
            int i = 0;
            boolean Overlap = false;
            while (!Overlap && i <= LENGTH(S)) {
                if (HAS_SHIP(TILE(G,P))) {
                    Overlap = true;
                }
                movePoint(&P,1,0);
                i = i + 1;
            }
            Valid = !Overlap;
        }
    }

    return Valid;

}

void endTurn(Grid *G, boolean *EndGame) {

    boolean AllShipsSunk = true;

    for (int i = 0; i < SHIPCOUNT; i++) {

        if (!SUNK(SHIP(*G,i))) {

            AllShipsSunk = false;

            boolean AllTilesShot = true;
            Point CheckPos = POSITION(SHIP(*G,i));
            int ShipLength = SHIPLENGTH(SHIP(*G,i));

            while (AllTilesShot && ShipLength > 0) {
                if (!WAS_SHOT(TILE(*G,CheckPos))) {
                    AllTilesShot = false;
                }
                ShipLength = ShipLength - 1;
            }

            if (AllTilesShot) {
                SUNK(SHIP(*G,i)) = true;
            }

        }

    }

    if (AllShipsSunk) {
        *EndGame = true;
    }

}

/*

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

*/