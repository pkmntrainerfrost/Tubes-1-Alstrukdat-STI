// void resetscoreboard(Map M){
//     printf("DAFTAR SCOREBOARD: \n");
//     printf("0. ALL\n");
//     printf("1. RNG\n");
//     printf("2. DINER DASH\n");
//     printf("3. HANGMAN\n");
//     printf("4. TOWER OF HANOI\n");
//     printf("5. SNAKE ON METEOR\n\n");
//     printf("SCOREBOARD YANG INGIN DIHAPUS: ");
//     Word input;
//     boolean valid = wordInput(&input, 1, 1);
//     int inputan;
//     inputan = wordToInt(input);

    
//     printf("\n");
//     if(valid && inputan==0){
//         printf("APAKAH KAMU INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)? ");
//         char yes[] = "YA";
//         Word ansyes = stringToWord(yes);
//         char no[] = "TIDAK";
//         Word ansno = stringToWord(no);

//         Word input;
//         boolean valid = wordInput(&input, 1, N_MAX);

//         printf("\n");
//         if(isWordEqual(input, ansyes)){
//             deallocateMap(&M);
//             printf("Scoreboard berhasil di-reset.\n");
//         }else if(isWordEqual(input, ansno)){
//             printf("Scoreboard tidak di-reset.\n");
//         }
//     }else if(valid && inputan==1){
//         printf("APAKAH KAMU INGIN MELAKUKAN RESET SCOREBOARD RNG (YA/TIDAK)? ");
//         char yes[] = "YA";
//         Word ansyes = stringToWord(yes);
//         char no[] = "TIDAK";
//         Word ansno = stringToWord(no);

//         Word input;
//         boolean valid = wordInput(&input, 1, N_MAX);

//         printf("\n");
//         if(isWordEqual(input, ansyes)){
//             printf("Scoreboard berhasil di-reset.\n");
//         }else if(isWordEqual(input, ansno)){
//             printf("Scoreboard tidak di-reset.\n");
//         }
//     }else if(valid && inputan==2){
//         printf("APAKAH KAMU INGIN MELAKUKAN RESET SCOREBOARD DINERDASH (YA/TIDAK)? ");
//         char yes[] = "YA";
//         Word ansyes = stringToWord(yes);
//         char no[] = "TIDAK";
//         Word ansno = stringToWord(no);

//         Word input;
//         boolean valid = wordInput(&input, 1, N_MAX);

//         printf("\n");
//         if(isWordEqual(input, ansyes)){
//             printf("Scoreboard berhasil di-reset.\n");
//         }else if(isWordEqual(input, ansno)){
//             printf("Scoreboard tidak di-reset.\n");
//         }
//     }else if(valid && inputan==3){
//         printf("APAKAH KAMU INGIN MELAKUKAN RESET SCOREBOARD HANGMAN (YA/TIDAK)? ");
//         char yes[] = "YA";
//         Word ansyes = stringToWord(yes);
//         char no[] = "TIDAK";
//         Word ansno = stringToWord(no);

//         Word input;
//         boolean valid = wordInput(&input, 1, N_MAX);

//         printf("\n");
//         if(isWordEqual(input, ansyes)){
//             printf("Scoreboard berhasil di-reset.\n");
//         }else if(isWordEqual(input, ansno)){
//             printf("Scoreboard tidak di-reset.\n");
//         }
//     }else if(valid && inputan==4){
//         printf("APAKAH KAMU INGIN MELAKUKAN RESET SCOREBOARD TOWER OF HANOI (YA/TIDAK)? ");
//         char yes[] = "YA";
//         Word ansyes = stringToWord(yes);
//         char no[] = "TIDAK";
//         Word ansno = stringToWord(no);

//         Word input;
//         boolean valid = wordInput(&input, 1, N_MAX);

//         printf("\n");
//         if(isWordEqual(input, ansyes)){
//             printf("Scoreboard berhasil di-reset.\n");
//         }else if(isWordEqual(input, ansno)){
//             printf("Scoreboard tidak di-reset.\n");
//         }
//     }else if(valid && inputan==5){
//         printf("APAKAH KAMU INGIN MELAKUKAN RESET SCOREBOARD SNAKE ON METEOR (YA/TIDAK)? ");
//         char yes[] = "YA";
//         Word ansyes = stringToWord(yes);
//         char no[] = "TIDAK";
//         Word ansno = stringToWord(no);

//         Word input;
//         boolean valid = wordInput(&input, 1, N_MAX);

//         printf("\n");
//         if(isWordEqual(input, ansyes)){
//             printf("Scoreboard berhasil di-reset.\n");
//         }else if(isWordEqual(input, ansno)){
//             printf("Scoreboard tidak di-reset.\n");
//         }
//     }else{
//         printf("Masukkan tidak valid\n");
//     }
    
// }

// int main(){
//     // Map MapHangman;
//     // CreateEmptyMap(&MapHangman);
//     // keytype test, test1;
//     // test = stringToWord("hai");
//     // test1 = stringToWord("halo");
//     // valuetype testInfo, test1Info;
//     // testInfo = 10;
//     // test1Info = 20;
//     // InsertMap(&MapHangman, test, testInfo);
//     // InsertMap(&MapHangman, test1, test1Info);
//     Map r;
//     CreateEmptyMap(&r);
//     rng(&r);
//     printf("**** SCOREBOARD GAME RNG ****\n");
//     printf("| NAMA        | SKOR        |\n");
//     displayscoreboard(r);
//     printf("\n");
//     // resetscoreboard(MapHangman);
// }

// //compile (ketik cd src dulu) : gcc Utility/scoreboard/scoreboard.c ADT/map/map.c ADT/word/word.c ADT/word/mesinkata/mesinkata.c Misc/io/io.c ADT/word/mesinkarakter/mesinkarakter.c Misc/ascii/ascii.c ADT/list/array.c -o try

#include <stdio.h>
#include "scoreboard.h"

void addMap(ListMap *M){
    Map mapRNG, mapDiner, mapHangman, mapTower, mapSnake, mapBattle;
    CreateEmptyMap(&mapRNG);
    CreateEmptyMap(&mapDiner);
    CreateEmptyMap(&mapHangman);
    CreateEmptyMap(&mapTower);
    CreateEmptyMap(&mapSnake);
    CreateEmptyMap(&mapBattle);

    insertListMap(M, mapRNG);
    insertListMap(M, mapDiner);
    insertListMap(M, mapHangman);
    insertListMap(M, mapTower);
    insertListMap(M, mapSnake);
    insertListMap(M, mapBattle);
}

void addSet(ListSet *S){
    Set setRNG, setDiner, setHangman, setTower, setSnake, setBattle;
    CreateEmptySet(&setRNG);
    CreateEmptySet(&setDiner);
    CreateEmptySet(&setHangman);
    CreateEmptySet(&setTower);
    CreateEmptySet(&setSnake);
    CreateEmptySet(&setBattle);

    insertListSet(S, setRNG);
    insertListSet(S, setDiner);
    insertListSet(S, setHangman);
    insertListSet(S, setTower);
    insertListSet(S, setSnake);
    insertListSet(S, setBattle);
}

void scoreboard(ListMap M, List L){
    displayListMap(M, L);
}