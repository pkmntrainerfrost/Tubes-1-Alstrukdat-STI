#ifndef __SNAKE__
#define __SNAKE__

#include "../../ADT/list/linkedList.h"
#include "../../ADT/word/mesinkata/mesinkata.h"
#include "../../Misc/io/io.h"

typedef struct {
    Point meteor;
    Point obstacle;
    Point food;
} SnakeGrid;

void drawMap(SnakeGrid SG, LinkedList S, boolean Lose, boolean Hit, int Turns);

Point validMove(SnakeGrid SG, LinkedList S, Word D);

Point checkGrow(SnakeGrid SG, LinkedList S);

void spawn(LinkedList *S);

int move(SnakeGrid *SG, LinkedList *S, Word D, boolean *Lose);

void hit(SnakeGrid *SG, LinkedList *S, boolean *Lose, boolean *Hit);

void grow(SnakeGrid *SG, LinkedList *S, boolean *Lose);

void updateFood(SnakeGrid *SG, LinkedList S);

void updateMeteor(SnakeGrid *SG);

boolean noMoreMoves(SnakeGrid SG, LinkedList S);

#endif