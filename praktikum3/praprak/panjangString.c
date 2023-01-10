#include "panjangstring.h"
#include "string.h"

// menerima argumen pointer kepada karakter pertama dari sebuah string yang panjangnya tidak diketahui
// dan memberikan output berupa panjang string tersebut, dengan batasan string input memiliki karakter
// '\0' pada akhir string
/* int panjangString(char*x){
    return strlen(x);
}*/

int panjangString(char*x){
    int i=0;
    int banyak=0;
    while (x[i]!='\0'){
        banyak+=1;
        i++;
        
    }
    return banyak;
}


