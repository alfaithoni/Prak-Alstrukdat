#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char string[100];
    char string1[100];
    scanf("%s", string);
    scanf("%s", string1);
    int sum=0;
    int i=0;
    if (strlen(string)==strlen(string1)){
        for (i;i<strlen(string);i++){
        if (tolower(string[i])==tolower(string1[i])){
            sum+=1;
        }
    }
    if (sum==0){
        printf("Tidak\n");
    }else {
        printf("Ya\n");
    }
    }else{
        printf("Tidak\n");
    }

    return 0;
}
