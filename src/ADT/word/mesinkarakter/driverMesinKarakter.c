#include "mesinkarakter.h"
#include <stdio.h>

int main() {

    start(false,"");

    while (!eoi) {
        printf("%c",cc);
        adv();
    }

    printf("\n");    

    start(true,"src/ADT/word/mesinkarakter/test.txt");

    while (!eoi) {
        printf("%c",cc);
        adv();
    }

    printf("\n");

    start(false,"");

    while (!eoi) {
        printf("%c",cc);
        adv();
    }
    printf("\n");
}

// compile : gcc src/ADT/word/mesinkarakter/driverMesinKarakter.c src/ADT/word/mesinkarakter/mesinkarakter.c -o driver