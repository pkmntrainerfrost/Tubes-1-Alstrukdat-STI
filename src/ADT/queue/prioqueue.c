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

void enqueue(PrioQueue *pq, PQElType val){
    if (isEmptyPQ(*pq)){
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
    }else{
		IDX_TAIL(*pq) = (IDX_TAIL(*pq) + 1) % PQCAPACITY;
		int idx = IDX_HEAD(*pq);
		while (((*pq).buffer[IDX_HEAD(*pq)].cookTime > val.cookTime) && (IDX_HEAD(*pq) != (IDX_TAIL(*pq))))
		{
			PQElType temp = (*pq).buffer[IDX_HEAD(*pq)];
			(*pq).buffer[IDX_HEAD(*pq)] = (*pq).buffer[IDX_HEAD(*pq) + 1];
			(*pq).buffer[IDX_HEAD(*pq) + 1] = temp;
			IDX_HEAD(*pq)++;
		}

		IDX_HEAD(*pq) = idx;

		(*pq).buffer[IDX_HEAD(*pq)] = val;
	}
}