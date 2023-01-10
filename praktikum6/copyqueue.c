#include "copyqueue.h"
#include <stdio.h>

void copyQueue(Queue *queueInput, Queue *queueOutput){
    int x,y;
    int i = 0;
    x = IDX_HEAD(*queueInput);
    y = IDX_TAIL(*queueInput);
    for (i; i<length(*queueInput); i++){
        ElType temp;
        temp = HEAD(*queueInput);
        dequeue(queueInput, &HEAD(*queueInput));
        enqueue(queueInput, temp);
        enqueue(queueOutput, temp);
    }
    IDX_HEAD(*queueInput) = x;
    IDX_TAIL(*queueInput) = y;
    IDX_HEAD(*queueOutput) = x;
    IDX_TAIL(*queueOutput) = y;
}
