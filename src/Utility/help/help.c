#include "../splash.h"
#include "../../Misc/io/io.h"

#include <stdio.h>
#include "help.h"

void help(){

    header();

    printf("Berikut command-command yang tersedia:\n");
    printf("1. START - Membaca file konfigurasi default berisi game yang dapat dimainkan\n");
    printf("2. LOAD - Input save file yang ingin dibaca\n");
    printf("3. SAVE - Menyimpan state game pemain saat ini ke dalam suatu file\n");
    printf("4. CREATEGAME - Menambahkan game baru pada daftar game\n");
    printf("5. LISTGAME - Menampilkan daftar game yang disediakan oleh sistem\n");
    printf("6. DELETEGAME - Menghapus sebuah game dari daftar game\n");
    printf("7. QUEUEGAME - Mendaftarkan permainan ke dalam list\n");
    printf("8. PLAYGAME - Memainkan sebuah permainan di urutan pertama antrian game\n");
    printf("9. SKIPGAME - Melewatkan permainan dalam antrian game sebanyak n\n");
    printf("10. QUIT - Keluar dari program\n");

    printf("Tekan [ENTER] untuk kembali ke menu utama...\n");

    blankInput();

}