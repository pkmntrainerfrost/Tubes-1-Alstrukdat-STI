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

void dinerDash(){ //prodedur dinerdash

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
    for (int i = 0; i <= 5; i++){ //batas memasak 5 makanan dalam satu waktu
        order[i].foodId = i;
        order[i].cookTime = rand() % 5;
        order[i].stayTime = (rand() * 5 + rand() * 2) % 5;
        order[i].price = rand() % 3 * 10000 + rand() % 4 * 1000;
    }

    PrioQueue pq;
    createQueuePQ(&pq);
    for (i=0;i<3;i++){
    enqueuePQ(&pq, order[i]);        
    }

    printf("SALDO: %d\n", saldo);
    printf("Daftar Pesanan: \n");
    printf("Makanan| Durasi memasak | Ketahanan | Harga\n");
    printf("--------------------------------------------\n");
    for (i = 1; i<=5;i++){
        printf("M0%-5d| %-15d| %-9d | %-6d \n", order[i].foodId+1, order[i].cookTime, order[i].stayTime, order[i].price);
    }

}
