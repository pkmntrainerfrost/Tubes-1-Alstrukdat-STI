#include "../ADT/map/map.h"
#include "../ADT/word/word.h"

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