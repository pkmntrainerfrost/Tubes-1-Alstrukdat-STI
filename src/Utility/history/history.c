#include <stdio.h>
#include "history.h"

void resetHist(List *listHist){
    Word yn;
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY?[YA/TIDAK]\n");
    boolean yesno = wordInput(&yn, 2, 5);
    boolean yes = isSameWord(yn, stringToWord("YA"));
    boolean no = isSameWord(yn, stringToWord("TIDAK"));
    while (!yes && !no){
        printf("Masukan salah! Ulangi input!\n");
        yesno = wordInput(&yn, 2, 5);
    }
    if (yes){
        deallocateList(listHist);
        printf("History berhasil di-reset.\n");            
    }else if (no){
        printf("History tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan\n");
        history(*listHist, length(*listHist));
    }
}

void history(List listHist, int num){
    int i;
    printf("Berikut adalah daftar Game yang telah dimainkan\n");
    if (length(listHist) > 0){
        if (num < length(listHist)){
            for (i = 0; i < num; i++){
                printf("%d. ", i+1);
                int j;
                for(j=0; j<listHist.A[i].length; j++){
                    printf("%c", listHist.A[i].buffer[j]);
                }
                printf("\n");
            }
        }else{
            for (i = 0; i < length(listHist); i++){
                printf("%d. ", i+1);
                int j;
                for(j=0; j<listHist.A[i].length; j++){
                    printf("%c", listHist.A[i].buffer[j]);
                }
                printf("\n");
            }        
        }     
    }else{
        printf("History kosong.\n");
    }
}

// int main()
// {
//     List List;
//     createList(&List);
//     insertLast(&List, stringToWord("RNG"));
//     insertLast(&List, stringToWord("Diner DASH"));
//     insertLast(&List, stringToWord("DINOSAUR IN EARTH"));
//     insertLast(&List, stringToWord("RISEWOMAN"));
//     insertLast(&List, stringToWord("EIFFEL TOWER"));
//     insertLast(&List, stringToWord("Battleship")); 
//     insertLast(&List, stringToWord("Tetris"));
//     int num;
//     history(List, num);
//     displayList(List);
// }

// src % gcc ADT/list/array.c ADT/word/word.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c Misc/io/io.c Misc/ascii/ascii.c ADT/queue/queue2.h Utility/history/history.c -o driver