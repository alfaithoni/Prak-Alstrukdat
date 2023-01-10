#include <stdio.h>

int main(){
    int x;
    scanf("%d", &x);
    int sum=0;
    int last=0;
    while(x!=0){
        last=x%10;
        sum+=last;
        x=(x-last)/10;
    }
    printf("%d\n", sum);
    return 0;
}
