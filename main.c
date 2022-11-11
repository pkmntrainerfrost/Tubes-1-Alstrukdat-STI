#include "src/Utility/splash.h"
#include "src/Misc/io/io.h"
#include "src/ADT/boolean.h"
#include "src/ADT/word/word.h"
#include "src/ADT/list/array.h"
#include "src/ADT/queue/queue2.h"
#include "src/utility/start/start.h"
#include "src/utility/load/load.h"
#include "src/utility/help/help.h"
#include "src/utility/commandlain/commandlain.h"
#include "src/utility/quit/quit.h"
#include "src/utility/listGame/listGame.h"
#include "src/utility/deleteGame/deleteGame.h"
#include "src/utility/playGame/playGame.h"
#include "src/utility/queuegame/queueGame.h"
#include "src/utility/skipGame/skipGame.h"
#include "src/utility/save/save.h"

#include <stdio.h>

int main() {

    List ListGame;
    createList(&ListGame);

    Queue QueueGame;
    createQueue(&QueueGame);

    boolean Started = false;

    boolean InvalidFile = false;
    int Tries = 0;

    while (!Started) {

        printf("\e[1;1H\e[2J");
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
        int Valid = multiWordInput(&Input,1,3);

        if (Valid) {
            if (length(Input) == 1) { 
                if (isWordEqual(getElmt(Input,0),stringToWord("QUIT"))){
                    quit();
                } else {
                    commandlain();
                }
            } else if (length(Input) == 2) {
                if (isWordEqual(getElmt(Input,1),stringToWord("GAME"))){
                    if (isWordEqual(getElmt(Input,0),stringToWord("LIST"))){
                        listGameMain(ListGame);
                    } else if (isWordEqual(getElmt(Input,0),stringToWord("DELETE"))){
                        deleteGame(&ListGame, QueueGame);
                    } else if (isWordEqual(getElmt(Input,0),stringToWord("PLAY"))){
                        playGame(&QueueGame, ListGame);
                    } else if (isWordEqual(getElmt(Input,0),stringToWord("QUEUE"))){
                        queueGame(&QueueGame, ListGame);
                    } else {
                        commandlain();
                    }
                } else {
                    commandlain();      
                }
            } else {
                if (isWordEqual(getElmt(Input,0),stringToWord("SKIP")) && isWordEqual(getElmt(Input,1),stringToWord("GAME")) && wordToInt(getElmt(Input,2)) != INVALID_INT && wordToInt(getElmt(Input,2)) >= 0) {
                    skipGame(&QueueGame,ListGame,wordToInt(getElmt(Input,2)));
                } else {
                    commandlain();
                }   
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

