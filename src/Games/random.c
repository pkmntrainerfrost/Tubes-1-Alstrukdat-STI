#include "random.h"
#include <stdio.h>
#include <stdlib.h>

int random_range(int Min, int Max) {

    int div = RAND_MAX / (Max + 1);
    int result = rand();

    printf("%d",RAND_MAX);

    while (result > Max) {
        result = rand() / div;
    }

    return (Min + result);

}
