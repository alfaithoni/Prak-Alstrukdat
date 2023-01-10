#include <stdio.h>
#include "listsirkuler.h"

boolean IsEmpty (List L){
    return (First(L) == Nil);
}

void CreateEmpty (List *L){
    First(*L) = Nil;
}

address Alokasi (infotype X){
    address P = (address) malloc (sizeof(ElmtList));
    if (P!=Nil){
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (address P){
    free(P);
}

address Search (List L, infotype X){
    address P = First(L);
    boolean ada = false;
    if (P == Nil) {
        ada = false;
    }
    else {
        while (((P)->next != ((L).First)) && ((P)->info != X)) {
            P = (P)->next;
        }
        ada = ((P)->info == X);
    }

    if (ada) {
        return P;
    } else {
        return Nil;
    }
}

void InsVFirst (List *L, infotype X){
    address P = Alokasi(X);
    if (P!=Nil){
        InsertFirst(L,P);
    }
}

void InsVLast (List *L, infotype X){
    address P = Alokasi(X);
    if (P!=Nil){
        InsertLast(L,P);
    }
}

void DelVFirst (List *L, infotype * X){
    address P = First(*L);
    *X  = Info(P);
    DelFirst(L,&P);
    Dealokasi(P);
}

void DelVLast (List *L, infotype * X){
    address P;
    DelLast(L,&P);
    *X = Info(P);
    Dealokasi(P);
}

void InsertFirst (List *L, address P){
    if(IsEmpty(*L)){
        Next(P) = P;
    }
    else {
        address Last = First(*L);
        while (Next(Last)!=First(*L)){
            Last = Next(Last);
        }
        Next(P) = First(*L);
        Next(Last) = P;
    }
    First(*L) = P;
}

void InsertLast (List *L, address P){
    if(IsEmpty(*L)){
        InsertFirst(L,P);
    }
    else {
        address Last = First(*L);
        while (Next(Last)!=First(*L)){
            Last = Next(Last);
        }
        Next(P) = Next(Last);
        Next(Last) = P;
    }
}

void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void DelFirst (List *L, address *P){
    *P = First(*L);
    if(Next(*P) == *P){
        First(*L) = Nil;
    }
    else {
        address Last = First(*L);
        while (Next(Last)!=First(*L)){
            Last = Next(Last);
        }
        Next(Last) = Next(*P);
        First(*L) = Next(*P);
    }
}

void DelLast (List *L, address *P){
    address Last = First(*L);
    address Preclast = Nil;
    while (Next(Last)!=First(*L)){
        Preclast = Last;
        Last = Next(Last);
    }
    *P = Last;
    if (Preclast == Nil){
        First(*L) = Nil;
    }
    else {
        Next(Preclast) = First(*L);
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}

void DelP (List *L, infotype X){
    address P = Search(*L,X);
    if (P!=Nil){
        if(P==First(*L)){
            DelFirst(L,&P);
        }
        else {
            address Prec = First(*L);
            while (Next(Prec)!=P){
                Prec = Next(Prec);
            }
            DelAfter(L,&P,Prec);
        }
        Dealokasi(P);
    }
}

void PrintInfo (List L){
    address P = First(L);
    if (IsEmpty(L)){
        printf("[]");
    }
    else {
        printf("[");
        do{
            printf("%d", Info(P));
            P = Next(P);

            if (P!=First(L)){
                printf(",");
            }
        }
        while(P!=First(L));
        printf("]");
    }
}
