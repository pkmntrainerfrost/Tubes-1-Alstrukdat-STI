#include <stdio.h>
#include "save.h"
static FILE *saveFile;

// bikin file baru
void savetoFile(char saveFilename[], List L)
{
    saveFile = fopen(saveFilename, "w");
    fprintf(saveFile, "%d\n", L.nEff);
    int i;
    for(i=0; i<length(L); i++){
        int j;
        for(j=0; j<L.A[i].length; j++){
            fprintf(saveFile, "%c", L.A[i].buffer[j]);
        }
        fprintf(saveFile, "\n");
    }

    fclose(saveFile);
    printf("Save file berhasil disimpan\n");
}

// int main()
// {
//     List L;
//     createList(&L);
//     insertLast(&L, stringToWord("RNG"));
//     insertLast(&L, stringToWord("Diner DASH"));
//     insertLast(&L, stringToWord("DINOSAUR IN EARTH"));
//     insertLast(&L, stringToWord("RISEWOMAN"));
//     insertLast(&L, stringToWord("EIFFEL TOWER"));
//     insertLast(&L, stringToWord("Battleship")); 
//     insertLast(&L, stringToWord("Tetris"));
//     displayList(L);
//     printf("\n");
//     Word check2;
//     boolean cek = wordInput(&check2,1,10);
//     char s2[wordLength(check2) + 1];
//     wordToString(check2, s2);
//     savetoFile(s2, L);
//     return 0;
// }

//compile: gcc Utility/save/save.c ADT/list/array.c ADT/word/word.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c Misc/io/io.c Misc/ascii/ascii.c -o driver
