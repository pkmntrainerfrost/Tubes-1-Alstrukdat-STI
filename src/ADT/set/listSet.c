#include <stdio.h>
#include <stdlib.h>
#include "listSet.h"

void createListSet(ListSet *L){
    (*L).ElmtListSet = (ElTypeSet*) malloc (defaultSizeSet * sizeof(ElTypeSet));
    (*L).capacityListSet = defaultSizeSet;
    (*L).nEff = 0;
}

void deallocateListSet(ListSet *L){
    free((*L).ElmtListSet);
    (*L).capacityListSet = 0;
    (*L).nEff = 0;
}

void updateCapacityListSet(ListSet *L){
    int newCapacity = 2 * defaultSizeSet;
    ElTypeSet *newBuffer = (ElTypeSet*) malloc (newCapacity * sizeof(ElTypeSet));
    int i;
    for (i = 0; i < (*L).nEff; i++){
        newBuffer[i] = (*L).ElmtListSet[i];
    }
    free((*L).ElmtListSet);

    (*L).ElmtListSet = (ElTypeSet*) malloc (newCapacity * sizeof(ElTypeSet));

    for (i=0; i<(*L).nEff; i++){
        (*L).ElmtListSet[i] = newBuffer[i];
    }

    free(newBuffer);
    (*L).capacityListSet = newCapacity;
}

boolean isEmptyListSet(ListSet L){
    return (L.nEff == 0);
}

boolean isFullListSet(ListSet L){
    return (L.nEff == L.capacityListSet);
}

void insertListSet(ListSet *L, Set S){
    if (isFullListSet(*L)){
        updateCapacityListSet(L);
    }
    (*L).ElmtListSet[(*L).nEff] = S;
    (*L).nEff++;
}

void deleteListSet(ListSet *L, int idx){
    int i;
    for (i=idx; i<(*L).nEff-1; i++){
        (*L).ElmtListSet[i] = (*L).ElmtListSet[i+1];
    }
    (*L).nEff--;
}

boolean insertElmt(ListSet *L, int idx, infotypeSet Elmt){
    return (InsertSet(&(*L).ElmtListSet[idx], Elmt));
}

void displayListSet(ListSet S){
    int i;
    for (i=0; i<S.nEff; i++){
        printf("Set %d: ", i);
        PrintSet(S.ElmtListSet[i]);
        printf("\n");
    }
}