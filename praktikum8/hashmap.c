#include <stdio.h>
#include "hashmap.h"
#include "boolean.h"

/* Definisi HashMap M kosong : M.Count = Nil */
/* M.Count = jumlah element HashMap */
/* M.Elements = tempat penyimpanan element HashMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M) {
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
/* Ciri HashMap kosong : count bernilai Nil dengan seluruh isi map Undefined */
	(*M).Count = Nil;
	for (int i = 0; i < MaxEl; i++) {
		(*M).Elements[i].Key = Undefined;
		(*M).Elements[i].Value = Undefined;
	}
}

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K) {
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */
	return (K % MaxEl);
}
/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k) {
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
	boolean found = false;
	address i = 0;
	while (i < MaxEl && !found) {
		if (M.Elements[i].Key == k) {
			found = true;
		} else {
			i++;
		}
	}
	if (found) {
		return M.Elements[i].Value;
	} else {
		return Undefined;
	}
}
void Insert(HashMap *M, keytype k, valuetype v) {
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open addressing jika index sudah terisi    */
	if (Value(*M, k) == Undefined) {
		int i = 0;
		while ((*M).Elements[Hash(Hash(k) + i)].Key != Undefined) {
			i++;
		}
		(*M).Elements[Hash(Hash(k) + i)].Key = k;
		(*M).Elements[Hash(Hash(k) + i)].Value = v;
		(*M).Count++;
	}
}
