#include "linkstack.h"

void Alokasi(address *P, ElType X)
{
    *P = (Node *)malloc(sizeof(Node));
    if (*P != Nil)
    {
        Info(*P) = X;
        Next(*P) = Nil;
    }
}

void Dealokasi(address P)
{
    free(P);
}

boolean IsEmpty(Stack S)
{
    return Top(S) == Nil;
}

void CreateEmpty(Stack *S)
{
    Top(*S) = Nil;
}

void Push(Stack *S, ElType X)
{
    address P;
    Alokasi(&P, X);
    if (P != Nil)
    {
        if (!IsEmpty(*S))
            Next(P) = Top(*S);
        Top(*S) = P;
    }
}

void Pop(Stack *S, ElType *X)
{
    *X = InfoTop(*S);
    address P = Top(*S);
    Top(*S) = Next(Top(*S));
    Dealokasi(P);
}
