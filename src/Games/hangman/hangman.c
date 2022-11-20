#include <stdio.h>
#include "hangman.h"
static FILE *saveFileKata;

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

void readListKata(List *ListKata){
    Word file;
    concateWord(stringToWord("src/Games/hangman/"), stringToWord("listKata.txt"), &file);

    char a[wordLength(file) + 1];
    wordToString(file, a);

    startKata(true, a);

    while (!endKata) {
        insertLast(ListKata, currentKata);
        advKata();
    }
}

void addToListKata(List *L){
    boolean repeat = true;
    Word kata;
    while (repeat){
        printf("Masukkan kata yang ingin Anda tambahkan ke dictionary kata: ");
        boolean valid = wordInput(&kata, 1, 50);
        if (valid){
            if (isMemberList(*L, kata)) {
                printf("Kata sudah ada di dalam dictionary kata!\n");
            } else {
                if (kata.buffer[0] >= 'a' && kata.buffer[0] <= 'z') {
                    kata.buffer[0] -= 32;
                }
                insertLast(L, kata);
                printf("Kata berhasil ditambahkan ke dalam dictionary kata!\n");
                // tanyain mau nambahin lg ga
                // kalau iya, repeat = true
                // tambahin kemungkinan bukan huruf?
            }
        } else {
            if (wordLength(kata) == 0) {
                printf("Kata tidak boleh kosong!\n");
                printf("\n");
            } else {
                printf("Kata melebihi batas karakter!\n");
                printf("Kata hanya boleh 1-50 huruf!\n");
                printf("\n");
            }
        }
    }
}

void saveListKata(List L){
    Word file;
    concateWord(stringToWord("src/Games/hangman/"), stringToWord("listKata.txt"), &file);

    char a[wordLength(file) + 1];
    wordToString(file, a);

    saveFileKata = fopen(a, "w");
    int i, j;
    for (i=0; i<length(L); i++){
        for (j=0; j<L.A[i].length; j++){
            fprintf(saveFileKata, "%c", L.A[i].buffer[j]);
        }
        if (i < length(L)-1) {
            fprintf(saveFileKata, "\n");
        }
    }

    fclose(saveFileKata);
}

void playHangman(List L)
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

void hangman()
{
    printf("Selamat datang di permainan Hangman!\n");
    printf("Silakan pilih mode permainan:\n");
    printf("1. Bermain Hangman\n");
    printf("2. Menambah kata ke dictionary kata untuk permainan Hangman\n");
    printf("Silahkan masukkan pilihan Anda: ");

    // baca list kata dari listKata.txt
    List L;
    createList(&L);
    readListKata(&L);

    Word input;
    boolean repeat = true;
    while (repeat){
        boolean valid = wordInput(&input,1,1);
        if (valid){
            if (input.buffer[0] == '1'){
                playHangman(L);
                // tambahin opsi main lagi?
                repeat = false;
            } else if (input.buffer[0] == '2'){
                addKata(L);
                // tambahin mau main game lagi atau selesai
                // kalo iya, repeat = true + playHangman(L)
                repeat = false;
            } else {
                printf("Masukan pilihan Anda salah!\n");
                printf("Masukkan 1 atau 2!\n\n");
                printf("Silakan masukkan pilihan Anda kembali: ");
            }
        } else {
            printf("Masukan pilihan Anda salah!\n");
            printf("Masukkan 1 atau 2!\n\n");
            printf("Silakan masukkan pilihan Anda kembali: ");
        }
    }

    saveListKata(L);
}

int main()
{
    hangman();
    return 0;
}


// compile : gcc src/Games/hangman/hangman.c src/ADT/list/array.c src/ADT/word/mesinkata/mesinkata.c src/ADT/word/mesinkarakter/mesinkarakter.c src/ADT/word/word.c src/Misc/ascii/ascii.c src/Misc/io/io.c -o driver
