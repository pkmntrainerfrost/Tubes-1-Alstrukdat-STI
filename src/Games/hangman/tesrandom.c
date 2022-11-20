#include <stdio.h>
#include "../random.h"
#include "hangman.h"
#include "../../ADT/boolean.h"
#include <stdlib.h>
#include <time.h>

int main()
{
    List L;
    createList(&L);
    insertLast(&L, stringToWord("hai"));
    insertLast(&L, stringToWord("halo"));
    insertLast(&L, stringToWord("woi"));
    insertLast(&L, stringToWord("woii1"));
    insertLast(&L, stringToWord("woii2"));
    insertLast(&L, stringToWord("woi3i"));
    insertLast(&L, stringToWord("woi4"));
    insertLast(&L, stringToWord("woi5"));
    insertLast(&L, stringToWord("woi6"));
    boolean valid = true;
    int Number;
    while (valid){
        srand(time(NULL));
        Number = random_range(0,length(L)-1);
        if (Number >= 0 && Number < length(L)){
            valid = false;
        }
    }
    printf("%d\n", Number);
    Word coba;
    coba = getElmt(L, Number);
    printWord(coba);
    return 0;
}

// compile : gcc src/Utility/splash.c src/Games/random.c src/Games/hangman/tesrandom.c src/Games/hangman/hangman.c src/ADT/list/array.c src/ADT/word/mesinkata/mesinkata.c src/ADT/word/mesinkarakter/mesinkarakter.c src/ADT/word/word.c src/Misc/ascii/ascii.c src/Misc/io/io.c -o driver