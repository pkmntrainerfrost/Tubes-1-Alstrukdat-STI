#include "Utility/splash.h"
#include "Misc/io/io.h"
#include "ADT/boolean.h"
#include "ADT/word/word.h"
#include "ADT/list/array.h"
#include "utility/start/start.h"
#include "utility/load/load.h"
#include "utility/help/help.h"
#include "Utility/commandlain/commandlain.h"

#include <stdio.h>

int main() {

    List ListGame;
    createList(&ListGame);

    boolean Started = false;

    boolean InvalidFile = false;
    int Tries = 0;

    while (!Started) {

        splash(Tries);

        List Input;
        createList(&Input);
        boolean Valid = multiWordInput(&Input,1,2);
        help();

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
                commandlain();
                Tries = Tries + 1;
            }
        } else {
            printf("Masukan tidak boleh kosong! Silahkan ulangi input.\n");
            Tries = Tries + 1;
        }

        deallocateList(&Input);

    }

}

