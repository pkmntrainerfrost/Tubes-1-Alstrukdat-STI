#include "battleship.h"
#include "../Misc/io/io.h"

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

void copyShip(Ship *S1, Ship *S2) {

    NAME(*S1) = NAME(*S2);
    POSITION(*S1) = POSITION(*S2);
    VERTICAL(*S1) = VERTICAL(*S2);
    SHIPLENGTH(*S1) = SHIPLENGTH(*S2);
    SUNK(*S1) = SUNK(*S2);

}

void placeShipsPlayer(Grid *G) {

    Ship Carrier;
    Ship Battleship;
    Ship Cruiser;
    Ship Submarine;
    Ship Destroyer;
    
    shipInput(G,&Carrier,"Carrier",5);
    copyShip(&Carrier,&SHIP(*G,0));

    shipInput(G,&Battleship,"Battleship",4);
    copyShip(&Battleship,&SHIP(*G,0));
    
    shipInput(G,&Battleship,"Cruiser",3);
    copyShip(&Cruiser,&SHIP(*G,0));

    shipInput(G,&Submarine,"Submarine",3);
    copyShip(&Submarine,&SHIP(*G,0));

    shipInput(G,&Destroyer,"Destroyer",2);
    copyShip(&Destroyer,&SHIP(*G,0));

}

void shipInput(Grid *G, Ship *S, char *N, int L) {

    int InvalidInputs = 0;
    boolean Valid = false;

    while (!Valid) {
        
        if (InvalidInputs == 0) {
            printf("Silahkan masukkan posisi dan orientasi kapal.\n");
        } else {
            printf("Posisi kapal tidak valid!\n");
        }

        Point P;
        boolean V;

        posInput(&P);
        verticalInput(&V);

        createShip(S,N,P,V,L);

        if (shipPosValid(*G,*S)) {
            Valid = true;
        } else {
            InvalidInputs = InvalidInputs + 1;
        }

    }

}

void posInput(Point *P) {

    int InvalidInputs = 0;
    boolean Valid = false;
    char Input[3];

    while (!Valid) {
        
        if (InvalidInputs == 0) {
            printf("Silahkan masukkan koordinat. Contoh: A0\n");
        } else {
            printf("Masukan bukan merupakan koordinat yang valid! Ulangi Input!\n");
        }

        stringInput(Input,2);

        if ((isAlpha(Input[0]) && isCharInRange(lower(Input[0]), 'a', 'j')) && (isNumeric(Input[1]))) {
            Valid = true;
        } else {
            InvalidInputs = InvalidInputs + 1;
        }

    }

    ABSCISSA(*P) = alphabeticalOrd(Input[0]);
    ORDINATE(*P) = charToInt(Input[1]);

}

void verticalInput(boolean *V) {

    int InvalidInputs = 0;
    boolean Valid = false;
    char Input[2];

    while (!Valid) {
        
        if (InvalidInputs == 0) {
            printf("Apakah kapal berorientasi vertikal? [Y/N]\n");
        } else {
            printf("Ulangi input!\n");
        }

        stringInput(Input,2);

        if (lower(Input[0]) == 'y' || lower(Input[0]) == 'n') {
            Valid = true;
        } else {
            InvalidInputs = InvalidInputs + 1;
        }

    }

    if (lower(Input[0]) == 'y') {
        *V = true;
    } else {
        *V = false;
    }

}

boolean shipPosValid(Grid G, Ship S) {

    boolean Valid = false;
    Point P = copyPoint(POSITION(S));

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

void shoot(Grid *G) {

    boolean Valid = false;
    Point P;

    while (!Valid) {

        posInput(&P);

        if (!WAS_SHOT(TILE(*G,P))) {
            Valid = true;
        }

    }
    
    WAS_SHOT(TILE(*G,P)) = true;

}

void endTurn(Grid *G, boolean *Winner) {

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
        *Winner = true;
    }

}

/*

------------------KAPALPERANG-------------------

                PAPAN ANYA           PAPAN ANDA
           A B C D E F G H I J | A B C D E F G H I J
##### C 0)                     |                     (0 C #####
        1)                     |                     (1 
####. B 2)                     |                     (2 B .####            
        3)                     |                     (3
###.. D 4)                     |                     (4 D ..###
        5)                     |                     (5
###.. S 6)                     |                     (6 S ..###
        7)                     |                     (7
##... P 8)                     |                     (8 P ...##
        9)                     |                     (9 
           A B C D E F G H I J | A B C D E F G H I J
                2/5 KAPAL             2/5 KAPAL



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