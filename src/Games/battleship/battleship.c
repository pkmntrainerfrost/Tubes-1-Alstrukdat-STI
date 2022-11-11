#include "battleship.h"
#include "../../Misc/io/io.h"
#include <stdio.h>

// AI
// Yor Forger -> nembak asal (kalo gk sempet, implement yg ini aja)
// Loid Forger -> lebih pinter, strategi 
// Anya Forger -> hax (baca pikiran), harus bener terus ato nggak auto kalah

int main() {

    battleship();

    return 0;

}

void battleship() {

    Word inputEnemy;
    int enemy;
    boolean validEnemy = false;
    boolean inGame = false;

    while (!validEnemy) {

        header();

        battleshipSplash();

        printf("Silahkan pilih lawan Anda [YOR/LOID/ANYA/QUIT]: ");

        validEnemy = wordInput(&inputEnemy,3,4);

        if (validEnemy) {
            if (isWordEqual(inputEnemy,stringToWord("YOR"))) {
                inGame = true;
                enemy = 1;
                printf("Tekan [ENTER] untuk memulai permainan.\n");
            } else if (isWordEqual(inputEnemy,stringToWord("LOID"))) {
                inGame = true;
                enemy = 2;
                printf("Tekan [ENTER] untuk memulai permainan.\n");
            } else if (isWordEqual(inputEnemy,stringToWord("ANYA"))) {
                inGame = true;
                enemy = 3;
                printf("Tekan [ENTER] untuk memulai permainan.\n");
            } else if (isWordEqual(inputEnemy,stringToWord("QUIT"))) {
                inGame = false;
                printf("Pengecut. Tekan [ENTER] untuk kembali ke menu utama.\n");
            } else {
                validEnemy = false;
            }
        } 

        if (!validEnemy) {
            printf("Masukan tidak valid. Tekan [ENTER] dan ulangi masukan.\n");
        }

        blankInput();

    }

    if (inGame) {

        header();

        Grid PlayerGrid;
        Grid EnemyGrid;

        initializeGrid(&PlayerGrid,false);
        initializeGrid(&PlayerGrid,true);

        placeShipsPlayer(&PlayerGrid);

    }

}

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
            printf("Silahkan masukkan posisi dan orientasi kapal %s.\n",N);
        } else {
            printf("Posisi kapal tidak valid! Ulangi masukan.\n");
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

    Word Input;

    while (!Valid) {
        
        if (InvalidInputs == 0) {
            printf("Silahkan masukkan koordinat [A-J][0-9]. Contoh: A0, D8\n");
        } else {
            printf("Masukan bukan merupakan koordinat yang valid! Ulangi Input!\n");
        }
        
        boolean InputValid = wordInput(&Input,2,2);

        if (InputValid) {
            printf("%d,%d,%d\n",isAlpha(Input.buffer[0]),isCharInRange(lower(Input.buffer[0]), ord('a'), ord('j')),isNumeric(Input.buffer[1]));
            if ((isAlpha(Input.buffer[0]) && isCharInRange(lower(Input.buffer[0]), ord('a'), ord('j'))) && (isNumeric(Input.buffer[1]))) {
                Valid = true;
            } else {
                InvalidInputs = InvalidInputs + 1;
            }
        }

    }

    ABSCISSA(*P) = alphabeticalOrd(Input.buffer[0]);
    
    ORDINATE(*P) = charToInt(Input.buffer[1]);

    printf("%d,%d\n",ABSCISSA(*P),ORDINATE(*P));

}

void verticalInput(boolean *V) {

    int InvalidInputs = 0;
    boolean Valid = false;

    Word Input;

    while (!Valid) {
        
        if (InvalidInputs == 0) {
            printf("Apakah kapal berorientasi vertikal? [Y/N]\n");
        } else {
            printf("Ulangi input!\n");
        }

        boolean InputValid = wordInput(&Input,1,2);

        if (InputValid) {
            if (isAlpha(Input.buffer[0]) && (lower(Input.buffer[0]) == 'y' || lower(Input.buffer[0]) == 'n')) {
                Valid = true;
            } else {
                InvalidInputs = InvalidInputs + 1;
            }
        }

    }

    if (lower(Input.buffer[0]) == 'y') {
        *V = true;
    } else {
        *V = false;
    }

}

boolean shipPosValid(Grid G, Ship S) {

    boolean Valid = false;
    Point P = copyPoint(POSITION(S));

    if (VERTICAL(S)) {
        if (ORDINATE(P) + SHIPLENGTH(S) - 1 <= 10 && ABSCISSA(P) <= 10 && isFirstQuadrant(P)) {
            int i = 0;
            boolean Overlap = false;
            while (!Overlap && i <= SHIPLENGTH(S)) {
                if (HAS_SHIP(TILE(G,P))) {
                    Overlap = true;
                }
                movePoint(&P,0,1);
                i = i + 1;
            }
            Valid = !Overlap;
        }
    } else {
        if (ABSCISSA(P) + SHIPLENGTH(S) - 1 <= 10 && ORDINATE(P) <= 10 && isFirstQuadrant(P)) {
            int i = 0;
            boolean Overlap = false;
            while (!Overlap && i <= SHIPLENGTH(S)) {
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

void battleshipSplash() {

    printf("                                             #.                                 \n");
    printf("                                             @ #                                \n");
    printf("                                             .@ ,                               \n");
    printf("                                           @. @                                 \n");
    printf("                       &@             @@*     @#                                \n");
    printf("                      @@@           @@@       @  @@@@@@                         \n");
    printf("                       @        &@@ @@@  @    @@@@@@@@@                         \n");
    printf("                @@@@ @@@     @@@@@@@@@@@@@@@@@@@@@@@@@@ @@@@@. @((@@@,@@@    @& \n");
    printf(" @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    printf(" @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    printf("\n");
    printf("  ######   #####  ######## ######## ##      ####### ####### ##   ## ## ######   \n");
    printf("  ##   ## ##   ##    ##       ##    ##      ##      ##      ##   ## ## ##   ##  \n");
    printf("  ######  #######    ##       ##    ##      #####   ####### ####### ## ######   \n");
    printf("  ##   ## ##   ##    ##       ##    ##      ##           ## ##   ## ## ##       \n");
    printf("  ##   ## ##   ##    ##       ##    ##      ##           ## ##   ## ## ##       \n");
    printf("  ######  ##   ##    ##       ##    ####### ####### ####### ##   ## ## ##       \n");
    printf("\n");
    printf("==========================Selamat datang, Laksamana.===========================\n");
    printf("\n");

}

/* 

                                                                                
================================================================================                                                                                
                                                                                                    
                                             #.                                 
                                             @ #                                
                                             .@ ,                               
                                           @. @                                 
                       &@             @@*     @#                                
                      @@@           @@@       @  @@@@@@                         
                       @        &@@ @@@  @    @@@@@@@@@                         
                @@@@ @@@     @@@@@@@@@@@@@@@@@@@@@@@@@@ @@@@@. @((@@@,@@@    @& 
 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 
 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  ######   #####  ######## ######## ##      ####### ####### ##   ## ## ######  
  ##   ## ##   ##    ##       ##    ##      ##      ##      ##   ## ## ##   ## 
  ######  #######    ##       ##    ##      #####   ####### ####### ## ######  
  ##   ## ##   ##    ##       ##    ##      ##           ## ##   ## ## ##      
  ######  ##   ##    ##       ##    ####### ####### ####### ##   ## ## ##       

===========================Selamat datang, Laksamana.===========================

Silahkan pilih lawan Anda [YOR/LOID/ANYA]: 


*/

/*

------------------KAPALPERANG-------------------

           
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