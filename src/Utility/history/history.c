#include <stdio.h>
#include "history.h"

void resetHist(List *listHist){
    Word yn;
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY?[YA/TIDAK]\n");
    boolean yesno = wordInput(&yn, 2, 5);
    if (yesno){
        boolean yes = isSameWord(yn, stringToWord("YES"));
        boolean no = isSameWord(yn, stringToWord("NO"));
        if (yes){
            deallocateList(listHist);
            printf("History berhasil di-reset.\n");            
        }else if (no){
            printf("History tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan\n");
            history(*listHist, length(*listHist));
        }
// tambahin kondisi kalau masukan tidak valid
    }
}

void history(List listHist, int num){
    int i;
    Word gameName = stringToWord("ambil dari save\n");
    // integrasi dengan save
    printf("Berikut adalah daftar Game yang telah dimainkan\n");
    if (length(listHist) > 0){
        if (num < length(listHist)){
            for (i = 0; i < num; i++){
                insertLast(&listHist, gameName);
            }
        }else{
            for (i = 0; i < num; i++){
                insertLast(&listHist, gameName);
            }        
        }
        displayList(listHist);        
    }else{
        printf("History kosong.\n");
    }

        

}