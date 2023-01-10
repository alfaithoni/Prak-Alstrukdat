#include <stdio.h>
#include <math.h>

int main(){
    float x;
    scanf("%f", &x);
    int f, c;
    if (x>0){
        f = floor(x);
        c = ceil(x);
    }else if (x<0){
        f = floor(x);
        c = ceil(x);
    }
    printf("%d %d\n", f, c);
    return 0;
}
