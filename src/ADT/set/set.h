#ifndef set_H
#define set_H
#include <stdio.h>
#include "../boolean.h"
#include "../word/mesinkata/mesinkata.h"

/* MODUL Set
Deklarasi set yang dengan implementasi array eksplisit-statik rata kiri
*/

#define Nil 0
#define InitialSizeSet 10

#define infotypeSet Word

typedef int address;

typedef struct
{
    infotypeSet *Elementset;
    address Countset;
    int CapacitySet;
} Set;

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

void deallocateSet(Set *S);

void updateCapacitySet(Set *S);

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S);
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullSet(Set S);
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
boolean InsertSet(Set *S, infotypeSet Elmt);
/* Menambahkan Elmt sebagai elemen Set S jika elmt tidak ada di S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S dan true. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan dan false */

void DeleteSet(Set *S, infotypeSet Elmt);
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSet(Set S, infotypeSet Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

void PrintSet(Set S);
/*menampilkan semua set yang ada*/

#endif