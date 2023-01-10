/* Tuliskan header di sini berisi nama, dll */

#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r) {
    int i;
    address P = First(L);
    for (i=0;i<r;i++){
        P = Next(P);
    }
    return Info(P);
}

int main () {
  List L;
  CreateEmpty(&L);
  int r,x;
  scanf("%d",&x);
  while (x!=0){
    InsVLast(&L,x);
    scanf("%d",&x);
  }
  scanf("%d",&r);
  if (IsEmpty(L)){
    printf("List Kosong\n");
  }
  else {
    printf("%d\n", ElemenKeN(L, r));
  }
  return 0;
}
