#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./dinerdash.h"
#include "../../Misc/io/io.h"
#include "../../ADT/boolean.h""

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

PQElType addQueue(int i){
    PQElType addOrder;
    addOrder.foodId = i;
    addOrder.cookTime = (rand() % 5) + 1;
    addOrder.stayTime = (rand() % 5) + 1;
    addOrder.price = (rand() % 5 ) * 5000 + 10000;
    return addOrder;
}
void dinerDash(){

    char input[100];
    char cook[] = "COOK";
    char serve[] = "SERVE";
    char skip[] = "SKIP";
    int queue = 0;
    int served = 0;
    int saldo = 0;
    int i;
    printf("Welcome to diner dash!\n\n");

    PQElType order[20];

    srand(time(NULL));
    PrioQueue pq, cookQ, serveQ;      
    createQueuePQ(&pq);  
    createQueuePQ(&cookQ);
    createQueuePQ(&serveQ);
    for (int i = 0; i < 3; i++){ //3 makanan default awal 
        order[i].foodId = i;
        order[i].cookTime = (rand() % 5) + 1;
        order[i].stayTime = (rand() % 5) + 1;
        order[i].price = (rand() % 5 ) * 5000 + 10000;
        enqueuePQ(&pq, order[i]); 
    }   

    printf("SALDO: %d\n\n", saldo);
    printOrders(pq);
    printCooking(cookQ);
    printServing(serveQ);

    int idx;
    idx = 3;
    while (!isFullPQ(pq) && served <= 15){
        //INPUT COMMAND SEMENTARA PAKE SCANF, BELOM SELESAI//
        char command[6];
        char orderId[5];

        printf("\n \n");
        printf("Masukkan command:");
        scanf("%s %s", command, orderId);

        //Cek inputan 

        printf("Command: %s\n", command);
        printf("orderId: %s\n", orderId);

        // handle input command
        while (!(isSame(command, cook) || isSame(command, serve) || isSame(command,skip)))
        {
            printf("Masukkan command: ");
            scanf("%s %s", command, orderId);
        }

        // mengubah str to int id dan looping jika input tidak sesuai
        int id = 0;
        for (int i = 1; orderId[i] != '\0'; i++)
        {
            id = id * 10 + (orderId[i] - '0');
        }
        while (id < HEAD(pq).foodId || id > TAIL(pq).foodId)
        {
            printf("Masukkan command: ");
            scanf("%s %s", command, orderId);

            id = 0;
            for (int i = 1; orderId[i] != '\0'; i++)
            {
                id = id * 10 + (orderId[i] - '0');
            }
        }
        printf("id: %d\n", id);

    // tambahin looping
    // enqueue setiap putaran 
    // dequeue saat cook time = 0
    // enqueue jika bisa diserve 
    // conditional kalau makanan hangus 

        if (isSame(command, cook))
        {
            enqueuePQ(&pq, addQueue(idx));
            enqueuePQ(&cookQ, pq.buffer[id-served]);
            printf("Makanan %s telah dimasukkan ke dalam antrian\n", orderId);
            queue++;
            idx++;
        }
        //belum ada kondisi kalau cookTIme == 0 -> enqueue to serve

        else if (isSame(command, serve))
        {
            if (!isEmptyPQ(serveQ))
            {
                if (HEAD(pq).foodId == id)
                {
                printf("Berhasil mengantar %s\n", orderId);
                enqueuePQ(&pq, addQueue(idx));
                PQElType vals;
                dequeuePQ(&pq, &vals);
                dequeuePQ(&serveQ, &vals);
                // enqueuePQ(&serveQ, pq.buffer[id]);
                served++;
                idx++;
                saldo += HEAD(pq).price;

                }

                else
                {
                printf("Makanan %s tidak dapat disajikan karena M%d belum selesai\n", orderId, HEAD(pq).foodId);
                }
            // print queue
            // print makanan yang sedang dimasak
            // print makanan yang dapat disajikan
            // print saldo
            }else{
                printf("Tidak ada makanan yang siap disajikan\n");
            }
            
        }
        else if (isSame(command, skip))
        {
            enqueuePQ(&pq, addQueue(idx));
            idx++;
        }
        
        printf("\n \n");
        printf("SALDO: %d\n\n", saldo);
        printOrders(pq);
        printCooking(cookQ);
        printServing(serveQ);

        printf("\n \n");        
        printf("=================================================================\n");
        int ctr = IDX_HEAD(cookQ);
        while (ctr < IDX_TAIL(cookQ) + 1){ //untuk mengurangi waktu masak 
            cookQ.buffer[ctr].cookTime -= 1;
            if (cookQ.buffer[ctr].cookTime == 0){
                PQElType vall;
                dequeuePQ(&cookQ, &vall);
                enqueuePQ(&serveQ,vall);
                //printf("Berhasil memasak M%d\n", cookQ.buffer[ctr].foodId);
            }
            ctr++;    
        }
        ctr = IDX_HEAD(serveQ);

        while (ctr < IDX_TAIL(serveQ)+1){ //untuk mengurangi waktu masak 
            serveQ.buffer[ctr].stayTime -= 1;
            ctr++;   
        }
    }
    printf("========== GAME OVER ==========\n");
    printf("SKOR AKHIR : %d\n", saldo);
}


int main(){
    dinerDash();
}