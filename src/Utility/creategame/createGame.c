#include <stdio.h>
#include "createGame.h"

void createGame(List *L) {

    boolean repeat = true;

    while (repeat) {

        header();

        printf("Masukkan nama game yang akan ditambahkan: ");

        Word name;
        boolean valid = wordInput(&name,1,N_MAX);

        if (valid) {
            boolean unique = true;
            int i = 0;
            while (i < length(*L) && unique) {
                if (isWordEqual(getElmt(*L,i),name)) {
                    unique = false;
                }
                i = i + 1;
            }
            if (!unique) {
                printf("Nama game sudah ada dalam daftar game!\n");
            } else {
                insertLast(L,name);
                printf("Game berhasil ditambahkan.\n");
            }
        } else {
            if (wordLength(name) == 0) {
                printf("Nama game tidak boleh kosong!\n");
            } else {
                printf("Nama game melebihi batas karakter!\n");
            }
        }

        printf("\nApakah Anda ingin kembali melakukan input? [Y/N]: ");

        valid = wordInput(&name,1,1);
        
        if (valid && (isWordEqual(name,stringToWord("Y")) || isWordEqual(name,stringToWord("y")))) {
            repeat = true;
        } else {
            repeat = false;
        }

    }


    /*
    printf("Masukkan nama game yang akan ditambahkan: ");
    List input;
    createList(&input);
    boolean valid = multiWordInput(&input,1,10);
    displayList(input);
    Word temp;
    createWord(&temp);
    int i;
    for(i=0; i<wordLength(input.A[0]); i++){
        temp.buffer[i] = input.A[0].buffer[i];
    }
    deleteFirst(&input);
    printWord(temp);
    while (length(input) > 0) {
        printf(" ");
        copyWord(getElmt(input,0), &temp);
        for (i=0; i<wordLength(input.A[0]); i++){
            temp.buffer[wordLength(temp)+i] = input.A[0].buffer[i];
        }
        printWord(temp);
        deleteFirst(&input);
    }
    printWord(temp);
    */
    // ???????
    // Word GameName;
    // createWord(&GameName);

    // int i = 0;
    // startInput();

    // while (!eoi) {
    //     if (i < N_MAX) {
    //         GameName.buffer[i] = cc;
    //         i++;
    //     }
    //     advInput();
    // }

    // GameName.length = i;
    // insertLast(L, GameName);
}


// compile: gcc utility/createGame.c utility/listGame/listGame.c ADT/list/array.c ADT/queue/queue2.c ADT/word/mesinkata/mesinkata.c ADT/word/mesinkarakter/mesinkarakter.c ADT/word/word.c Misc/io/io.c Misc/ascii/ascii.c -o driver 