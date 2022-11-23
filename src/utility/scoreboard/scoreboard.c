#include <stdio.h>
#include "scoreboard.h"

void displayscoreboard(Map M){
    if (IsEmptyMap(M)){
        printf("---- SCOREBOARD KOSONG ----\n");
    } else {
        int i;
        printf("|---------------------------|\n");
        for (i=0; i<M.Count; i++){
            int j;
            printf("| ");
            for (j=0; j<M.Elements[i].name.length; j++){
                printf("%c", M.Elements[i].name.buffer[j]);
            }
            int k = M.Elements[i].name.length;
            for(k; k<12; k++){
                printf(" ");
            }
            printf("| %-12d", M.Elements[i].score);
            printf("|\n");
        }
    }
}

void inserttoscoreboard(Map *M, Word nama, int score){

}

// int main(){
//     Map MapHangman;
//     Map Mapdinerdash;
//     printf("**** SCOREBOARD GAME HANGMAN ****\n");
//     printf("| NAMA        | SKOR        |\n");
//     displayscoreboard(MapHangman);
//     displayscoreboard(Mapdinerdash);
// }