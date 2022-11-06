#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"../mesinkata/mesinkata.h"
#include"../mesinkar/mesinkar.h"
#include"../array/arrayGame.h"

void MakeEmpty (ArrayGame *T){
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
	(*T).Neff = 0;
}

/* *** Test tabel kosong *** */
boolean IsEmpty (ArrayGame T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
	return (T.Neff == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull (ArrayGame T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
	return (T.Neff == IdxMax);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (ArrayGame T){
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
	int i;
	if(IsEmpty(T)){
		printf("Tidak ada game dalam antrian game-mu\n");
	}else{
		printf("Berikut adalah daftar antrian game-mu\n");
		for(i=IdxMin; i<T.Neff; i++){
			printf("%d %s\n", i, T.Elmt[i]);
		}
	}
}

void copyString(char arr1[], char arr2[]){
	for(int i=0; arr2[i]!='\0'; i++){
		arr1[i] = arr2[i];
	}
	arr1[i] = '\0';
}

void insertArrayGame (ArrayGame *T, char game[]){
	if(!IsFull(*T)){
		copyString(T.Elmt[*T.Neff], game);
		*T.Neff++; 
	}
} 

int compareString(char arr1[], char arr2[]){
	int same = true;
	for(int i=0; arr1[i]!='\0' && arr2[i]!='\0' && same; i++){
		if (arr1[i]!=arr2[i])
			same = false;
	}
	if (arr1[i]=='\0' && arr2[i]=='\0')
		return same;
	else
		return false;
} 

void addToQueueGame(ArrayGame *QGame, char game[]){ // bintang
	int found = false;
	for(int i=0; i<*QGame.Neff && !found; i++){
		if (compareString(*QGame.Elmt[i], game)) // game berada di queue
			found = true;	
	}
	if (!found){
		insertArrayGame(QGame, game);
		printf("Game berhasil ditambahkan kedalam daftar antrian.\n");
	}
}