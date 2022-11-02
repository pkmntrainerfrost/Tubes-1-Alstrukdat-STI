#include "mesinkata.h"

boolean endKata;
Kata currentKata;

void ignoreBlank() {

    while (cc == BLANK) {
        adv();
    }

}

void startKata() {

    start();
    ignoreBlank


}