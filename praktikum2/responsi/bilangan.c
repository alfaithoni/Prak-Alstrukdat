#include <stdio.h>

int main(){
    int N; //jumlah test case//
    int M; //input 1-M//
    int i;
    int j;
    int temp;
    int sum=0;
    scanf("%d", &N);
    for (i=1;i<=N;i++){
        scanf("%d", &M);
        for (j=1;j<=M;j++){
            if (j%7==0){
                sum+=j;
            } else {
                temp=j;
                while(temp>0){
                    if (j%10==7){
                        temp=-1;
                    }
                    if (temp==-1){
                        sum+=j;
                    }
                    temp/=10;
                }
            }
        }
        printf("%d\n", sum);
        sum=0;
    }
    return 0;
}




