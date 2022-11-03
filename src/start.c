#include <stdio.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "list.h"

void START(List *ListGame){
    createList(ListGame);
    char *configfile = "fileconfig.txt";
    STARTWORD(configfile);
    int i;
    int idx = currentKata.buffer[0] - 48;
    for (i=0; i < idx; i++){
        ADVWORD();
        insertLast(ListGame, currentKata);
    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}

int main(){
    List ListGame;
    START(&ListGame);
}