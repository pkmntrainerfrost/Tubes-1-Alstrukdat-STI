#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void CreateEmptyMap(Map *M)
{
    (*M).Elements = (infotype*) malloc (InitialSize * sizeof(infotype));
    (*M).Count = Nil;
}

void deallocateMap(Map *M)
{
    free((*M).Elements);
    (*M).Count = Nil;
}

void updateCapacityMap(Map *M)
{
    int newCapacity = 2 * InitialSize;
    infotype *newBuffer = (infotype*) malloc (newCapacity * sizeof(infotype));
    int i;
    for (i = 0; i < (*M).Count; i++){
        newBuffer[i] = (*M).Elements[i];
    }
    free((*M).Elements);
    (*M).Elements = newBuffer;
}

boolean IsEmptyMap(Map M)
{
    return (M.Count == Nil);
}

boolean IsFullMap(Map M)
{
    return (M.Count == InitialSize);
}

valuetype Value(Map M, keytype k)
{
    if (IsMemberMap(M, k)){
        boolean found = false;
        int i = 0;
        while (i < M.Count){
            if (isWordEqual(M.Elements[i].name, k)){
                return (M.Elements[i].score);
            }
            i++;
        }
    } else {
        return Undefined;
    }
}

void InsertMap(Map *M, keytype k, valuetype v)
{
    if (IsFullMap(*M)){
        updateCapacityMap(M);
    }

    if (!(IsMemberMap(*M, k))){
        (*M).Count++;
        (*M).Elements[(*M).Count-1].name = k;
        (*M).Elements[(*M).Count-1].score = v;
    }
}

void DeleteMap(Map *M, keytype k)
{
    if (IsMemberMap(*M, k)){
        boolean found = false;
        int i = 0;
        while (i < (*M).Count && (!found)){
            if (isWordEqual((*M).Elements[i].name, k)){
                found = true;
            } else {
                i++;
            }
        }

        int j;
        for (j=i; j<(*M).Count-1; j++){
            (*M).Elements[j].name = (*M).Elements[j+1].name;
            (*M).Elements[j].score = (*M).Elements[j+1].score;
        }
        (*M).Count--;
    }
}

boolean IsMemberMap(Map M, keytype k)
{
    boolean found = false;
    int i = 0;
    while (i < M.Count && (!found)){
        if (isWordEqual(M.Elements[i].name, k)){
            found = true;
        } else {
            i++;
        }
    }
    return found;
}

void PrintMap(Map M)
{
    if (IsEmptyMap(M)){
        printf("Map kosong\n");
    } else {
        int i;
        printf("[");
        for (i=0; i<M.Count; i++){
            int j;
            for (j=0; j<M.Elements[i].name.length; j++){
                printf("%c", M.Elements[i].name.buffer[j]);
            }
            printf(" %d", M.Elements[i].score);

            if (i+1 != M.Count){
                printf(", ");
            }
        }
        printf("]\n");
    }
}

// void inputName(Map *M)
// {
//     boolean repeat = true;
//     while (repeat){
//         printf("Masukkan nama: ");
//         Word name;
//         boolean valid = wordInput(&name, 1, N_MAX);

//         if (valid){
//             if (IsMemberMap(*M, name)){
//                 printf("Nama sudah ada di daftar scoreboard. \n");
//             } else {
//                 printf("Masukkan score: ");
//                 int score;
//                 scanf("%d", &score);
//                 InsertMap(M, name, score);
//                 repeat = false;
//             }
//         } else {
//             if (wordLength(name) == 0){
//                 printf("Nama tidak boleh kosong. \n");
//             } else {
//                 printf("Nama terlalu panjang. \n");
//             }
//         }
//     }
// }