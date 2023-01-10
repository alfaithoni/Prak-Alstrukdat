#include "reverse.h"
#include <stdio.h>

void transferReverse(Queue* q1, Queue* q2){
    if (Length(*q1)==1){
        (*q2).Tab[0] = Pop(q1);
        (*q2).HEAD = 0;
        (*q2).TAIL = 0;
    }
    else{
        (*q2).HEAD = 0;
        (*q2).TAIL = Length(*q1)-1;
        int i = Length(*q1)-1;
        for (i; i>=0; i--){
            (*q2).Tab[Length(*q1)-1]=Pop(q1);
        }
    }
}
// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik

