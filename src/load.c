#include <stdio.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "list.h"

void load(char* filename, List *ListGame, List *ListHistory){
    createList(ListGame);
    createList(ListHistory);
    startLoad(filename);
    int i;
    int idx1 = wordToInt(currentKata);
    for (i=0; i < idx1; i++){
        advLoad();
        insertLast(ListGame, currentKata);
    }

    advLoad();
    int j;
    int idx2 = wordToInt(currentKata);
    for (j=0; j < idx2; j++){
        advLoad();
        insertLast(ListHistory, currentKata);
    }
    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
}

int main(){
    List ListGame, ListHistory;
    char filename[100];
    printf("masukkan file yang akan dibaca: \n");
    scanf("%s", filename); //ggaaannnttiiii//
    load(filename, &ListGame, &ListHistory);    
}