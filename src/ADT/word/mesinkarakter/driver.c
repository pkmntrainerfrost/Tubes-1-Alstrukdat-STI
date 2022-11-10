#include "mesinkarakter.h"
#include <stdio.h>

int main() {

    start(false,"");

    while (!eoi) {
        printf("%c",cc);
        adv();
    }

    printf("\n");    

    start(true,"test.txt");

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

}