#include <stdio.h>
#include <stdlib.h>
#include "io.h"

boolean isUppercase(char c) {

    return (c >= 65 && c <= 90);

}

boolean isLowercase(char c) {

    return (c >= 97 && c <= 122);

}

boolean isCharAlpha(char c) {

    return (isUppercase(c) && isLowercase(c));

}

boolean isCharNumeric(char c) {

    return (c >= 48 && c <= 57);

}

boolean isAlpha(char *s);

boolean isNumeric(char *s) {

    boolean numeric = true;
    int i = 0;

    while (numeric && i < stringLength(s)) {
        if (!isCharNumeric(s[i])) {
            numeric = false;
        }
        i = i + 1;
    }

    return numeric;

}

boolean isAlphaNumeric(char *s);

int charToInt(char c) {

    int i = c - 48;

    return i;

}

int intInput(int *i) {

    char s[11];

    scanf("%s",s);

    if (isNumeric(s)) {

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

int charInput(char *c) {
    
}

int stringInput(char *s);