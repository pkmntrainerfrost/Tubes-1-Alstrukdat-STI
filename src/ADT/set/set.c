#include <stdio.h>
#include <stdlib.h>
#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : Countset bernilai Nil */
{
    (*S).Elementset = (infotypeSet *) malloc(InitialSizeSet * sizeof(infotypeSet));
    (*S).CapacitySet = InitialSizeSet;
    (*S).Countset = Nil;
}

void deallocateSet(Set *S)
{
    free((*S).Elementset);
    (*S).CapacitySet = 0;
    (*S).Countset = Nil;
}

void updateCapacitySet(Set *S)
{
    int newCapacity = 2 * InitialSizeSet;
    infotypeSet *newBuffer = (infotypeSet *) malloc(newCapacity * sizeof(infotypeSet));
    int i;
    for (i = 0; i < (*S).Countset; i++){
        newBuffer[i] = (*S).Elementset[i];
    }
    free((*S).Elementset);
    (*S).Elementset = newBuffer;
    (*S).CapacitySet = newCapacity;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : Countset bernilai Nil */
{
    return(S.Countset == Nil);
}

boolean IsFullSet(Set S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : Countset bernilai MaxEl */
{
    return(S.Countset == S.CapacitySet);
}

/* ********** Operator Dasar Set ********* */
boolean InsertSet(Set *S, infotypeSet Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if(IsFullSet(*S)){
        updateCapacitySet(S);
    }

    if(!IsMemberSet(*S, Elmt)){
        S->Elementset[S->Countset]=Elmt;
        S->Countset++;
        return true;
    } else {
        return false;
    }
}

void DeleteSet(Set *S, infotypeSet Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    if (IsMemberSet(*S,Elmt)){
        boolean found = false;
        int i = 0;
        while (i < (*S).Countset && (!found)){
            if (isWordEqual((*S).Elementset[i], Elmt)){
                found = true;
            } else {
                i++;
            }
        }

        int j;
        for (j=i; j<(*S).Countset-1; j++){
            (*S).Elementset[j]= (*S).Elementset[j+1];
        }
        (*S).Countset--;
    }
}

boolean IsMemberSet(Set S, infotypeSet Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    boolean found = false;
    int i = 0;
    while (i < S.Countset && (!found)){
        if (isWordEqual(S.Elementset[i], Elmt)){
            found = true;
        } else {
            i++;
        }
    }
    return found;
}

void PrintSet(Set S)
{
    if (IsEmptySet(S)){
        printf("Map kosong\n");
    } else {
        int i;
        printf("[");
        for (i=0; i<S.Countset; i++){
            int j;
            for (j=0; j<S.Elementset[i].length; j++){
                printf("%c", S.Elementset[i].buffer[j]);
            }

            if (i+1 != S.Countset){
                printf(", ");
            }
        }
        printf("]\n");
        
    }
        
}
