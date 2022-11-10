#include <stdio.h>
#include "word.h"

int main()
{
    Word test, test1, concat;
    createWord(&test);
    createWord(&test1);
    printf("%d\n", wordLength(test));
    test = stringToWord("hai");
    test1 = stringToWord("halo");
    printWord(test);
    printf("\n");
    if (isWordEqual(test, test1)) {
        printf("Sama\n");
    } else {
        printf("Tidak sama\n");
    }
    createWord(&concat);
    concateWord(test, test1, &concat);
    char *s;
    wordToString(concat, s);
    printf("%s\n", s);
    test = intToWord(123);
    printf("%d\n", wordToInt(test));
    return 0;
}

// compile: gcc ADT/word/driverWord.c ADT/word/word.c Misc/ascii/ascii.c -o driver
// wordToString sama intToWord belum jalan