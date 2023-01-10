#include "stack.h"
#include "boolean.h"
#include "aritmatika.h"
#include <stdio.h>

boolean isOperator(char input){
    return (input == '+' || input == '-' || input == '*' || input == '/');
}

int hitung(int angka1, int angka2, char op){
    if (op == '+'){
        return (angka1 + angka2);
    }
    else if (op == '-'){
        return (angka1 - angka2);
    }
    else if (op == '*'){
        return (angka1 * angka2);
    }
    else if (op == '/'){
        return (angka1 / angka2);
    }
}

int eval(char *input, int length){
    Stack S1;
    CreateEmpty(&S1);
    int i =0;
    while (i<length){
        if (!isOperator(input[i])){
            infotype X = input[i]-48;
            Push(&S1,X);
        }
        else {
            infotype op1,op2;
            Pop(&S1,&op1);
            Pop(&S1,&op2);
            Push(&S1,hitung(op2,op1,input[i]));
        }
        i++;
    }
    return InfoTop(S1);
}
