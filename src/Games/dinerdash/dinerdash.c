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

/*
boolean isElTypeEqual(Word kata1, Word kata2){
// mengembalikan true jika str1 sama dengan str2
    boolean check = true;
    int i;

    if (wordLength(kata1) == wordLength(kata2)){
        for(i=0;i<wordLength(kata1);i++){
            if (kata1.buffer[i] != kata2.buffer[i]){
                check = false;
            }
        }
    }
    return check;    
}
*/

PQElType addQueue(int i){
    PQElType addOrder;
    addOrder.foodId = i;
    addOrder.cookTime = (rand() % 5) + 1;
    addOrder.stayTime = (rand() % 5) + 1;
    addOrder.price = (rand() % 5 ) * 5000 + 10000;
    return addOrder;
}

void dequeueAt(PrioQueue *pq, int idx,PQElType * val){
    (*val).foodId = (*pq).buffer[idx].foodId;
	(*val).cookTime = (*pq).buffer[idx].cookTime;
	(*val).stayTime = (*pq).buffer[idx].stayTime;
	(*val).price = (*pq).buffer[idx].price;
    if (IDX_HEAD(*pq) == IDX_TAIL(*pq)){
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    }else{
		int i;
		for(i = idx; i < IDX_TAIL(*pq); i++){
			(*pq).buffer[i].foodId = (*pq).buffer[i + 1].foodId;	
			(*pq).buffer[i].cookTime = (*pq).buffer[i + 1].cookTime;
			(*pq).buffer[i].stayTime = (*pq).buffer[i + 1].stayTime;
			(*pq).buffer[i].price = (*pq).buffer[i + 1].price;	
		}
        IDX_TAIL(*pq)--;
    }

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
        List usr;
        Word orderId;
        Word command;

        printf("\n \n");
        printf("Masukkan command:");
        multiWordInput(&usr, 1, 2);
        command = usr.A[0];
        orderId = usr.A[1];

        //Cek inputan 
        //printf("Command: %s\n", command);
        //printf("orderId: %s\n", orderId);

        // handle input command
        while (!(isElTypeEqual(command, cooks) || isElTypeEqual(command, serves) || isElTypeEqual(command,skips)))
        {
            printf("Masukkan command: ");
            multiWordInput(&usr, 1, 2);
            command = usr.A[0];
            orderId = usr.A[1];
        }

        // mengubah str to int id dan looping jika input tidak sesuai
        int id = 0;
        for (int i = 1; usr.A[i].buffer != '\0'; i++)
        {
            id = id * 10 + (usr.A[i].buffer - '0');
        }
        while (id < HEAD(pq).foodId || id > TAIL(pq).foodId)
        {
            printf("Masukkan command: ");
            multiWordInput(&usr, 1, 2);
            command = usr.A[0];
            orderId = usr.A[1];

            id = 0;
            for (int i = 1; usr.A[i].buffer != '\0'; i++)
            {
                id = id * 10 + (usr.A[i].buffer - '0');
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
                printf("Berhasil mengantar %d\n", id);
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
            }
            ctr++;    
        }
    }
    printf("========== GAME OVER ==========\n");
    printf("SKOR AKHIR : %d\n", saldo);
}


int main(){
    dinerDash();
}