#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, i, q, count;
    int *arrN;

    scanf("%d", &N);
    arrN = (int *)malloc(sizeof(int) * N);
    for (i = 0; i < N; i++){
        scanf("%d", &arrN[i]);
    }

    scanf("%d", &q);
    for (i = 0; i < q; i++){
        int l, r;
        count = 0;

        scanf ("%d %d", &l, &r);
        for (l; l <= r; l++){
            count += arrN[(l - 1) % N];
        }
        printf("%d\n", count);
    }
    return 0;
}
