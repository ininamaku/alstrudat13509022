/*
Nama/NIM : Muhammad Adinata/13509022.
Nama file : T-09-13509022-queue1.h
Topik : Queue
Tanggal : 31 Oktober 2010
Deksripsi : ADT queue dengan tabel kontigu memori dinamis
*/

#ifndef QUEUE1_H
#define QUEUE1_H
#include "boolean.h"
#include <stdlib.h>

extern const int Nil;

/* Definisi elemen dan address  */ 
typedef int infotype; 
typedef int address; /* indeks tabel  */
/* Contoh deklarasi variabel bertype Queue  :  */

/*Versi I: tabel dinamik,Head dan Tail eksplisit, ukuran disimpan  */
typedef struct  { 
	infotype  *T;  /* tabel penyimpan elemen  */
 	address HEAD;	/* alamat penghapusan  */
 	address TAIL; /* alamat penambahan  */
	int MaxEl; /* MAx elemen queue  */
} Queue; 
/* Definisi Queue kosong: Head=Nil; TAIL=Nil.  */
/* Catatan implementasi: T[0] tidak pernah dipakai  */

/**** AKSES  (Selektor)  ****/
/* Jika Q adalah Queue, maka akses elemen  :  */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl

/***	* Prototype  ***	*/
boolean IsEmpty  (Queue Q); 
/* Mengirim true jika Q kosong: lihat definisi di atas  */

boolean IsFull(Queue Q); 
/* Mengirim true jika tabel penampung elemen Q sudah penuh  */
/* yaitu mengandung MaxEl elemen */

int NBElmt(Queue Q); 
/* Mengirimkan banyaknya elemen queue. Mengirimkan  0 jika Q kosong  */

/*** Kreator  ***/ 
void CreateEmpty(Queue  *Q, int Max); 
/* I.S. sembarang  */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb:  */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max  */
/* atau  : jika alokasi gagal, Q kosong dg Maksimum elemen=0  */
/* Proses  : Melakukan alokasi,Membuat sebuah Q kosong  */

 /*** Destruktor  ***/ 
void DeAlokasi(Queue  *Q); 
/* Proses: Mengembalikan memori Q  */
/* I.S. Q pernah dialokasi  */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset  0  */

/*** Primitif Add/Delete  ***/ 
void Add  (Queue  * Q, infotype X); 
/* Proses: Menambahkan    X pada Q dengan aturan FIFO  */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh  */
/* F.S. X menjadi TAIL yang baru, TAIL "maju"  */ 
/* Jika Tail(Q)=MaxEl+1 maka geser isi tabel, shg Head(Q)=1  */

void Del(Queue  * Q, infotype* X); 
/* Proses: Menghapus    X pada Q dengan aturan FIFO  */
/* I.S. Q tidak mungkin kosong  */
/* F.S. X  = nilai elemen HEAD pd I.S.,HEAD "maju";Q mungkin kosong  */

 #endif 
