#include "battleship.h"

// AI
// Yor Forger -> nembak asal (kalo gk sempet, implement yg ini aja)
// Loid Forger -> lebih pinter, strategi 
// Anya Forger -> hax (baca pikiran), harus bener terus ato nggak auto kalah

void initializeGrid(Grid *G) {

    int i = 0;

    for (int x = 1; x < 11; x++) {
        for (int y = 1; y < 11; y++) {

            Point P;
            createPoint(&P,x,y);

            HAS_SHIP(TILE(*G,P)) = false;
            WAS_SHOT(TILE(*G,P)) = false;

            destroyPoint(&P);

        }
    }

}

void endTurn(Grid *G, boolean *endGame) {

    boolean allShipsSunk = true;

    for (int i = 0; i < SHIPCOUNT; i++) {

        if (!SUNK(SHIP(*G,i))) {

            allShipsSunk = false;

            boolean allTilesShot = true;
            Point checkPos = POSITION(SHIP(*G,i));
            int shipLength = SHIPLENGTH(SHIP(*G,i));

            while (allTilesShot && shipLength > 0) {
                if (!WAS_SHOT(TILE(*G,checkPos))) {
                    allTilesShot = false;
                }
                shipLength = shipLength - 1;
            }

            if (allTilesShot) {
                SUNK(SHIP(*G,i)) = true;
            }

        }

    }

    if (allShipsSunk) {
        *endGame = true;
    }

}

       PAPAN ANDA               PAPAN ANYA

INTEGRITAS KAPAL   |A|B|C|D|E|F|G|H|I|J| |A|B|C|D|E|F|G|H|I|J|   INTEGRITAS KAPAL
                   | | | | | | | | | | |0| | | | | | | | | | |   
                   | | | | | | | | | | |1| | | | | | | | | | |   CARRIER #####
                   | | | | | | | | | | |2| | | | | | | | | | |   
                   | | | | | | | | | | |3| | | | | | | | | | |   BATTLESHIP ####
                   | | | | | | | | | | |4| | | | | | | | | | |   
                   | | | | | | | | | | |5| | | | | | | | | | |   CRUISER ###
                   | | | | | | | | | | |6| | | | | | | | | | |   
                   | | | | | | | | | | |7| | | | | | | | | | |   SUBMARINE ###
                   | | | | | | | | | | |8| | | | | | | | | | |   
                   | | | | | | | | | | |9| | | | | | | | | | |   DESTROYER ##

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