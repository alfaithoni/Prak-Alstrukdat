#include <stdio.h>
#include "list.h"
#include "MinMax.h"

IdxType IdxMin(List L){
    int i, min = L.A[0], temp = 0;
    for (i = FirstIdx(L); i <= LastIdx(L); i++){
        if (L.A[i] < min){
            min = L.A[i];
            temp = i;
        }
    }
    return temp;
}

IdxType IdxMax(List L){
    int i, max = L.A[0], temp = 0;
    for (i = FirstIdx(L); i <= LastIdx(L); i++){
        if(L.A[i] > max){
            max = L.A[i];
            temp = i;
        }
    }
    return temp;
}

List MinMax(List L){
    IdxType idxMin = IdxMin(L);
    ElType tempMin = Get(L, idxMin);
    DeleteAt(&L, idxMin);
    InsertLast(&L, tempMin);

    IdxType idxMax = IdxMax(L);
    ElType tempMax = Get(L, idxMax);
    DeleteAt(&L, idxMax);
    InsertLast(&L, tempMax);
    return L;
}

