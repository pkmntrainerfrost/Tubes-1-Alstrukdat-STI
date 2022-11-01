#include "random.h"
#include <stdio.h>
#include <stdlib.h>

int random_range(int Min, int Max) {

    return (Min + rand() % Max);

}

int main() {

    char a;

    scanf("%c",&a);

    printf("char yang diinput adalah '%c'\n", a);

}