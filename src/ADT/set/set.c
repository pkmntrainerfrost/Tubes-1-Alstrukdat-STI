#include<stdio.h>
#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : Countset bernilai Nil */
{
    S->Countset=Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : Countset bernilai Nil */
{
    return(S.Countset==Nil);
}

boolean IsFull(Set S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : Countset bernilai MaxEl */
{
    return(S.Countset==MaxEl);
}

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if (!(IsMember(*S, Elmt))){
        (*S).Countset++;
        (*S).Elementset[(*S).Countset-1]=Elmt;
    }
}

void Delete(Set *S, infotype Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    if (IsMember(*S,Elmt)){
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

boolean IsMember(Set S, infotype Elmt)
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
    if (IsEmpty(S)){
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
