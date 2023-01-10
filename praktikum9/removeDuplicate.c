#include <stdio.h>
#include "removeDuplicate.h"

List removeDuplicate(List l)
{
    List lu;
    address P = First(l);
    CreateEmpty(&lu);
    while (P != Nil)
    {
        if (Search(lu, Info(P)) == Nil)
            InsVLast(&lu, Info(P));
        else
            P = Next(P);
    }
    return lu;
}
