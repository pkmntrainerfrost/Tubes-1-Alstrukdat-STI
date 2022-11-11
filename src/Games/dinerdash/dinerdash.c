#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/boolean.h"
#include "../../ADT/word/mesinkarakter/mesinkarakter.h"
#include "../../ADT/word/mesinkata/mesinkata.h"
#include "../../ADT/queue/prioqueue.h"
#include "../../ADT/queue/queue2.h"
#include "../../Misc/io/io.h"
#include "../../ADT/word/word.h"
#include "../../Misc/ascii/ascii.h"
#include "../../ADT/list/array.h"
#include "../../Games/random.h"

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
    Word cooks = stringToWord(cook);
    Word serves = stringToWord(serve);
    Word skips = stringToWord(skip);
    PQElType order[20];

    srand(time(NULL));
    PrioQueue pq, cookQ, serveQ;      
    createQueuePQ(&pq);  
    createQueuePQ(&cookQ);
    createQueuePQ(&serveQ);
    for (int i = 0; i < 3; i++){ //3 makanan default awal 
        order[i].foodId = i;
        order[i].cookTime = random_range(1,4) + 1;
        order[i].stayTime = random_range(1,5) + 1;
        order[i].price = random_range(1,8) * 5000 + 10000;
        enqueuePQ(&pq, order[i]); 
    }   

    printf("SALDO: %d\n\n", saldo);
    printOrders(pq);
    printCooking(cookQ);
    printServing(serveQ);

    int idx;
    idx = 3;
    while (!isFullPQ(pq) && served <= 15){
        List usr;
        createList(&usr);
        Word orderId;
        Word command;
        int valid;

        printf("\n \n");
        printf("Masukkan command:");
        valid = multiWordInput(&usr, 1, 2);

        if (valid){
            command = usr.A[0];
            orderId = usr.A[1];            
        }


        //Cek inputan 
        //printf("Command: %s\n", command);
        //printf("orderId: %s\n", orderId);

        // handle input command
        while (!(isElTypeEqual(command, cooks) || isElTypeEqual(command, serves) || isElTypeEqual(command,skips)))
        {
            printf("Masukkan command: ");
            valid = multiWordInput(&usr, 1, 2);

            if (valid){
                command = usr.A[0];
                orderId = usr.A[1];            
            }
        }

        // mengubah str to int id dan looping jika input tidak sesuai
        int id = 0;
        for (int i = 1; i < usr.A[1].length; i++)
        {
            id = id * 10 + (usr.A[1].buffer[i] - '0');
        }
        while (id < HEAD(pq).foodId || id > TAIL(pq).foodId)
        {
            printf("Masukkan command: ");
            valid = multiWordInput(&usr, 1, 2);

            if (valid){
                command = usr.A[0];
                orderId = usr.A[1];            
            }

            id = 0;
            for (int i = 1; i < usr.A[1].length; i++)
            {
                id = id * 10 + (usr.A[1].buffer[i] - '0');
            }
        }
        printf("id: %d\n", id);

        if (isElTypeEqual(command, cooks) == true)
        {
            enqueuePQ(&pq, addQueue(idx));
            enqueuePQ(&cookQ, pq.buffer[id-served]);
            printf("Makanan M%d sedang dimasak\n", id);
            queue++;
            idx++;
        }

        else if (isElTypeEqual(command, serves) == true)
        {
            if (!isEmptyPQ(serveQ))
            {
                if (HEAD(pq).foodId == id)
                {
                printf("Berhasil mengantar M%d\n", id);
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
                printf("Makanan M%d tidak dapat disajikan karena M%d belum selesai\n", id, HEAD(pq).foodId);
                }

            }else{
                printf("Tidak ada makanan yang siap disajikan\n");
            }
            
        }
        else if (isElTypeEqual(command, skips) == true)
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
        
        int ctr;
        ctr = IDX_HEAD(serveQ);

        while (ctr < IDX_TAIL(serveQ)+1){ //untuk mengurangi waktu masak 
            serveQ.buffer[ctr].stayTime -= 1;
            ctr++;   
        }

        ctr = IDX_HEAD(cookQ);
        while (ctr < IDX_TAIL(cookQ) + 1){ //untuk mengurangi waktu masak 
            cookQ.buffer[ctr].cookTime -= 1;
            if (cookQ.buffer[ctr].cookTime == 0){
                PQElType vall;
                dequeueAt(&cookQ, ctr, &vall);
                enqueuePQ(&serveQ,vall);
                //printf("Berhasil memasak M%d\n", cookQ.buffer[ctr].foodId);
            }else{
                ctr++;  
            }  
        }
    }
    printf("========== GAME OVER ==========\n");
    printf("SKOR AKHIR : %d\n", saldo);
}

/*
int main(){
    dinerDash();
}
compile:
gcc /Users/trista/Documents/GitHub/Tubes-1-Alstrukdat-STI/src/Games/dinerdash/dinerdash.c /Users/trista/Documents/GitHub/Tubes-1-Alstrukdat-STI/src/ADT/word/mesinkarakter/mesinkarakter.c /Users/trista/Documents/GitHub/Tubes-1-Alstrukdat-STI/src/ADT/word/mesinkata/mesinkata.c /Users/trista/Documents/GitHub/Tubes-1-Alstrukdat-STI/src/ADT/queue/prioqueue.c /Users/trista/Documents/GitHub/Tubes-1-Alstrukdat-STI/src/ADT/queue/queue2.c /Users/trista/Documents/GitHub/Tubes-1-Alstrukdat-STI/src/Misc/io/io.c /Users/trista/Documents/GitHub/Tubes-1-Alstrukdat-STI/src/ADT/word/word.c /Users/trista/Documents/GitHub/Tubes-1-Alstrukdat-STI/src/Misc/ascii/ascii.c /Users/trista/Documents/GitHub/Tubes-1-Alstrukdat-STI/src/ADT/list/array.c -o try_DD
*/