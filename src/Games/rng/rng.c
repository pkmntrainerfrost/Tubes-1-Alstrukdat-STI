#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "rng.h"

void rng(){

    long Number = random_range(0,100);

    printf("%ld\n",Number);

    long Answer;
    boolean Correct = false;

    printf("Tebak angkanya\n");
    Word input;
    createWord(&input);
    boolean valid = wordInput(&input,1,10);
    Answer = wordToInt(input);

    while (Answer != Number) {
        if (Answer > Number) {
            printf("Lebih Kecil\n");
        } else {
            printf("Lebih Besar\n");
        }
        valid = wordInput(&input,1,10);
        Answer = wordToInt(input);
    }

    printf("Benar\n");

}

// int main() {

//     rng();

//     return 0;

// }

// compile: gcc Games/rng/rng.c Games/random.c Misc/io/io.c Misc/ascii/ascii.c ADT/list/array.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c -o driver