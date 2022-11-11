#include "../splash.h"
#include "../../Misc/io/io.h"

#include <stdio.h>
#include "help.h"

void help(){

    header();

    printf("Berikut command-command yang tersedia:\n");
    printf("1. SAVE - Menyimpan state game pemain saat ini ke dalam suatu file\n");
    printf("2. CREATEGAME - Menambahkan game baru pada daftar game\n");
    printf("3. LISTGAME - Menampilkan daftar game yang disediakan oleh sistem\n");
    printf("4. DELETEGAME - Menghapus sebuah game dari daftar game\n");
    printf("5. QUEUEGAME - Mendaftarkan permainan ke dalam list\n");
    printf("6. PLAYGAME - Memainkan sebuah permainan di urutan pertama antrian game\n");
    printf("7. SKIPGAME - Melewatkan permainan dalam antrian game sebanyak n\n");
    printf("8. QUIT - Keluar dari program\n");

    printf("\nTekan [ENTER] untuk kembali ke menu utama...\n");

    blankInput();

}