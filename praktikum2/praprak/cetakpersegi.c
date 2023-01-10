#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    n = 2*n-1;
    int i=1;
    for (i;i<=(n*n);i++){
        if (i%2==0){
            printf("X");
        }else{
            printf("O");
        } //ganjil
        if (i%n==0){
            printf("\n");
        }
    }
    return 0;
}
