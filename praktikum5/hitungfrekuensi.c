#include "hitungfrekuensi.h"
#include "mesinkarakter.h"

int hitungfrekuensi(){
    START();
    int count = 0, temp = 0;
    while (GetCC() != MARK){
        if ((GetCC() == 't' || GetCC() == 'T') && temp == 0){
            temp = -1;
        }else if (temp == -1 && (GetCC() == 'i' || GetCC() == 'I')){
            temp = -2;
        }else if (temp == -2 && (GetCC() == 'g' || GetCC() == 'G')){
            temp = -3;
        }else if (temp == -3 && (GetCC() == 'a' || GetCC() == 'A')){
            temp = -4;
            if (temp == -4){
                count++;
                temp = 0;
            }
        }else{
            temp = 0;
        }
        ADV();
    }
    return count;
}
