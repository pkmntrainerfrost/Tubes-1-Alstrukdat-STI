#include <stdio.h>
#include <stdlib.h>
#include "quit.h"

void quit(List ListGame){

    header();

    Word Check;
    boolean Save = false;
    boolean Valid = false;
    boolean InputValid = false;
    int InvalidInputs = 0;

    while (!InputValid) {
    
        if (InvalidInputs == 0) {
            printf("Apakah Anda ingin melakukan save terlebih dahulu? [Y/N]: ");
        } else {
            printf("Ulangi input!: ");
        }

        Valid = wordInput(&Check,1,1);

        if (Valid) {
            if (isAlpha(Check.buffer[0]) && (lower(Check.buffer[0]) == 'y' || lower(Check.buffer[0]) == 'n')) {
                if (lower(Check.buffer[0]) == 'y') {
                    Save = true;
                } else {
                    Save = false;
                }
                InputValid = true;
            } else {
                InvalidInputs = InvalidInputs + 1;
            }
        } else {
            InvalidInputs = InvalidInputs + 1; 
        }

    }

    if (Save) {
        InputValid = false;
        
        while (!InputValid) {
    
        if (InvalidInputs == 0) {
            printf("Masukkan nama file penyimpanan: ");
        } else {
            printf("Ulangi input!: ");
        }

        Valid = wordInput(&Check,1,N_MAX);

        for (int i = 0; i < wordLength(Check); i++) {
            if (Check.buffer[i] == ' ') {
                Valid = false;
            }
        }

        if (Valid) {
            if (lower(Check.buffer[wordLength(Check)-4]) == '.' && lower(Check.buffer[wordLength(Check)-3]) == 't' && lower(Check.buffer[wordLength(Check)-2]) == 'x' && lower(Check.buffer[wordLength(Check)-1]) == 't') {
                InputValid = true;
                char a[wordLength(Check) + 1];
                wordToString(Check,a);
                savetoFile(a, ListGame);
            } else {
                InvalidInputs = InvalidInputs + 1;
            }
        } else {
            InvalidInputs = InvalidInputs + 1; 
        }


        }
    }

    printf("Anda keluar dari game BNMO.\n");
    printf("Bye bye ...\n");
    exit(0);
}