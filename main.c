#include "src/Utility/splash.h"
#include "src/Misc/io/io.h"
#include "src/ADT/boolean.h"
#include "src/ADT/word/word.h"
#include "src/ADT/list/array.h"
#include "src/ADT/queue/queue2.h"
#include "src/Utility/start/start.h"
#include "src/Utility/load/load.h"
#include "src/Utility/help/help.h"
#include "src/Utility/commandlain/commandlain.h"
#include "src/Utility/quit/quit.h"
#include "src/Utility/listGame/listGame.h"
#include "src/Utility/deleteGame/deleteGame.h"
#include "src/Utility/creategame/createGame.h"
#include "src/Utility/playGame/playGame.h"
#include "src/Utility/queuegame/queueGame.h"
#include "src/Utility/skipGame/skipGame.h"
#include "src/Utility/save/save.h"

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
        boolean noEnter = false;

        if (Valid) {
            if (isWordEqual(getElmt(Input,0),stringToWord("START")) && length(Input) == 1) {
                START(&ListGame);
                printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
                Started = true;
            } else if (isWordEqual(getElmt(Input,0),stringToWord("HELP")) && length(Input) == 1) {
                noEnter = true;
                helpStart();
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
        
        if (!noEnter) {
            printf("Tekan [ENTER] untuk melanjutkan...");
            blankInput();
        }
        
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
                    quit(&ListGame,&QueueGame);
                } else if (isWordEqual(getElmt(Input,0),stringToWord("HELP"))) {
                    help();
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
                    } else if (isWordEqual(getElmt(Input,0),stringToWord("CREATE"))){
                        createGame(&ListGame);
                    } else if (isWordEqual(getElmt(Input,0),stringToWord("SKIP")) && wordToInt(getElmt(Input,2)) != INVALID_INT && wordToInt(getElmt(Input,2)) >= 0){
                        skipGame(&QueueGame,ListGame,wordToInt(getElmt(Input,2)));
                    } else {
                        commandlain();
                    }
                } else if (isWordEqual(getElmt(Input,0),stringToWord("SAVE"))){
                    Word Check = getElmt(Input,1);
                    if (lower(Check.buffer[wordLength(Check)-4]) == '.' && lower(Check.buffer[wordLength(Check)-3]) == 't' && lower(Check.buffer[wordLength(Check)-2]) == 'x' && lower(Check.buffer[wordLength(Check)-1]) == 't') {
                            char a[wordLength(Check) + 1];
                            wordToString(Check,a);
                            savetoFile(a, ListGame);
                    } else {
                        printf("Nama file tidak valid!\n");
                    } 
                } else {
                    commandlain();
                    printf("Tekan [ENTER] untuk melanjutkan...");
                    blankInput();
                }
            } else if (length(Input) == 3){
                if (isWordEqual(getElmt(Input,0),stringToWord("SKIP")) && isWordEqual(getElmt(Input,1),stringToWord("GAME")) && wordToInt(getElmt(Input,2)) != INVALID_INT && wordToInt(getElmt(Input,2)) >= 0){
                    skipGame(&QueueGame,ListGame,wordToInt(getElmt(Input,2)));
                } else {
                    commandlain();
                    printf("Tekan [ENTER] untuk melanjutkan...");
                    blankInput();
                }
            } else {
                commandlain();
                printf("Tekan [ENTER] untuk melanjutkan...");
                blankInput();
            } 
        } else {
            if (length(Input) > 0) {
                commandlain();
            } else {
                printf("Masukan tidak boleh kosong! Silahkan ulangi input.\n");
            }
            printf("Tekan [ENTER] untuk melanjutkan...");
            blankInput();
            Tries = Tries + 1;
        }

        deallocateList(&Input);
        

    }

}

