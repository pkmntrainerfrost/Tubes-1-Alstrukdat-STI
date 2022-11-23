#include "maphangman.h"

void sbHangman(Map h){
    printf("**** SCOREBOARD GAME HANGMAN ****\n");
    printf("| NAMA        | SKOR        |\n");
    if (IsEmptyMap(h)){
        printf("---- SCOREBOARD KOSONG ----\n");
    } else {
        int i;
        printf("|---------------------------|\n");
        for (i=0; i<h.Count; i++){
            int j;
            printf("| ");
            for (j=0; j<h.Elements[i].name.length; j++){
                printf("%c", h.Elements[i].name.buffer[j]);
            }
            int k = h.Elements[i].name.length;
            for(k; k<12; k++){
                printf(" ");
            }
            printf("| %-12d", h.Elements[i].score);
            printf("|\n");
        }
        
    }
}

// int main(){
//     Map M;
//     CreateEmptyMap(&M);
//     keytype test, test1;
//     test = stringToWord("hai");
//     test1 = stringToWord("halo");
//     valuetype testInfo, test1Info;
//     testInfo = 10;
//     test1Info = 20;
//     InsertMap(&M, test, testInfo);
//     InsertMap(&M, test1, test1Info);
//     sbHangman(M);
//     DeleteMap(&M, test);
//     sbHangman(M);
    
//     return 0;
// }

// compile main nya: gcc ADT/map/maphangman.c ADT/map/map.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/ascii/ascii.c -o driver