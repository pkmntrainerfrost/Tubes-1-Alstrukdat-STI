#include "random.h"
#include <stdio.h>
#include <stdlib.h>

long random_range(long Min, long Max) {

    long Result;

    unsigned long Boxes = (unsigned long) Max + 1;
    unsigned long MaxRandPlus1 = (unsigned long) RAND_MAX + 1;
    unsigned long BoxSize = MaxRandPlus1 / Boxes;
    unsigned long Defect = MaxRandPlus1 % Boxes;

    Result = rand();
    printf("%ld",Result);
    while ((unsigned long) Result >= MaxRandPlus1 - Defect) {
        Result = rand();
    }

    return Result/BoxSize;

}