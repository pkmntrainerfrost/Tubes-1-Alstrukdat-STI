#include "Utility/splash.h"
#include "Misc/io/io.h"
#include "ADT/boolean.h"
#include "ADT/word/word.h"
#include "ADT/list/array.h"
#include "Utility/start/start.h"
#include "Utility/load/load.h"

#include <stdio.h>

int main() {

    List ListGame;
    createList(&ListGame);

    boolean Started = false;

    boolean InvalidFile = false;
    int Tries = 0;

    while (!Started) {

        header();
        splash(Tries,Started);

        List Input;
        createList(&Input);
        boolean Valid = multiWordInput(&Input,1,2);

        if (Valid) {
            if (isWordEqual(getElmt(Input,0),stringToWord("START")) && length(Input) == 1) {
                START(&ListGame);
                printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
                Started = true;
            } else if (isWordEqual(getElmt(Input,0),stringToWord("LOAD")) && length(Input) == 2) {
                InvalidFile = CHECKFILE(getElmt(Input,1));
                if (!InvalidFile) {
                    LOAD(getElmt(Input,1),&ListGame);
                    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
                    Started = true;
                } else {
                    printf("Save file tidak ditemukan! Silahkan ulangi input.\n");
                    Tries = Tries + 1;
                }
            } else {
                printf("Masukan tidak valid! Silahkan ulangi input.\n");
                Tries = Tries + 1;
            }
        } else {
            if (length(Input) > 0) {
                printf("Masukan tidak valid! Silahkan ulangi input.\n");
            } else {
                printf("Masukan tidak boleh kosong! Silahkan ulangi input.\n");
            }
            Tries = Tries + 1;
        }

        printf("\nTekan [ENTER] untuk melanjutkan...\n");

        blankInput();

        deallocateList(&Input);

    }

    while (Started) {

        header();
        splash(Tries,Started);

        List Input;
        createList(&Input);
        int Valid = multiWordInput(&Input,1,2);

        if (Valid) {
            if (length(Input) == 1) { 

            } else {
                
            }
        } else {
            if (length(Input) > 0) {
                printf("Masukan tidak valid! Silahkan ulangi input.\n");
            } else {
                printf("Masukan tidak boleh kosong! Silahkan ulangi input.\n");
            }
            Tries = Tries + 1;
        }

    }

}

