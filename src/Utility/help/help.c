#include "../splash.h"
#include "../../Misc/io/io.h"

#include <stdio.h>
#include "help.h"

void helpStart()
{

    header();

    printf("Berikut command-command yang tersedia:\n");
    printf("1. START - Membaca file konfigurasi default yang berisi list game yang dapat dimainkan\n");
    printf("2. LOAD - Membaca save file yang ingin dibuka berisi list game yang dapat dimainkan\n");

    printf("\nTekan [ENTER] untuk kembali ke menu utama...");

    blankInput();
}

void help(){

    header();

    printf("Berikut command-command yang tersedia:\n");
    printf("1. SAVE - Menyimpan state game pemain saat ini ke dalam suatu file\n");
    printf("2. CREATE GAME - Menambahkan game baru pada daftar game\n");
    printf("3. LIST GAME - Menampilkan daftar game yang disediakan oleh sistem\n");
    printf("4. DELETE GAME - Menghapus sebuah game dari daftar game\n");
    printf("5. QUEUE GAME - Mendaftarkan permainan ke dalam list\n");
    printf("6. PLAY GAME - Memainkan sebuah permainan di urutan pertama antrian game\n");
    printf("7. SKIP GAME <N> - Melewatkan permainan dalam antrian game sebanyak N\n");
    printf("8. QUIT - Keluar dari program\n");

    printf("\nTekan [ENTER] untuk kembali ke menu utama...");

    blankInput();

}