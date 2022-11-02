/* File         : io.h */
/* Deskripsi    : Header Library I/O */

/* Digunakan untuk melakukan input dengan verifikasi */

#ifndef __IO__
#define __IO__

#include "../boolean.h"

#define VALID_INPUT 0;
#define INVALID_INPUT 1;

char ord(char c);

char alphabeticalOrd(char c);

char lower(char c);

char upper(char c);

boolean isUppercase(char c);

boolean isLowercase(char c);

boolean isAlpha(char c);

boolean isNumeric(char c);

boolean isStringAlpha(char *s);

boolean isStringNumeric(char *s);

boolean isStringAlphaNumeric(char *s);

int charToInt(char c);

/* Meminta user untuk memasukkan sebuah integer. Akan mengembalikan INVALID_INPUT bila masukan tidak valid. */
int intInput(int *i);

/* Meminta user untuk memasukkan sebuah string dengan panjang (length) tertentu. Apabila jumlah karakter melebihi panjang, input akan dipotong. Hasil input disimpan di s. */
/* DEKLARASIKAN STRING TERLEBIH DAHULU DENGAN KAPASITAS LENGTH + 1!!!! */
int stringInput(char *s, int length);

/* Mengembalikan panjang string. */
int stringLength(char *s);

#endif