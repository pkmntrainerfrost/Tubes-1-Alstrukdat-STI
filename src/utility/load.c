#include <stdio.h>
#include "boolean.h"
#include "../ADT/mesinkar/mesinkar_input.h"
#include "../ADT/mesinkar/mesinkata_input.h"
#include "../ADT/list/array.h"

void load(char* filename, List *ListGame, List *ListHistory){
    createList(ListGame);
    startKataInput(filename);
    int i;
    int idx1 = wordToInt(currentKataInput);
    for (i=0; i < idx1; i++){
        advLoad();
        insertLast(ListGame, currentKataInput);
    }
    advLoad();
    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
}

int main(){
    List ListGame, ListHistory;
    char filename[100];
    printf("masukkan file yang akan dibaca: \n");
    scanf("%s", filename); //ggaaannnttiiii//
    load(filename, &ListGame, &ListHistory);    
}