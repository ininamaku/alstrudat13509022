/*
Nama/NIM : Muhammad Adinata/13509022.
Nama file : T-09-13509022-queue1.c
Topik : Queue
Tanggal : 31 Oktober 2010
Deksripsi : ADT queue dengan tabel kontigu memori dinamis
*/

#include "boolean.h"
#include "T-09-13509022-queue1.h"
#include <stdlib.h>

const int Nil = 0;

boolean IsEmpty (Queue Q) {
	/*Algoritma*/
	return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull (Queue Q) {
	/*Algoritma*/
	return (NBElmt(Q) == Q.MaxEl);
}

int NBElmt(Queue Q) {
	/*Algoritma*/
	return (Tail(Q) - Head(Q) + 1);
}

void CreateEmpty (Queue * Q, int Max) {
	/*Algoritma*/
	(*Q).T = (infotype*) malloc (Max * sizeof (infotype));
	MaxEl(*Q) = Max-1;
	if ((*Q).T == NULL) {
		(*Q).T = (infotype*) malloc (1 * sizeof (infotype));
		MaxEl(*Q) = 1;
	}
	Head(*Q) = Nil; 
	Tail(*Q) = Nil;
}

void DeAlokasi (Queue *Q) {
	/*Algoritma*/
	free ((*Q).T);
}

void Add (Queue * Q, infotype X) {
	/*Algoritma*/
	if (IsEmpty(*Q)) {
		Head(*Q) = 1;
		Tail(*Q) = 1;
	}
	else  {
		Tail(*Q)+=1;
	}
	InfoTail(*Q) = X;	
}

void Del (Queue * Q, infotype * X) {
	/*Kamus Lokal*/
	int i;
	/*Algoritma*/
	(*X) = InfoHead(*Q);
	for (i=1; i<Tail(*Q); i++) {
		(*Q).T[i] = (*Q).T[i+1];
	}
	Tail(*Q) -= 1;
	if (Tail(*Q) == 0) {
		Tail(*Q) = Nil;
		Head(*Q) = Nil;
	}
}
