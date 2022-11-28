#include <stdio.h>
#include <stdlib.h>
#include "towerOfHanoi.h"

int step = 0;

// Inisialisasi Tower
void initAllTower(int h, Tower *A, Tower *B, Tower *C){
    Stack stackA, stackB, stackC;
    CreateEmptyStack(&stackA);
    CreateEmptyStack(&stackB);
    CreateEmptyStack(&stackC);
    (*A).name = 'A';
    (*A).height = h;
    (*A).countDisc = 0;
    (*A).content = stackA;
    (*B).name = 'B';    
    (*B).height = h;
    (*B).countDisc = 0;
    (*B).content = stackB;
    (*C).name = 'C';
    (*C).height = h;
    (*C).countDisc = 0;
    (*C).content = stackC;

    // fill in stack depends on h to tower A
    int i;
    for (i = h; i > 0 ; i--){
        Push(&(*A).content, i);
        (*A).countDisc++;
    };
};

void printAllTower(Tower A, Tower B, Tower C)
{
    printf("Tower A\n");
    printTower(A);
    printf("Tower B\n");    
    printTower(B);
    printf("Tower C\n");
    printTower(C);
    printf("\n========================\n");
}

void printTower(Tower T){
    int h, count, top, i, j, s, disc;
    Stack temp;
    CreateEmptyStack(&temp);
    h = T.height;
    count = T.countDisc;
    top = InfoTop(T.content);
    temp = CopyStack(T.content);

    // print for empty level
    for (i = 0; i < h - count; i++){
        for (j = 0; j < h; j++){
   printf(" ");  
  }
        printf("|\n");
    }

    // print for the rest of tower
    if (top != 0) {
        for (i = 0; i < count; i++)
        {
            // get current disc from temp stack
            Pop(&temp, &disc);
            for (j = 0; j < h - disc;j++){
                printf(" ");  
            }
            for (s = 0; s < disc;s++){
                printf("*");
            }
            printf("|");
            for (s = 0; s < disc;s++){
                printf("*");
            }
            printf("\n");
        }
    }

 for (i=0; i<=2*h; i++){
  printf("-");
 }
 printf("\n");
};


void moveDisc(Tower *A, Tower *B)
{

    if (IsEmptyStack((*A).content)){
        printf("Tower kosong, tidak ada yang bisa dipindahkan!\n");
        
        printf("\nTekan [ENTER] untuk melanjutkan...");
        blankInput();
        return;
    }

    if (IsEmptyStack((*B).content)) {
        int popped;
        Pop(&((*A).content), &popped);
        (*A).countDisc--;
        Push(&((*B).content), popped);
        (*B).countDisc++;

        printf("Memindahkan piringan dari tower %c ke tower %c\n", (*A).name, (*B).name);
        printf("\nTekan [ENTER] untuk melanjutkan...");
        blankInput();

    } else {
        if (InfoTop((*A).content) > InfoTop((*B).content)){
            printf("Piringan dari tower %c ke tower %c tidak dapat dipindahkan\n", (*A).name, (*B).name);

            printf("\nTekan [ENTER] untuk melanjutkan...");
            blankInput();
            return;
        } else {
            int popped;
            Pop(&((*A).content), &popped);
            (*A).countDisc--;
            Push(&((*B).content), popped);
            (*B).countDisc++;

            printf("Memindahkan piringan dari tower %c ke tower %c\n", (*A).name, (*B).name);
            printf("\nTekan [ENTER] untuk melanjutkan...");
            blankInput();
        }
    }
}

void towerOfHanoi(ListMap *M, ListSet *S){
    header();

    Tower A, B, C;
    Word many;
    int height;
    int moves = 0;
    boolean play = true;

    printf("Halo! Selamat datang di Tower of Hanoi!\n");    
    printf("Mau main dengan berapa piringan?: ");
	wordInput(&many, 1, 2);
    int intMany = wordToInt(many);

	while (intMany < 1) {
		printf("Pilih angka lebih baik...\n");
        printf("\nTekan [ENTER] untuk melanjutkan...");
        blankInput();

        header();
		printf("Mau main dengan berapa piringan?: ");
        wordInput(&many, 1, 2);
        wordToInt(many);
        intMany = wordToInt(many);
	}

    header();
    height = intMany;
    initAllTower(height, &A, &B, &C);
    printAllTower(A, B, C);
    
    while (play){
        Word wordFirst;
        boolean valid = false;
        printf("Pilih tower asal: ");
        wordInput(&wordFirst, 1, 1);
        char first = wordToChar(wordFirst);
        while (!valid){
            if(first == 'A' || first == 'B' || first == 'C' || first == 'a' || first == 'b' || first == 'c'){
                valid = true;
            }else{
                printf("Tidak ada tower %c di game ini\n", first);
                printf("\nTekan [ENTER] untuk melanjutkan...");
                blankInput();

                header();
                printAllTower(A, B, C);
                printf("Pilih tower asal: ");
                wordInput(&wordFirst, 1, 1);
                first = wordToChar(wordFirst);            
            }            
        }

        Word wordDest;
        valid = false;
        printf("Pilih tower tujuan: ");
        wordInput(&wordDest, 1, 1);
        char dest = wordToChar(wordDest);
        while (!valid){
            if(dest == 'A' || dest == 'B' || dest == 'C' || dest == 'a' || dest == 'b' || dest == 'c'){
                valid = true;
            }else{
                printf("Tidak ada tower %c di game ini\n", dest);
                printf("Choose the destination tower: ");
                wordInput(&wordDest, 1, 1);
                dest = wordToChar(wordDest);              
            }            
        }

        if (first == dest){
            printf("Tidak bisa memindahkan ke tower yang sama! Pilih tower lain\n");
            printf("\nTekan [ENTER] untuk melanjutkan...");
            blankInput();

        }else{
            if (first == 'A' || first == 'a'){
                if (dest == 'B' || dest == 'b'){
                    moveDisc(&A, &B);
                }
                else if(dest == 'C' || dest == 'c'){
                    moveDisc(&A, &C);
                }
            }
            else if (first == 'B' || first == 'b'){
                if(dest == 'A' || dest == 'a'){
                    moveDisc(&B, &A);
                }
                else if(dest == 'C' || dest == 'c'){
                    moveDisc(&B, &C);
                }
            }
            else //shud be from tower C
                if(dest == 'A' || dest == 'a'){
                    moveDisc(&C, &A);
                }
                else if(dest == 'B' || dest == 'b'){
                    moveDisc(&C, &B);
                }

            moves += 1;
        }

        header();
        printAllTower(A, B, C);

        if (C.countDisc == height) {
            play = false;
        }
    }

    header();
    float min_moves = pow(2, height) - 1;
    int score = (min_moves/moves*100);
    printf("Selamat telah menyelesaikan Tower of Hanoi!\n");
    printf("Skor kamu: %d\n", score);
    inputDataListMap(M, S, 3, score);
}

// compile:
// ganti dulu nama function tower of hanoi jadi main kalo mau coba 
// gcc src/Games/towerofhanoi/towerOfHanoi.c src/ADT/stack/stack.c src/Utility/splash.c src/Games/random.c src/ADT/word/mesinkata/mesinkata.c src/ADT/word/mesinkarakter/mesinkarakter.c src/ADT/word/word.c src/ADT/list/array.c src/Misc/ascii/ascii.c src/Misc/io/io.c -o driver