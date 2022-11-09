#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dinerdash.h"
#include "../Misc/io/io.h"
#include "../../boolean.h"

boolean isSame(char kata1[], char kata2[]){
// mengembalikan true jika str1 sama dengan str2
    boolean check = true;
    int i;

    if (stringLength(kata1) == stringLength(kata2)){
        for(i=0;i<stringLength(kata1);i++){
            if (kata1[i] != kata2[i]){
                check = false;
            }
        }
    }
    return check;    
}

void dinerDash(){

    char input[100];
    char cook[] = "COOK";
    char serve[] = "SERVE";
    int queue = 0;
    int served = 0;
    int saldo = 0;
    int i;
    printf("Welcome to diner dash!\n");

    PQElType order[20];

    srand(time(NULL));
    for (int i = 0; i < 6; i++){ //batas memasak 5 makanan dalam satu waktu
        order[i].foodId = i;
        order[i].cookTime = (rand() % 6) + 1;
        order[i].stayTime = ((rand() * 10) + 1 + rand() * 2) % 6;
        order[i].price = ((rand() % 3) + 1) * 10000 + rand() % 4 * 1000;
    }

    PrioQueue pq;
    createQueuePQ(&pq);
    for (i=0;i<3;i++){
        enqueuePQ(&pq, order[i]);        
    }

    printf("SALDO: %d\n", saldo);
    printOrders(pq);
    printCooking(pq);
    printServing(pq);

//INPUT COMMAND SEMENTARA PAKE SCANF, BELOM SELESAI//
    char command[6];
    char orderId[5];

    printf("Masukkan command:");
    scanf("%s %s", command, orderId);

//Cek inputan 

    printf("Command: %s\n", command);
    printf("orderId: %s\n", orderId);

/*
    printf("MASUKKAN COMMAND: %s %s\n", command, readyToServe);
    scanf("%s %s", command, readyToServe);
    printf("\n");
*/

    //  handle input command
    while (!(isSame(command, cook) || isSame(command, serve)))
    {
        printf("Masukkan command: ");
        scanf("%s %s", command, orderId);
    }

    while (!(isSame(orderId, "M0") || isSame(orderId, "M1") || isSame(orderId, "M2") || isSame(orderId, "M3") || isSame(orderId, "M4") || isSame(orderId, "M5")))
    {
        printf("Masukkan command: ");
        scanf("%s %s", command, orderId);
    }

    // mengubah orderId menjadi int

    int id = 0;
    for (int i = 1; orderId[i] != '\0'; i++)
    {
        id = id * 10 + (orderId[i] - '0');
    }

    printf("id: %d\n", id);

// tambahin looping
// enqueue setiap putaran 
// dequeue saat cook time = 0
// enqueue jika bisa diserve 
// conditional kalau makanan hangus 

    if (isSame(command, cook))
    {
        enqueuePQ(&pq, order[id]);
        printf("Makanan %s telah dimasukkan ke dalam antrian\n", orderId);

        queue++;
    }

    else if (isSame(command, serve))
    {
        if (HEAD(pq).foodId == id)
        {
            // kurang-kurangin dari array,
            // tampilin ke daftar masakan yang sedang dimasak
            // print queue

            if (HEAD(pq).cookTime == 0)
            {
                printf("Makanan %d telah selesai dimasak\n", HEAD(pq).foodId);
            }
            served++;
        }

        else
        {
            printf("Makanan %s tidak dapat disajikan karena M%d belum selesai\n", orderId, HEAD(pq).foodId);
        }
        // print queue
        // print makanan yang sedang dimasak
        // print makanan yang dapat disajikan
        // print saldo
    }

        printf("=================================================================\n");
}
