#include <stdio.h>
#include "prioqueue.h"
#include "../boolean.h"

void createQueuePQ(PrioQueue *pq){
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

boolean isEmptyPQ(PrioQueue pq){
    return ((IDX_HEAD(pq) == IDX_UNDEF) && (IDX_TAIL(pq) == IDX_UNDEF));
}

boolean isFullPQ(PrioQueue pq){
    return(IDX_TAIL(pq) == PQCAPACITY-1 && IDX_HEAD(pq) == 0);
}

int lengthPQ(PrioQueue pq){
    if (isEmptyPQ(pq)){
        return 0;
    }else{
        return IDX_TAIL(pq) - IDX_HEAD(pq) + 1;
    }
}

void enqueuePQ(PrioQueue *pq, PQElType val){
    if (isEmptyPQ(*pq)){
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
    }else{
		IDX_TAIL(*pq) = (IDX_TAIL(*pq) + 1) % PQCAPACITY;
		int idx = IDX_HEAD(*pq);
		while (((*pq).buffer[IDX_HEAD(*pq)].cookTime > val.cookTime) && (IDX_HEAD(*pq) != (IDX_TAIL(*pq)))){
			PQElType temp = (*pq).buffer[IDX_HEAD(*pq)];
			(*pq).buffer[IDX_HEAD(*pq)] = (*pq).buffer[IDX_HEAD(*pq) + 1];
			(*pq).buffer[IDX_HEAD(*pq) + 1] = temp;
			IDX_HEAD(*pq)++;
		}

		IDX_HEAD(*pq) = idx;
		(*pq).buffer[IDX_HEAD(*pq)] = val;
	}
}

void dequeuePQ(PrioQueue *pq, PQElType *val){
    *val = HEAD(*pq);
    if (IDX_HEAD(*pq) == IDX_TAIL(*pq)){
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    }

    else{
        IDX_HEAD(*pq) = (IDX_HEAD(*pq) + 1) % PQCAPACITY;
    }
}

/**** Display Queue ****/

void printOrders(PrioQueue pq){
	printf("Daftar Pesanan: \n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("—---------------------------------------------\n");
	if (isEmptyPQ(pq)){
		printf("\n");
	}else{
		PQElType val;
		int i = IDX_HEAD(pq);
		while (i != IDX_TAIL(pq)){
		    for (i = 0; i<3;i++){
				printf("M%d      | %d              | %d         | %d\n", pq.buffer[i].foodId+1, 
				pq.buffer[i].cookTime, pq.buffer[i].stayTime, pq.buffer[i].price);
			}
		}
	}
}

void printCooking(PrioQueue pq){
    printf("\n \n");
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("—-----------------------------\n");
	if (isEmptyPQ(pq)){
		printf("\n");
	}else{
		PQElType val;
		int i = IDX_HEAD(pq);
		while (i != IDX_TAIL(pq)){
			printf("M%d      | %d              ", pq.buffer[i].foodId, pq.buffer[i].cookTime);
			i++;
		}
	}
}

void printServing(PrioQueue pq){
    printf("\n \n");
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("—-----------------------------\n");
	if (isEmptyPQ(pq))
	{
		printf("\n");
	}
	else
	{
		PQElType val;
		int i = IDX_HEAD(pq);
		while (i != IDX_TAIL(pq))
		{
			printf("M%d      | %d              ", pq.buffer[i].foodId, pq.buffer[i].stayTime);
			i++;
		}
	}
}
