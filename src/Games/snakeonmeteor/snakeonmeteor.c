#include "../../Utility/splash.h"
#include "snakeonmeteor.h"
#include "../random.h"
#include <stdio.h>

void snakeonmeteor() {

    LinkedList Snake;
    createLL(&Snake);

    spawn(&Snake);

    SnakeGrid Grid;
    Point O;

    do {
        createPoint(&O,random_range(0,4),random_range(0,4));
    } while (searchLL(Snake,O) != NIL);

    Grid.obstacle = copyPoint(O);

    do {
        createPoint(&O,random_range(0,4),random_range(0,4));
    } while (searchLL(Snake,O) != NIL || isPointEqual(O,Grid.obstacle));

    Grid.food = copyPoint(O);

    boolean Lose = false;
    boolean Hit = false;

    int Move = 0;

    while (!Lose) {
        
        header();
        Lose = noMoreMoves(Grid,Snake);

        if (!Lose) {

            drawMap(Grid,Snake,Lose,Hit,Move);

            Word Input;
            boolean Valid = false;

            while (!Valid) {
                
                int InputValid = wordInput(&Input,1,1);

                if (InputValid) {
                    int ValidMove = move(&Grid,&Snake,Input,&Lose);
                    if (ValidMove == 0) {
                        Valid = true;
                        Move = Move + 1;
                    } else {
                        if (ValidMove == 1) {
                            printf("Dilarang\n");
                        } else if (ValidMove == 2) {
                            printf("Dilarang\n");
                        } else {
                            printf("INPUT TIDAK VALID\n");
                        }
                    }
                } else {
                    printf("Masuk");
                    if (wordLength(Input) == 0) {
                        printf("kosong\n");
                    } else {
                        printf("input tidak valid\n");
                    }
                }

            }

            if (!Lose) {
                grow(&Grid,&Snake,&Lose);
            }

            if (!Lose) {
                updateMeteor(&Grid);   
                hit(&Grid,&Snake,&Lose,&Hit);
            }

        }

    }

    header();
    
    drawMap(Grid,Snake,Lose,Hit,Move);

    printf("\n GAME OVER\n");
    printf("SKOR: %d",lengthLL(Snake) * 2);

}

void drawMap(SnakeGrid SG, LinkedList S, boolean Lose, boolean Hit, int Turns) {

    printf("                                SNAKE ON METEOR\n");
    printf("                             +---+---+---+---+---+\n");

    for (int i = 0; i < 5; i++) {
        
        printf("                             |");
        
        for (int j = 0; j < 5; j++) {
            
            printf(" ");

            Point P;
            createPoint(&P,j,i);

            if (isPointEqual(P,SG.food)) {
                printf("O");
            } else if (isPointEqual(P,SG.meteor)) {
                printf("M");
            } else if (isPointEqual(P,SG.obstacle)) {
                printf("X");
            } else {
                int Body = getIdxLL(S,P);   
                if (Body == -1) {
                    printf(" ");
                } else if (Body == 0) {
                    if (!Lose) {
                        printf("H");
                    } else {
                        printf("1");
                    }
                } else {
                    if (Lose) {
                        Body = Body + 1;
                    }
                    printf("%d",Body);
                }
            }

            printf(" |");
    
        }

        printf(" ");

        if (i == 0) {
            printf("LEGENDA\n");
            printf("                             +---+---+---+---+---+\n");
        } else if (i == 1) {
            printf("O - MAKANAN\n");
            printf("                             +---+---+---+---+---+ M - METEOR \n");
        } else if (i == 2) {
            printf("X - OBSTACLE\n");
            printf("                             +---+---+---+---+---+\n");
        } else if (i == 3) {
            printf("H - KEPALA\n");
            printf("                             +---+---+---+---+---+\n");
        } else {
            printf("W/A/S/D UNTUK BERGERAK\n");
            printf("                             +---+---+---+---+---+\n");
        }

    }

    if (Turns == 0) {
        printf("                    Masukkan W/A/S/D untuk mulai bermain...\n");
    } else {
        if (Lose) {
            if (isPointEqual(Info(First(S)),SG.obstacle)) {
                printf("Kena obstacle lmao\n");
            } else if (Hit) {
                printf("Kena meteor\n");
            } else if (noMoreMoves) {
                printf("dah nggak bisa kemana2\n");
            } else {
                printf("ndak bisa tumbuh\n");
            }
        } else {
            if (!Hit) {
                printf("jalan\n");
            } else {
                printf("kena\n");
            }
        }
    }

    printf("\n=================\n");

}

boolean noMoreMoves(SnakeGrid SG, LinkedList S) {

    Point P = copyPoint(Info(First(S)));
    Point NP = copyPoint(P);
    boolean Valid = true;

    NP = translate(P,1,0);
    if (ABSCISSA(NP) < 0) {
            ABSCISSA(NP) = 4;
        } else {
            ABSCISSA(NP) = ABSCISSA(NP) % 5;
        }
    Valid = Valid && !(!isPointEqual(NP,SG.meteor) && searchLL(S,NP) == NIL);

    NP = translate(P,-1,0);
    if (ABSCISSA(NP) < 0) {
            ABSCISSA(NP) = 4;
        } else {
            ABSCISSA(NP) = ABSCISSA(NP) % 5;
        }
    Valid = Valid && !(!isPointEqual(NP,SG.meteor) && searchLL(S,NP) == NIL);

    NP = translate(P,0,1);
    if (ORDINATE(NP) < 0) {
            ORDINATE(NP) = 4;
        } else {
            ORDINATE(NP) = ORDINATE(NP) % 5;
        }
    Valid = Valid && !(!isPointEqual(NP,SG.meteor) && searchLL(S,NP) == NIL);

    NP = translate(P,0,-1);
    if (ORDINATE(NP) < 0) {
            ORDINATE(NP) = 4;
        } else {
            ORDINATE(NP) = ORDINATE(NP) % 5;
        }
    Valid = Valid && !(!isPointEqual(NP,SG.meteor) && searchLL(S,NP) == NIL);

    return Valid;

}

Point validMove(SnakeGrid SG, LinkedList S, Word D) {

    Point P = copyPoint(Info(First(S)));
    Point NP;

    if (isWordEqual(stringToWord("W"),D) || isWordEqual(stringToWord("w"),D)) {
        NP = translate(P,0,-1);
        if (ORDINATE(NP) < 0) {
            ORDINATE(NP) = 4;
        } else {
            ORDINATE(NP) = ORDINATE(NP) % 5;
        }
    } else if (isWordEqual(stringToWord("A"),D) || isWordEqual(stringToWord("a"),D)) {
        NP = translate(P,-1,0);
        if (ABSCISSA(NP) < 0) {
            ABSCISSA(NP) = 4;
        } else {
            ABSCISSA(NP) = ABSCISSA(NP) % 5;
        }
    } else if (isWordEqual(stringToWord("S"),D) || isWordEqual(stringToWord("s"),D)) {
        NP = translate(P,0,1);
        if (ORDINATE(NP) < 0) {
            ORDINATE(NP) = 4;
        } else {
            ORDINATE(NP) = ORDINATE(NP) % 5;
        }
    } else if (isWordEqual(stringToWord("D"),D) || isWordEqual(stringToWord("d"),D)) {
        NP = translate(P,1,0);
        if (ABSCISSA(NP) < 0) {
            ABSCISSA(NP) = 4;
        } else {
                ABSCISSA(NP) = ABSCISSA(NP) % 5;
        }
    } else {
        createPoint(&NP,-3,-3);
    }

    if (searchLL(S,NP) != NIL) {
        createPoint(&NP,-1,-1);
    } else if (isPointEqual(NP,SG.meteor)) {
        createPoint(&NP,-2,-2);
    }

    return NP;

}

Point checkGrow(SnakeGrid SG, LinkedList S) {

    Point Tail = copyPoint(Info(Last(S)));

    Point Grow = translate(Tail,-1,0);
    ABSCISSA(Grow) = ABSCISSA(Grow) % 5;

    if (!isPointEqual(Grow,SG.meteor) && !isPointEqual(Grow,SG.obstacle) && (searchLL(S,Grow) == NIL)) {
        return Grow;
    }

    Grow = translate(Tail,0,-1);
    ORDINATE(Grow) = ORDINATE(Grow) % 5;

    if (!isPointEqual(Grow,SG.meteor) && !isPointEqual(Grow,SG.obstacle) && (searchLL(S,Grow) == NIL)) {
        return Grow;
    }

    Grow = translate(Tail,0,1);
    ORDINATE(Grow) = ORDINATE(Grow) % 5;

    if (!isPointEqual(Grow,SG.meteor) && !isPointEqual(Grow,SG.obstacle) && (searchLL(S,Grow) == NIL)) {
        return Grow;
    }

    Grow = translate(Tail,1,0);
    ABSCISSA(Grow) = ABSCISSA(Grow) % 5;

    if (!isPointEqual(Grow,SG.meteor) && !isPointEqual(Grow,SG.obstacle) && (searchLL(S,Grow) == NIL)) {
        return Grow;
    }

    createPoint(&Grow,-1,-1);

    return Grow;

}

void spawn(LinkedList *S) {

    Point P;
    createPoint(&P,random_range(0,4),random_range(0,4));

    insVLastLL(S,P);

    if (ABSCISSA(P) < 3) {
        insVLastLL(S,translate(P,1,0));
        insVLastLL(S,translate(P,2,0));
    } else {
        insVLastLL(S,translate(P,-1,0));
        insVLastLL(S,translate(P,-2,0));
    }

}

int move(SnakeGrid *SG, LinkedList *S, Word D, boolean *Lose) {

    Point P = copyPoint(Info(First(*S)));
    Point NP = validMove(*SG,*S,D);

    Point MoveToSelf;
    createPoint(&MoveToSelf,-1,-1);
    Point MoveToMeteor;
    createPoint(&MoveToMeteor,-2,-2);

    if (isFirstQuadrant(NP)) {
        for (int i = lengthLL(*S) - 1; i > 0; i--) {
            setElmtLL(S,i,getElmtLL(*S,i-1));
        }
        setElmtLL(S,0,NP);
        if (isPointEqual(NP,SG->obstacle)) {
            *Lose = true;
        }
        return 0;
    } else {
        if (isPointEqual(NP,MoveToSelf)) {
            return 1;
        } else if (isPointEqual(NP,MoveToMeteor)) {
            return 2;
        } else {
            return 3;
        }
    }

}

void hit(SnakeGrid *SG, LinkedList *S, boolean *Lose, boolean *Hit) {

    Address H = searchLL(*S,SG->meteor);

    if (H != NIL) {
        if (H == First(*S) || lengthLL(*S) == 1) {
            *Lose = true;
        }
        *Hit = true;
        delAddressLL(S,SG->meteor);
    } else {
        *Hit = false;
    }

}

void grow(SnakeGrid *SG, LinkedList *S, boolean *Lose) {

    Point Invalid;
    createPoint(&Invalid,-1,-1);

    if (isPointEqual(Info(First(*S)),SG->food)) {
        Point Grow = checkGrow(*SG,*S);
        if (isPointEqual(Grow,Invalid)) {
            *Lose = true;
        } else {
            insVLastLL(S,Grow);
            updateFood(SG,*S);
        }
    }

}

void updateFood(SnakeGrid *SG, LinkedList S) {

    Point P;

    do {
        createPoint(&P,random_range(0,4),random_range(0,4));
    } while (searchLL(S,P) != NIL || isPointEqual(P,SG->meteor) || isPointEqual(P,SG->obstacle));

    SG->food = copyPoint(P);

}

void updateMeteor(SnakeGrid *SG) {

    Point P;

    do {
        createPoint(&P,random_range(0,4),random_range(0,4));
    } while (isPointEqual(P,SG->meteor) || isPointEqual(P,SG->obstacle) || isPointEqual(P,SG->food));

    SG->meteor = copyPoint(P);

}

int main() {

    snakeonmeteor();

    return 0;

}

// ========
//
//                    //    SNAKE ON METEOR                           x
//                    // +---+---+---+---+---+ 
//                    // | A | B | C | D | E | LEGENDA
//                    // +---+---+---+---+---+
//                    // | A | B | C | D | E | O - MAKANAN
//                    // +---+---+---+---+---+ M - METEOR
//                    // | A | B | C | D | E | X - OBSTACLE
//                    // +---+---+---+---+---+ 
//                    // | A | B | C | D | E | H - KEPALA
//                    // +---+---+---+---+---+
//                    // | A | B | C | D | E | W/A/S/D UNTUK BERGERAK
//                    // +---+---+---+---+---+

// gcc ADT/list/linkedList.c ADT/word/word.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/mesinkata/mesinkata.c ADT/point/point.c Games/snakeonmeteor/snakeonmeteor.c Utility/splash.c Misc/io/io.c Misc/ascii/ascii.c Games/random.c ADT/list/array.c -o snakeonmeteor
