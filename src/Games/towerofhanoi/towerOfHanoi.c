#include<stdio.h>
#include<stdlib.h>
#include"towerOfHanoi.h"

int step = 0;

void printStack(Stack A, Stack B, Stack C){
	int idxA = 0, idxB = 0, idxC = 0;

	do{
		if(IsEmpty(A)){
			printf("|");
		}else{
			if(idxA == Top(A)){
				switch(Info(A, idxA)){
					case 1:
						printf("*");
						break;
					case 3:
						printf("***");
						break;
					case 5:
						printf("*****");
						break;
					case 7:
						printf("*******");
						break;
					case 9:
						printf("*********");
						break;
				}
			}else{
				printf("|");
			}
		}
		idxA++;

		if(IsEmpty(B)){
			printf("|");
		}else{
			if(idxB == Top(B)){
				switch(Info(B, idxB)){
					case 1:
						printf("*");
						break;
					case 3:
						printf("***");
						break;
					case 5:
						printf("*****");
						break;
					case 7:
						printf("*******");
						break;
					case 9:
						printf("*********");
						break;
				}
			}else{
				printf("|");
			}
		}
		idxB++;

		if(IsEmpty(C)){
			printf("|");
		}else{
			if(idxC == Top(C)){
				switch(Info(C, idxC)){
					case 1:
						printf("*");
						break;
					case 3:
						printf("***");
						break;
					case 5:
						printf("*****");
						break;
					case 7:
						printf("*******");
						break;
					case 9:
						printf("*********");
						break;
				}
			}else{
				printf("|");
			}
		}
		idxC++;
	}while(idxA < MaxEl);
}

void pindah(Stack *S1, Stack *S2, char cc){
	// cek TOP S1 dengan S2
	infotype x;
	if(InfoTop(*S1) < InfoTop(*S2)){
		Pop(S1, &x);
		Push(S2, x);
		printf("Memindahkan piringan ke %c...\n", cc);
		step++;
	}else{
		printf("Piringan tidak dapat dipindahkan.");
	}
}

boolean cekStack(Stack C){
	if(IsEmpty(C)){
		return 0;
	}else{
		if(Info(C, 0) == 1 && Info(C, 1) == 3 && Info(C, 2) == 5 && Info(C, 3) == 7 && Info(C, 4) == 9){
			return 1;
		}else{
			return 0;
		}
	}
}

boolean endGame(Stack C){
	infotype x;
	char nama[20];
	int result = cekStack(C);
	if(result){
		printf("Kamu berhasil!\n");
		if(step == 31){
			printf("Skor didapatkan: 10\n");
		}else{
			x = step/3; // hitung skor
			printf("Skor didapatkan: %d\n", x);
		}
		printf("Nama: ");	
		scanf("%s", nama);
	}
	return result;
}

void towerOfHanoi(){
	Stack A, B, C;
	int result = 0;
	char awal, tujuan;
	// CreateEmpty(&A);
	// CreateEmpty(&B);
	// CreateEmpty(&C);

	// Push(&A, 1);
	// Push(&A, 3);
	// Push(&A, 5);
	// Push(&B, 7);
	// Push(&C, 9);

	do{
		printf("TIANG ASAL: ");
		scanf("%c", &awal);
		printf("TIANG TUJUAN: ")
		scanf("%c", &tujuan);

		if((awal == 'A' || awal == 'a') && (tujuan == 'B' || tujuan == 'b')){
			pindah(&A, &B, tujuan);
		}else if((awal == 'A' || awal == 'a') && (tujuan == 'C' || tujuan == 'c')){
			pindah(&A, &C, tujuan);
		}else if((awal == 'B' || awal == 'b') && (tujuan == 'A' || tujuan == 'a')){
			pindah(&B, &A, tujuan);
		}else if((awal == 'B' || awal == 'b') && (tujuan == 'C' || tujuan == 'c')){
			pindah(&B, &C, tujuan);
		}else if((awal == 'C' || awal == 'c') && (tujuan == 'A' || tujuan == 'a')){
			pindah(&C, &A, tujuan);
		}else if((awal == 'C' || awal == 'c') && (tujuan == 'B' || tujuan == 'b')){
			pindah(&C, &B, tujuan);
		}else{
			printf("Tidak dapat memindahkan piringan ke tiang yang sama.\n");
		}
		result = endGame(C);
	}while(result == 0);

	printStack(A, B, C);
}

int main(){
	towerOfHanoi();
	return 0;
}