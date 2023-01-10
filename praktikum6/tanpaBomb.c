#include "tanpaBomb.h"
#include <stdio.h>

Queue tanpaBomb(Queue queue, ElType bomb){
    int i = 0;
    for (i; i<length(queue); i++){
        if (queue.buffer[i] != bomb){
            printf("%d", queue.buffer[i]);
        }
    }
}
