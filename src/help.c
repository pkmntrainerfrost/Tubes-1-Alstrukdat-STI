#include<stdio.h>
#include "../../help.h"

void help(){
    printf("berikut command-command yang tersedia:\n");
    printf("1. START (membaca file konfigurasi default)\n");
    printf("2. LOAD (diinputkan file yang akan dibaca)\n");
    printf("3. SAVE (menyimpan state game pemain saat ini)\n");
    printf("4. CREATEGAME (menambahkan game baru pada daftar game)\n");
    printf("5. LISTGAME (menampilkan daftar game yang disediakan oleh sistem)\n");
    printf("6. DELETEGAME (menghapus sebuah game dari daftar game)\n");
    printf("7. QUEUEGAME (mendaftarkan permainan kedalam list)\n");
    printf("8. PLAYGAME (memainkan sebuah permainan)\n");
    printf("9. SKIPGAME (melewatkan permainan sebanyak n)\n");
    printf("10. QUIT (keluar dari program)\n");
}
