#ifndef __SNAKE__
#define __SNAKE__

#include "../../ADT/list/linkedList.h"
#include "../../ADT/word/mesinkata/mesinkata.h"

typedef struct {
    Point meteor;
    Point obstacle;
    Point food;
} SnakeGrid;

void drawMap(SnakeGrid *SG);

boolean validMove(LinkedList S, Word D);

boolean checkGrow(LinkedList S);

void spawn(LinkedList *S);

void move(LinkedList *S, Word D);

void hit(SnakeGrid *SG, LinkedList *S, boolean *Lose);

void grow(LinkedList *S);

void updateFood(SnakeGrid *SG, LinkedList S);

void updateMeteor(SnakeGrid *SG);

#endif