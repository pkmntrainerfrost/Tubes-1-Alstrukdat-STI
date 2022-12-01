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

    Grid.obstacle = O;

}

void drawMap(SnakeGrid *SG) {

}

boolean validMove(LinkedList S, Word D) {

    Point P = copyPoint(LLFirst(S)->info);
    Point NP;

    if (isWordEqual(stringToWord("W"),D)) {
        NP = translate(P,0,1);
        ORDINATE(NP) = ORDINATE(NP) % 5;
    } else if (isWordEqual(stringToWord("A"),D)) {
        NP = translate(P,-1,0);
        ABSCISSA(NP) = ABSCISSA(NP) % 5;
    } else if (isWordEqual(stringToWord("S"),D)) {
        NP = translate(P,0,-1);
        ORDINATE(NP) = ORDINATE(NP) % 5;
    } else if (isWordEqual(stringToWord("D"),D)) {
        NP = translate(P,1,0);
        ABSCISSA(NP) = ABSCISSA(NP) % 5;
    }

    return searchLL(S,NP) == NIL;

}

boolean checkGrow(LinkedList S) {

    Point Tail = copyPoint(LLInfo(LLLast(S)));

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

void move(LinkedList *S, Word D) {

    Point P = copyPoint(LLFirst(*S)->info);
    Point NP;

    if (isWordEqual(stringToWord("W"),D)) {
        NP = translate(P,0,1);
        ORDINATE(NP) = ORDINATE(NP) % 5;
    } else if (isWordEqual(stringToWord("A"),D)) {
        NP = translate(P,-1,0);
        ABSCISSA(NP) = ABSCISSA(NP) % 5;
    } else if (isWordEqual(stringToWord("S"),D)) {
        NP = translate(P,0,-1);
        ORDINATE(NP) = ORDINATE(NP) % 5;
    } else if (isWordEqual(stringToWord("D"),D)) {
        NP = translate(P,1,0);
        ABSCISSA(NP) = ABSCISSA(NP) % 5;
    }

    for (int i = lengthLL - 1; i > 0; i++) {
        setElmtLL(S,i,getElmtLL(*S,i-1));
    }

    setElmtLL(S,0,NP);

}

void hit(SnakeGrid *SG, LinkedList *S, boolean *Lose) {

    Address Hit = searchLL(*S,SG->meteor);

    if (Hit != NIL) {
        if (Hit == LLFirst(*S) || lengthLL(*S) == 1) {
            *Lose = true;
        } else {
            Next(Prev(Hit)) == Next(Hit);
            if (Hit != LLLast(*S)) {
                Prev(Next(Hit)) == Prev(Hit);
            }
            deallocateNode(Hit);
        }
    }

}

void grow(LinkedList *S) {

    if (searchLL(*S,));

}

void updateFood(SnakeGrid *SG, LinkedList S) {

    Point P;

    do {
        createPoint(&P,random_range(0,5),random_range(0,5));
    } while (searchLL(S,P) != NIL);

}