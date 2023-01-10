#include <stdio.h>

int main(){
   float suhu;
   printf("Masukkan suhu! (celcius) \n");
   scanf("%f", &suhu);
   char satuan;
   printf("Masukkan satuan!\n");
   scanf(" %c", &satuan);
   float R, F, K;
   R = (0.8*suhu);
   F = (1.8*suhu + 32);
   K = (suhu + 273.15);
   if (satuan == 'R'){
      printf("%.2f \n", R);
   } else if (satuan == 'F'){
      printf("%.2f \n", F);
   } else if (satuan == 'K'){
      printf("%.2f \n", K);
   }
   return 0;
}