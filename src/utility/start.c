#include <stdio.h>
#include "boolean.h"
#include "../ADT/word/mesinkata/mesinkata.h"
#include "../ADT/list/array.h"

void START(List *ListGame){
    createList(ListGame);
    char file[] = "fileconfig.txt";
    char *configfile = file;
    int i;
    int idx = currentKata.buffer[0] - 48;
    for (i=0; i < idx; i++){
        advKata();
        insertLast(ListGame, currentKata);
    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}

int main(){
    List ListGame;
    START(&ListGame);
}