#include <stdio.h>
#include "hangman.h"

void inputGuess(List Guesses, Word *guess) {
    boolean repeat = true;
    while (repeat){
        printf("Masukkan tebakan Anda: ");
        boolean valid = wordInput(guess,1,1);
        if (valid) {
            if (isMemberList(Guesses, *guess)) {
                printf("Anda sudah pernah menebak huruf %c\n", (*guess).buffer[0]);
                printf("Silakan masukkan huruf lain\n");
            } else {
                if ((*guess).buffer[0] >= 'a' && (*guess).buffer[0] <= 'z') {
                    (*guess).buffer[0] -= 32;
                }
                repeat = false;
            }
        } else {
            if (wordLength(*guess) == 0) {
                printf("Tebakan tidak boleh kosong!\n");
                printf("\n");
            } else {
                printf("Tebakan melebihi batas karakter!\n");
                printf("Tebakan hanya boleh 1 huruf!\n");
                printf("\n");
            }
        }
    }
}

void displayKata(List L){
    int i;
    for (i=0; i<length(L); i++){
        printf("%c", getElmt(L,i).buffer[0]);
    }
    printf("\n");
}

void hangman(List L)
{
    int chance = 10;
    Word guess;
    Word test = stringToWord("HAI");
    int i;

    List Word, kata, Guesses;
    createList(&Word);
    createList(&kata);
    createList(&Guesses);

    boolean cek;
    int valid;
    int score = 0;
    while (chance != 0){
        for (i=0; i<wordLength(test); i++){
            insertLast(&Word, charToWord(test.buffer[i]));
        }

        for (i=0; i<length(Word); i++){
            insertLast(&kata, stringToWord("_"));
        }

        valid = 0;
        while (valid != length(Word) && chance != 0){
            if (isEmpty(Guesses)){
                printf("\nTebakan sebelumnya:-\n");
            } else {
                printf("\nTebakan sebelumnya: ");
                displayKata(Guesses);
            }
            printf("Kata: ");
            displayKata(kata);
            printf("Sisa kesempatan: %d\n", chance);
            inputGuess(Guesses, &guess);
            insertLast(&Guesses, guess);

            cek = false;
            for (i=0; i<length(Word); i++){
                if (isWordEqual(guess, getElmt(Word,i))){
                    setElmt(&kata, i, guess);
                    cek = true;
                    valid++;
                }
            }

            if (cek){
                printf("Selamat, Tebakan Anda benar!\n");
            } else {
                printf("Tebakan Anda salah!\n");
                printf("Kesempatan Anda berkurang!\n");
                chance--;
            }
        }

        if (valid == length(Word)){
            printf("Selamat, Anda berhasil menebak kata!\n");
            printf("Skor Anda bertambah %d poin!\n", valid);
            score += valid;
            printf("Skor Anda: %d\n", score);
            printf("Silahkan lanjut ke kata selanjutnya!\n");
        }

        // kosonging semua list
        if (chance != 0){
            while (!isEmpty(Word)){
                deleteFirst(&Word);
            }
            while (!isEmpty(kata)){
                deleteFirst(&kata);
            }
            while (!isEmpty(Guesses)){
                deleteFirst(&Guesses);
            }
        }

        // benerin newline

        // tambahin list kata (di random keluar kata apa (?))
        // kata bakal ada spasi nggak?
        // bonus blm
        printf("\n");
    }

    if (chance == 0){
        printf("Anda kalah!\n");
        printf("Kata yang harus ditebak: ");
        displayKata(Word);
        printf("Skor Anda: %d\n", score);
    } else {
        printf("Anda menang!\n");
        printf("Skor Anda: %d\n", score);
    }
}


int main()
{
    List L;
    createList(&L);
    hangman(L);
    return 0;
}


// compile : gcc Games/hangman/hangman.c ADT/list/array.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/ascii/ascii.c Misc/io/io.c -o driver
