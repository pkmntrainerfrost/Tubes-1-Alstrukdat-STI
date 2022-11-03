#include <stdio.h>
#include "save.h"
static FILE *saveFile;

// bikin file baru
void savetoFile(char saveFilename[], List L)
{
    saveFile = fopen(saveFilename, "w");
    fprintf("%d\n", L.nEff);
    int i;
    for(i=0; i<L.nEff; i++){
        fprintf(saveFile, "%d. %s\n", i+1, L.buffer[i].character);
    }

    fclose(saveFile);
}