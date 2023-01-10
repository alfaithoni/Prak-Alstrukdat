#include <stdio.h>

int main(){
    float indeks;
    float sumindeks=0;
    int lulus=0;
    float banyak=0;
    float rata; //2 angka belakang koma//
    scanf("%f", &indeks);
    if (indeks == -999){
        printf("Tidak ada data\n");
    } else {
        while(indeks!=-999){
            if (indeks<=4 && indeks>=0){ //validasi input//
                if (indeks>=3){
                    lulus+=1;
                }
                sumindeks+=indeks;
                banyak+=1;

            }scanf("%f", &indeks);

        }

        if (banyak>0){
            printf("Jumlah mahasiswa yang lulus = %d\n", lulus);
            rata=sumindeks/banyak;
            printf("Nilai rata-rata = %.2f\n", rata);
            if (rata==4.00){
                printf("Indeks akhir kelas = A\n");
            } else if (rata>=3.00 && rata<4.00){
                printf("Indeks akhir kelas = B\n");
            } else if (rata>=2.00 && rata<3.00){
                printf("Indeks akhir kelas = C\n");
            } else if (rata>=1.00 && rata<2.00){
                printf("Indeks akhir kelas = D\n");
            } else if (rata>=0 && rata<1.00){
                printf("Indeks akhir kelas = E\n");
            }
        }else {
            printf("Tidak ada data\n");
        }
    }
    return 0;
}
