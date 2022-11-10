/* File         : io.h */
/* Deskripsi    : Header Library I/O */

/* Digunakan untuk melakukan input dengan verifikasi */

#ifndef __IO__
#define __IO__

#include "../../ADT/boolean.h"
#include "../../ADT/word/word.h"
#include "../../ADT/list/array.h"

#define INVALID_INPUT 0
#define VALID_INPUT 1

/* Meminta user untuk menginput satu buah kata dengan panjang minimal min dan panjang maksimal max, lalu menyimpannya di w. Kata dianggap berakhir ketika bertemu dengan karakter newline. Apabila input melebihi max atau N_MAX, karakter yang lebih akan diabaikan. Apabila input kurang dari min, akan mengembalikan INVALID_INPUT. */
int wordInput(Word *w, int min, int max);

/* Meminta user untuk menginput beberapa kata dengan banyak minimal min dan banyak maksimal max, lalu menyimpannya di array of kata input. Input dianggap berakhir ketika bertemu dengan karakter newline, dan kata dipisahkan berdasarkan spasi. Apabila input melebihi max, kata yang lebih akan diabaikan. Apabila input kurang dari min, akan mengembalikan INVALID_INPUT. */
int multiWordInput(List *input, int min, int count);

// int charToInt(char c);

// char intToChar(int i);

// void commandInput();

// /*
// void wordInput(Word *w);

// void multiWordInput(List *l);
// */

// char ord(char c);

// char alphabeticalOrd(char c);

// char lower(char c);

// char upper(char c);

// boolean isUppercase(char c);

// boolean isLowercase(char c);

// boolean isAlpha(char c);

// boolean isNumeric(char c);

// boolean isCharInRange(char c, char a, char b);

// boolean isStringAlpha(char *s);

// boolean isStringNumeric(char *s);

// boolean isStringAlphaNumeric(char *s);


// /* Meminta user untuk memasukkan sebuah integer. Akan mengembalikan INVALID_INPUT bila masukan tidak valid. */
// int intInput(int *i);

// /* Meminta user untuk memasukkan sebuah string dengan panjang (length) tertentu. Apabila jumlah karakter melebihi panjang, input akan dipotong. Hasil input disimpan di s. */
// /* DEKLARASIKAN STRING DULU DENGAN KAPASITAS LENGTH + 1!!!! */
// int stringInput(char *s, int length);

// /* Mengembalikan panjang string. */
// int stringLength(char *s);

// void stringCopy(char *s1, char *s2);

#endif