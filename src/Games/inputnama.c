#include <stdio.h>
#include "../ADT/map/map.h"
#include "../ADT/word/word.h"
#include "../Misc/io/io.h"

void inputName(Map *M)
{
    boolean repeat = true;
    while (repeat){
        printf("Masukkan nama: ");
        Word name;
        boolean valid = wordInput(&name, 1, N_MAX);

        if (valid){
            if (IsMemberMap(*M, name)){
                printf("Nama sudah ada di daftar scoreboard. \n");
            } else {
                printf("Masukkan score: ");
                int score;
                scanf("%d", &score);
                InsertMap(M, name, score);
                repeat = false;
            }
        } else {
            if (wordLength(name) == 0){
                printf("Nama tidak boleh kosong. \n");
            } else {
                printf("Nama terlalu panjang. \n");
            }
        }
    }
}

int main(){
    Map m;
    CreateEmptyMap(&m);
    inputName(&m);
}

// compile : gcc Games/inputnama.c ADT/map/map.c ADT/word/word.c Misc/ascii/ascii.c Misc/io/io.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/mesinkata/mesinkata.c ADT/list/array.c -o driver