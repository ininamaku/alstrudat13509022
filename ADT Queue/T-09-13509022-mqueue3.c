/*
Nama/NIM : Muhammad Adinata/13509022.
Nama file : T-09-13509022-mqueue3.c
Topik : Queue
Tanggal : 31 Oktober 2010
Deksripsi : Driver queue dengan tabel kontigu memori dinamis
*/
#include <stdio.h>
#include "T-09-13509022-queue3.h"

int main() {
	int i;
	infotype x;
	Queue Q;
	CreateEmpty (&Q,30);
	for (i=1; !IsFull(Q); i++) {
		Add(&Q, i);
	}
	for (i=1; i<10; i++) {
		Del(&Q,&x);
		printf("%d ", x);
	}
	printf("\n");
	for (i=1; !IsFull(Q); i++) {
		Add(&Q, i);
	}
	while (!IsEmpty(Q)) {
		Del(&Q,&x);
		printf("%d ", x);
	}
	DeAlokasi(&Q);
	return 0;
}
