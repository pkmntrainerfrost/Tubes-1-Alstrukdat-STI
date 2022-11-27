#ifndef towerofhanoi_H
#define towerofhanoi_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"../../ADT/stack/stack.h"

void printStack(Stack A, Stack B, Stack C);

void pindah(Stack *S1, Stack *S2, char cc);

boolean cekStack(Stack C);

boolean endGame(Stack C);

void towerOfHanoi();

#endif