#include <stdio.h>

int main(){
    int x, i=0 ;
    int *T;
    scanf("%d", &x);
    if (x == 0){
        printf("Stack kosong\n");
    }
    else {
        T[i] = x;
        while (x!=0){
            i++;
            scanf("%d", &x);
            T[i] = x;
        }
        printf("x");
    }
}
