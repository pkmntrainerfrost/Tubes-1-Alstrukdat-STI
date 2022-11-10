#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"../mesinkata/mesinkata.h"
#include"../mesinkar/mesinkar.h"
#include"../array/arrayGame.h"

void queueGame(ArrayGame LGame, ArrayGame QGame){
	int nomor;
	TulisIsi(QGame);
	arrayDaftarGame(LGame);
	printf("Nomor Game yang mau ditambahkan ke antrian: ");
	scanf("%d", &nomor);
	if(nomor < LGame.Neff){
		addToQueueGame(&QGame, LGame.Elmt[nomor]);
	}else{
		printf("Nomor permainan tidak valid, silahhkan masukkan nomor game pada list.\n");
	}
}

void playGame(ArrayGame *QGame, ArrayGame *history){
	int found = false;
	for(int i=0; i<*QGame.Neff && !found; i++){
		if (compareString(*QGame.Elmt[i], "RNG")){ // game rng
			rng();
			found = true;
			*QGame.Elmt[i][0] = '\0';
			addToQueueGame(history, *QGame.Elmt[i]);
		}
		else if (compareString(*QGame.Elmt[i], "DINER DASH")){ // game diner dash
			dinerdash();
			found = true;
			*QGame.Elmt[i][0] = '\0';
			addToQueueGame(history, *QGame.Elmt[i]);
		}
		else{
			srand(time(NULL));
			int r = rand();
			printf("Score: %d\n", r);
			found = true;
			*QGame.Elmt[i][0] = '\0';
			addToQueueGame(history, *QGame.Elmt[i]);
		}
	}
	if (!found){
		printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
	}
}

void skipGame(ArrayGame *QGame, int skip, ArrayGame *history){
	int found = false;
	for(int i=skip; i<*QGame.Neff && !found; i++){
		if (compareString(*QGame.Elmt[i], "RNG")){ // game rng
			rng();
			found = true;
			*QGame.Elmt[i][0] = '\0';
			addToQueueGame(history, *QGame.Elmt[i]);
		}
		else if (compareString(*QGame.Elmt[i], "DINER DASH")){ // game diner dash
			dinerdash();
			found = true;
			*QGame.Elmt[i][0] = '\0';
			addToQueueGame(history, *QGame.Elmt[i]);
		}
		else{
			srand(time(NULL));   // Initialization, should only be called once.
			int r = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX.
			printf("Score: %d\n", r);
			found = true;
			*QGame.Elmt[i][0] = '\0';
			addToQueueGame(history, *QGame.Elmt[i]);
		}
	}
	if (!found){
		printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
	}
}