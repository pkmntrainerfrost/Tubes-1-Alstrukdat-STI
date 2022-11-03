#include <stdio.h>
#include "save.h"
static FILE *saveFile;

// hilangin lengthnya gabisa (?)
int Length(char *str)
{
    int i=0, count=0;
    while (str[i] != '\0'){
        count++;
        i++;
    }
    return count;
}

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

int main()
{
    List L;
    createList(&L);
    printf("Input command: ");
    char *command;
    // gabole scanf
    scanf("%s", command);
    int panjang = Length(command);
    // pake word machine
    if (command[0] == 's' && command[1] == 'a' && command[2] == 'v' && command[3] == 'e'){ 
        char *saveFilename;
        scanf("%s", saveFilename);
        savetoFile(saveFilename, L);
    }

    return 0;    
}