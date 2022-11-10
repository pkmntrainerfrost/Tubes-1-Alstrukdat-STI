/* File         : io.c */
/* Deskripsi    : Implementasi mesin karakter-kata untuk input/output + stringops */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "io.h"
#include "../../ADT/list/array.h"
#include "../../ADT/word/word.h"
#include "../../ADT/word/mesinkata/mesinkata.h"

#define INVALID_INPUT 1
#define VALID_INPUT 0

int wordInput(Word *w, int min, int max) {

    createWord(w);

    start(false,"");

    int i = 0;
    while (!eoi) {
        if (i < N_MAX && i < max) {
            w->buffer[i] = cc;
            i = i + 1;
        }
        adv();
    }

    wordLength(*w) = i; 

    if (wordLength(*w) < min) {
        return INVALID_INPUT;
    } else {
        return VALID_INPUT;
    }

}

int multiWordInput(List *input, int min, int count) {

    deallocateList(input);
    createList(input);

    startKata(false,"");

    int i = 0;
    while (!endKata && i < count) {
        insertAt(input,currentKata,0);
        advKata;
    }

    if (length(*input) < min) {
        return INVALID_INPUT;
    } else {
        return VALID_INPUT;
    }

}


// /* TYPE CONVERSION */

// int charToInt(char c) {

//     int i = c - 48;

//     return i;

// }

// int wordToInt(int *i, Word w) {

//     *i = 0;

//     int j = 0;
//     boolean valid = true;

//     while (j < wordLength(w) && valid) {
//         if (!isNumeric(w.buffer[j])) {
//             valid = false;
//         } else {
//             *i = *i + (charToInt(w.buffer[j]) * pow(10,wordLength(w) - 1));
//         }
//     }

//     if (!valid) {
//         return INVALID_INPUT;
//     } else {
//         return VALID_INPUT;
//     }

// }

// char intToChar(int i) {

//     int c = i + 48;

//     return c;

// }

// Word stringToWord(char *s) {

//     Word w;
//     createWord(&w);

//     int i = 0;
//     boolean end = false;
//     while (i < sizeof(s) && !end) {
//         if (s[i] == "\0") {
//             end = true;
//         } else {
//             w.buffer[i] = s[i];
//             i++;
//         }
//     }

//     return w;

// }

// /* WORD OPS */

// void createWord(Word *w) {

//     w->length = 0;

// }

// void concateWord(Word w1, Word w2, Word *w3) {

//     for (int i = 0; i < wordLength(w1); i++) {
//         w3->buffer[i] = w1.buffer[i];
//     }

//     for (int i = 0; i < wordLength(w2); i++) {
//         w3->buffer[i] = w2.buffer[i];
//     }

//     w3->length = wordLength(w1) + wordLength(w2);

// }

// void copyWord(Word *w1, Word *w2) {

//     for (int i = 0; i < w1->length; i++) {
//         w2->buffer[i] = w1->buffer[i];
//     }

//     w2->length = w1->length;

// }

// boolean isWordEqual(Word w1, Word w2) {

//     boolean equal = true;

//     if (wordLength(w1) != wordLength(w2)) {
//         equal = false;
//     } else {
//         int i = 0;
//         while (i < wordLength(w1) && equal) {
//             if (w1.buffer[i] != w2.buffer[i]) {
//                 equal = false;
//             }
//             i++;
//         }
//     }
//     return equal;

// }

// int wordLength(Word w) {

//     return (w).length;

// }

// /* CHAR OPS */

// char ord(char c) {

//     int i = c;
//     return i;

// }

// char alphabeticalOrd(char c) {

//     a = 0

//     c = lower(c);
//     int i = c;
//     return (i - 65);

// }

// char lower(char c) {

//     if (isLowercase(c)) {
//         return (c);
//     } else {
//         return (c - 32);
//     }

// }

// char upper(char c) {

//     if (isUppercase(c)) {
//         return (c);
//     } else {
//         return (c + 32);
//     }

// }

// boolean isUppercase(char c) {

//     return (c >= 65 && c <= 90);

// }

// boolean isLowercase(char c) {

//     return (c >= 97 && c <= 122);

// }

// boolean isAlpha(char c) {

//     return (isUppercase(c) && isLowercase(c));

// }

// boolean isNumeric(char c) {

//     return (c >= 48 && c <= 57);

// }

// boolean isCharInRange(char c, char a, char b) {

//     return ((c >= a) && (c <= b));

// }

// /* IGNORE */

// int intInput(int *i) {

//     char s[11];

//     scanf("%s",s);

//     if (isStringNumeric(s)) {

//         long int result = 0;

//         for (int j = 0; j < stringLength(s); j++) {
//             result = (result * 10) + charToInt(s[j]);
//         }

//         if (result > INT_MAX) {
//             return INVALID_INPUT;
//         }

//         *i = result;

//         return VALID_INPUT;

//     } else {

//         return INVALID_INPUT;

//     }

// }

// int stringInput(char *s, int length) {

//     if (sizeof(s) < length) {
//         length = sizeof(s);
//     }

//     int i = 0;
//     boolean newline = false;
//     while (i < length && !newline) {
//         scanf("%c",s[i]);
//         if (s[i] == '\n') {
//             newline = true;
//         } else {
//             i = i + 1;
//         }
//     }
    
//     if (newline || length != sizeof(s)) {
//         s[i] = '\0';
//     }
    
//     return VALID_INPUT;

// }

// boolean isStringAlpha(char *s) {

//     boolean alpha = true;
//     int i = 0;

//     while (alpha && i < stringLength(s)) {
//         if (!isAlpha(s[i])) {
//             alpha = false;
//         }
//         i = i + 1;
//     }

//     return alpha;

// }   

// boolean isStringNumeric(char *s) {

//     boolean numeric = true;
//     int i = 0;

//     while (numeric && i < stringLength(s)) {
//         if (!isNumeric(s[i])) {
//             numeric = false;
//         }
//         i = i + 1;
//     }

//     return numeric;

// }

// boolean isStringAlphaNumeric(char *s) {

//     boolean alphanumeric = true;
//     int i = 0;

//     while (alphanumeric && i < stringLength(s)) {
//         if (!isNumeric(s[i]) || !isAlpha(s[i])) {
//             alphanumeric = false;
//         }
//         i = i + 1;
//     }

//     return alphanumeric;

// }


// void stringCopy(char *s1, char *s2) {

//     for (int i = 0; i < stringLength(s1) && i < sizeof(s2); i++) {

//         s2[i] = s1[i];

//     }

// }

// int stringLength(char *s) {

//     int i = 0;
//     boolean end = false;
//     while (!end && i < sizeof(s)) {
//         if (s[i] == '\0') {
//             end = true;
//         } else {
//             i = i + 1;
//         }
//     }

//     if (!end) {
//         return sizeof(s);
//     } else {
//         return i;
//     }

// }

