/* File         : io.c */
/* Deskripsi    : Implementasi library io buatan gweh */

#include <stdio.h>
#include <stdlib.h>
#include "io.h"

char ord(char c) {

    int i = c;
    return i;

}

char alphabeticalOrd(char c) {

    // a = 0

    c = lower(c);
    int i = c;
    return (i - 65);

}

char lower(char c) {

    if (isLowercase(c)) {
        return (c);
    } else {
        return (c - 32);
    }

}

char upper(char c) {

    if (isUppercase(c)) {
        return (c);
    } else {
        return (c + 32);
    }

}

boolean isUppercase(char c) {

    return (c >= 65 && c <= 90);

}

boolean isLowercase(char c) {

    return (c >= 97 && c <= 122);

}

boolean isAlpha(char c) {

    return (isUppercase(c) && isLowercase(c));

}

boolean isNumeric(char c) {

    return (c >= 48 && c <= 57);

}

boolean isCharInRange(char c, char a, char b) {

    return ((c >= a) && (c <= b));

}

boolean isStringAlpha(char *s) {

    boolean alpha = true;
    int i = 0;

    while (alpha && i < stringLength(s)) {
        if (!isAlpha(s[i])) {
            alpha = false;
        }
        i = i + 1;
    }

    return alpha;

}   

boolean isStringNumeric(char *s) {

    boolean numeric = true;
    int i = 0;

    while (numeric && i < stringLength(s)) {
        if (!isNumeric(s[i])) {
            numeric = false;
        }
        i = i + 1;
    }

    return numeric;

}

boolean isStringAlphaNumeric(char *s) {

    boolean alphanumeric = true;
    int i = 0;

    while (alphanumeric && i < stringLength(s)) {
        if (!isNumeric(s[i]) || !isAlpha(s[i])) {
            alphanumeric = false;
        }
        i = i + 1;
    }

    return alphanumeric;

}

int charToInt(char c) {

    int i = c - 48;

    return i;

}

int intInput(int *i) {

    char s[11];

    scanf("%s",s);

    if (isStringNumeric(s)) {

        long int result = 0;

        for (int j = 0; j < stringLength(s); j++) {
            result = (result * 10) + charToInt(s[j]);
        }

        if (result > INT_MAX) {
            return INVALID_INPUT;
        }

        *i = result;

        return VALID_INPUT;

    } else {

        return INVALID_INPUT;

    }

}

int stringInput(char *s, int length) {

    if (sizeof(s) < length) {
        length = sizeof(s);
    }

    int i = 0;
    boolean newline = false;
    while (i < length && !newline) {
        scanf("%c",s[i]);
        if (s[i] == '\n') {
            newline = true;
        } else {
            i = i + 1;
        }
    }
    
    if (newline || length != sizeof(s)) {
        s[i] = '\0';
    }
    
    return VALID_INPUT;

}

int stringLength(char *s) {

    int i = 0;
    boolean end = false;
    while (!end && i < sizeof(s)) {
        if (s[i] == '\0') {
            end = true;
        } else {
            i = i + 1;
        }
    }

    if (!end) {
        return sizeof(s);
    } else {
        return i;
    }

}
