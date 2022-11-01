/* File         : io.h */
/* Deskripsi    : Header Library I/O */

/* Digunakan untuk melakukan input dengan verifikasi */

#ifndef __IO__
#define __IO__

#include "../boolean.h"

#define VALID_INPUT 0;
#define INVALID_INPUT 1;

boolean isUppercase(char c);

boolean isLowercase(char c);

boolean isCharAlpha(char c);

boolean isCharNumeric(char c);

boolean isAlpha(char *s);

boolean isNumeric(char *s);

boolean isAlphaNumeric(char *s);

int stringLength(char *s);

int intInput(int *i);

int charInput(char *c);

int stringInput(char *s);

#endif