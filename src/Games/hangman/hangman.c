#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hangman.h"
static FILE *saveFileKata;

void inputGuess(List Guesses, Word *guess) {
    boolean repeat = true;
    while (repeat){
        printf("Masukkan tebakan Anda: ");
        boolean valid = wordInput(guess,1,1);
        if (valid) {
            if ((*guess).buffer[0] >= 'a' && (*guess).buffer[0] <= 'z') {
                (*guess).buffer[0] -= 32;
            }

            if (isMemberList(Guesses, *guess)) {
                printf("Anda sudah pernah menebak huruf %c\n", (*guess).buffer[0]);
                printf("Silakan masukkan huruf lain\n");
            } else {
                repeat = false;
            }
        } else {
            if (wordLength(*guess) == 0) {
                printf("Tebakan tidak boleh kosong!\n");
                printf("\n");
            } else {
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

Word randomWord(List L){
    Word randomword;
    boolean valid = true;
    int Num;
    while(valid){
        srand(time(NULL));
        Num = random_range(0, length(L)-1);
        if (Num>=0 && Num<length(L)){
            valid = false;
        }
    }
    randomword = getElmt(L, Num);
    
    return randomword;
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
                // kata yang ada spasinya tidak valid
                int i=0;
                boolean cek = true;
                while (i<wordLength(kata)){
                    if (kata.buffer[i] == ' '){
                        cek = false;
                    }
                    i++;
                }

                if (cek){
                    // all uppercase
                    int k;
                    for(k=0; k<kata.length; k++){
                        if (kata.buffer[k] >= 'a' && kata.buffer[k] <= 'z'){
                            kata.buffer[k] -= 32;
                        }
                    }

                    insertLast(L, kata);
                    printf("Kata berhasil ditambahkan ke dictionary kata!\n");
                    Word yesnoinput;
                    boolean loop = true;
                    while (loop){
                        printf("Apakah Anda ingin menambahkan kata lain? (Y/N)\n");
                        printf("Silahkan masukkan pilihan Anda: ");
                        boolean ans = wordInput(&yesnoinput, 1, 1);
                        if (ans){
                            if (yesnoinput.buffer[0] == 'Y' || yesnoinput.buffer[0] == 'y'){
                                loop = false;
                                repeat = true;
                            } else if (yesnoinput.buffer[0] == 'N' || yesnoinput.buffer[0] == 'n'){
                                loop = false;
                                repeat = false;
                            } else {
                                printf("Input tidak valid!\n");
                                printf("Masukkan Y/N!\n\n");
                            }
                        } else {
                            printf("Input tidak valid!\n");
                            printf("Masukkan Y/N!\n\n");
                        }
                    }
                } else {
                    printf("Kata tidak boleh mengandung spasi!\n\n");
                }
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
    Word randWord;
    int i;

    List GuessWord, kata, Guesses;
    createList(&GuessWord);
    createList(&kata);
    createList(&Guesses);

    boolean cek;
    int valid;
    int score = 0;
    while (chance != 0){
        randWord = randomWord(L);
        for (i=0; i<wordLength(randWord); i++){
            insertLast(&GuessWord, charToWord(randWord.buffer[i]));
        }

        for (i=0; i<length(GuessWord); i++){
            insertLast(&kata, stringToWord("_"));
        }

        valid = 0;
        while (valid != length(GuessWord) && chance != 0){
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
            for (i=0; i<length(GuessWord); i++){
                if (isWordEqual(guess, getElmt(GuessWord,i))){
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

        if (valid == length(GuessWord)){
            printf("Selamat, Anda berhasil menebak kata!\n");
            printf("Kata yang harus ditebak: ");
            displayKata(GuessWord);
            printf("\nSkor Anda bertambah %d poin!\n", valid);
            score += valid;
            printf("Skor Anda: %d\n", score);
            printf("Silahkan lanjut ke kata selanjutnya!\n");
        }

        // kosonging semua list
        if (chance != 0){
            while (!isEmpty(GuessWord)){
                deleteFirst(&GuessWord);
            }
            while (!isEmpty(kata)){
                deleteFirst(&kata);
            }
            while (!isEmpty(Guesses)){
                deleteFirst(&Guesses);
            }
        }

        // benerin newline
        printf("\n");
    }

    if (chance == 0){
        printf("Anda kalah!\n");
        printf("Kata yang harus ditebak: ");
        displayKata(GuessWord);
        printf("Skor Anda: %d\n", score);
    } else {
        printf("Anda menang!\n");
        printf("Skor Anda: %d\n", score);
    }

    boolean loop = true;
    Word yesnoinput;
    while (loop){
        printf("Apakah Anda ingin bermain lagi? (Y/N)\n");
        printf("Silahkan masukkan pilihan Anda: ");
        boolean ans = wordInput(&yesnoinput, 1, 1);
        if (ans){
            if (yesnoinput.buffer[0] == 'Y' || yesnoinput.buffer[0] == 'y'){
                playHangman(L);
                loop = false;
            } else if (yesnoinput.buffer[0] == 'N' || yesnoinput.buffer[0] == 'n'){
                printf("Terima kasih telah bermain!\n");
                loop = false;
            } else {
                printf("Input tidak valid!\n");
                printf("Masukkan Y/N!\n\n");
            }
        } else {
            printf("Input tidak valid!\n");
            printf("Masukkan Y/N!\n\n");
        }
    }
}

void hangman()
{
    header();
    // tambahin header di semua e
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
                repeat = false;
            } else if (input.buffer[0] == '2'){
                addToListKata(&L);
                printf("Apakah Anda ingin bermain Hangman? (Y/N)\n");
                printf("Silahkan masukkan pilihan Anda: ");
                Word yesnoinput;
                boolean loop = true;
                while (loop){
                    printf("Apakah Anda ingin bermain Hangman? (Y/N)\n");
                    printf("Silahkan masukkan pilihan Anda: ");
                    boolean ans = wordInput(&yesnoinput, 1, 1);
                    if (ans){
                        if (yesnoinput.buffer[0] == 'Y' || yesnoinput.buffer[0] == 'y'){
                            playHangman(L);
                            loop = false;
                        } else if (yesnoinput.buffer[0] == 'N' || yesnoinput.buffer[0] == 'n'){
                            printf("Terima kasih telah bermain!\n");
                            loop = false;
                        } else {
                            printf("Input tidak valid!\n");
                            printf("Masukkan Y/N!\n\n");
                        }
                    } else {
                        printf("Input tidak valid!\n");
                        printf("Masukkan Y/N!\n\n");
                    }
                }
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
    // List L;
    // createList(&L);
    // readListKata(&L);
    // addToListKata(&L);
    // saveListKata(L);
    hangman();
    return 0;
}


// compile : gcc src/Utility/splash.c src/Games/random.c src/Games/hangman/hangman.c src/ADT/list/array.c src/ADT/word/mesinkata/mesinkata.c src/ADT/word/mesinkarakter/mesinkarakter.c src/ADT/word/word.c src/Misc/ascii/ascii.c src/Misc/io/io.c -o driver