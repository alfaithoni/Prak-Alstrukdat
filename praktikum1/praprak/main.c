#include <stdio.h>

int main() {
   int h, m, s, d;
   scanf("%d", &d);
   h = d / 3600;
   m = (d % 3600) / 60;
   s = d - m*60 - h*3600;
   printf("%d detik = %d jam %d menit %d detik\n", d, h, m, s);
   return 0;
}