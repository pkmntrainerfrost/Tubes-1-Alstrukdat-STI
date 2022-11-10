#include "Utility/splash.h"
#include "Misc/io/io.h"
#include "ADT/boolean.h"
#include "ADT/word/word.h"
#include "ADT/list/array.h"

#include <stdio.h>

int main() {

    boolean Started = false;

    boolean InvalidFile = false;
    int Tries = 0;

    while (!Started) {

        splash(Tries,InvalidFile);

        List Input;
        createList(&Input);
        boolean Valid = multiWordInput(&Input,1,2);

        if (Valid) {
            if (isWordEqual(getElmt(Input,0),stringToWord("START")) && length(Input) == 1) {
                printf("valid");
                Started = true;
            } else if (isWordEqual(getElmt(Input,0),stringToWord("LOAD")) && length(Input) == 2) {
                printf("valid");
                Started = true;
            } else {
                Tries = Tries + 1;
            }
        } else {
            Tries = Tries + 1;
        }

        deallocateList(&Input);

    }

}

