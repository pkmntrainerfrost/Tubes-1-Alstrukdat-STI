#include <stdio.h>
#include "save.h"
static FILE *saveFile;

// bikin file baru
void savetoFile(char saveFilename[], List L)
{
    saveFile = fopen(saveFilename, "w");
    fprintf(saveFile, "%d\n", L.nEff);
    int i;
    for(i=0; i<L.nEff; i++){
        fprintf(saveFile, "%d. %s\n", i+1, L.A[i].buffer);
    }

    fclose(saveFile);
    printf("Save file berhasil disimpan\n");
}

// int main()
// {
//     List L;
//     createList(&L);
//     ElType test;
//     test = stringToWord("hai");
//     insertLast(&L, test);
//     test = stringToWord("halo");
//     insertLast(&L, test); 
//     // blm bikin scanf buat saveFilename
//     savetoFile("test.txt", L);
//     return 0;
// }

// 2
// 1. hai
// 2. halo #@
// knp hasilnya ada #@ ya?