#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "rng.h"

void rng() {

    long Number = random_range(0,100);

    printf("%ld",Number);

    long Answer;
    boolean Correct = false;

    printf("Tebak angkanya\n");
    scanf("%d", &Answer);

    while (Answer != Number) {
        if (Answer > Number) {
            printf("Lebih Kecil\n");
        } else {
            printf("Lebih Besar\n");
        }
        scanf("%d", &Answer);
    }

    printf("Benar\n");

}

int main() {

    rng();

    return 0;

}