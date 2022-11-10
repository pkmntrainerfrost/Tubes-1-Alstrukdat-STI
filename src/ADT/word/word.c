/* FILE         : word.c */
/* DESKRIPSI    : Implementasi ADT Word (pengganti string) */

#include <stdio.h>
#include <math.h>
#include "word.h"

/* Membuat kata kosong dengan panjang 0 */
void createWord(Word *w) {

    w->length = 0;

}

/* Menggabung w1 dan w2 dan menyimpannya di w3 */
void concateWord(Word w1, Word w2, Word *w3) {

    int length = wordLength(w1) + wordLength(w2);

    if (length < N_MAX) {
        length = N_MAX;
    }

    for (int i = 0; i < wordLength(w1); i++) {
        w3->buffer[i] = w1.buffer[i];
    }

    for (int i = wordLength(w1); i < length; i++) {
        w3->buffer[i] = w2.buffer[i];
    }

    wordLength(*w3) = length;

}

/* Menggabung w1 dan w2 dan menyimpannya di w3 */
void copyWord(Word w1, Word *w2) {

    for (int i = 0; i < wordLength(w1); i++) {
        w2->buffer[i] = w1.buffer[i];
    }

    wordLength(*w2) = wordLength(w1);

}

/* Merubah sebuah integer menjadi sebuah word */
Word intToWord(int i) {

    Word w;
    createWord(&w);

    int j = 0;

    do {
        w.buffer[j] = intToChar(i % 10);
        i = i / 10;
        j = j + 1;
    } while (i != 0);

    wordLength(w) = j;

    return w;

}

/* Merubah sebuah string menjadi sebuah word */
Word stringToWord(char *s) {

    Word w;
    createWord(&w);

    boolean end = false;
    int i = 0;

    while (i < sizeof(s) && !end) {
        if (s[i] == '\0') {
            end = true;
        } else {
            w.buffer[i] = s[i];
            i = i + 1;
        }
    }

    wordLength(w) = i;

    return w;

}

/* Merubah sebuah kata menjadi suatu integer, apabila word bukan integer yang valid maka akan mengembalikan INT_INVALID */
int wordToInt(Word w) {

    long i = 0;
    boolean valid = true;
    boolean neg = false;
    
    int j = 0;
    while (j < wordLength(w) && valid) {
        if (isNumeric(w.buffer[j])) {
            i = i + (charToInt(w.buffer[j]) * pow(10,(wordLength(w) - 1 - j)));
            if (i > 0x7FFFFFFF) {
                i = INVALID_INT;
                valid = false;
            }
            j = j + 1;
        } else if (j == 0 && w.buffer[j] == '-') {
            neg = true;
        } else {
            i = INVALID_INT;
            valid = false;
        }
    }

    int result = i;

    return result;

}

/* Merubah sebuah word menjadi suatu string dan menyimpannya di s. PENTING: DEFINISIKAN S TERLEBIH DAHULU DENGAN KAPASITAS WORDLENGTH + 1 */
void wordToString(Word w, char *s) {

    int length = wordLength(w);

    if (sizeof(s) < length + 1) {
        length = sizeof(s);
    }

    int i = 0;
    while (i < length) {
        s[i] = w.buffer[i];
        i = i + 1;
    }

}

/* Mengecek apakah dua buah kata merupakan kata yang sama */
boolean isWordEqual(Word w1, Word w2) {

    boolean equal = (wordLength(w1) == wordLength(w2));

    int i = 0;
    while (equal && i < wordLength(w1)) {
        if (w1.buffer[i] != w2.buffer[i]) {
            equal = false;
        }
        i = i + 1;
    }

    return equal;

}

/* Mencetak sebuah word ke layar, tanpa tambahan karakter didepan + dibelakangnya */
void printWord(Word w) {

    for (int i = 0; i < wordLength(w); i++) {
        printf("%c",w.buffer[i]);
    }

}