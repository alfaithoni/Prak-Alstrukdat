#include <stdio.h>

int main(){
    int x,last;
    scanf("%d", &x);
    while(x!=0){
        last=x%10;
        printf("%d", last);
        x/=10;
    }
    printf("\n");
    return 0;
}
