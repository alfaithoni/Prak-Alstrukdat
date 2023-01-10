# include <stdio.h>
# include "circular_queue.h"
# include <stdlib.h>


/* Definisi Queue kosong: HEAD=NIL; TAIL=NIL. */

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
    return (Q.HEAD == NIL) && (Q.TAIL == NIL) ;
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q){
    return Length(Q) == Q.MaxEl;
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int Length (Queue Q){
    if (IsEmpty(Q)){
        return 0;
    }
    else{
        return (Q.MaxEl + Q.TAIL - Q.HEAD)%Q.MaxEl + 1;
    }
}
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
int MaxLength (Queue Q){
    return Q.MaxEl;
}
/* Mengirimkan kapasitas jumlah elemen Q */

/* *** Kreator *** */
Queue CreateQueue (int Max){
    Queue Q;
    Q.HEAD = NIL;
    Q.TAIL = NIL;
    Q.MaxEl = Max;
    Q.Tab = (ElType*)malloc(Max * sizeof(ElType*));
    if (Q.Tab == NULL){
        Q.MaxEl = Max;
    }
    return Q;

}
/* Proses : Melakukan alokasi memori, membuat sebuah Q kosong */
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/*   Jika alokasi berhasil, Tab dialokasi berukuran Max */
/*   Jika alokasi gagal, Q kosong dengan MaxEl=0 */

/* *** Destruktor *** */
void DeleteQueue (Queue * Q){
    free ((*Q).Tab);
    (*Q).MaxEl = 0;
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. membebaskan memori Tab, Q.MaxEl di-set 0 */

/* *** Primitif Add/Delete *** */
void Push (Queue * Q, ElType X){
    if (IsEmpty(*Q)){
        (*Q).Tab[0]=X;
        (*Q).HEAD=0;
        (*Q).TAIL=0;
    }
    else if ((*Q).TAIL == (*Q).MaxEl -1){
        (*Q).Tab[0]=X;
        (*Q).TAIL=0;
    }
    else{
        int a = (*Q).TAIL;
        (*Q).Tab[a+1]=X;
        (*Q).TAIL ++;
    }
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru,
        TAIL "maju" dengan mekanisme circular buffer
        Jika Q kosong, HEAD dimulai dari 0 */
ElType Pop (Queue * Q){
    ElType isi;
    if (Length(*Q)==1){
        int a = (*Q).HEAD;
        isi = (*Q).Tab[a];
        (*Q).HEAD =NIL;
        (*Q).TAIL =NIL;
        return isi;
    }
    else{
        int b=(*Q).HEAD;
        isi = (*Q).Tab[b];
        (*Q).HEAD=((*Q).HEAD+1+(*Q).MaxEl)%(*Q).MaxEl;
        return isi;
    }
}
/* Proses: Menghapus indeks HEAD pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
ElType Front (Queue Q){
    ElType isi;
    int a = (Q).HEAD;
    isi = (Q).Tab[a];
    return isi;
}
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */
