/*
Nama/NIM : Muhammad Adinata/13509022.
Nama file : T-XX-13509022-list1.h
Topik : List
Tanggal : 31 Oktober 2010
Deksripsi : ADT list berkait linier
*/

/* File : list1.h */
/* contoh ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include "T-XX-13509022-list1.h"
#include <stdlib.h>
/* PROTOTYPE */
/***	*** TEST LIST KOSONG ***	***/
boolean ListEmpty (List L) {
/* Mengirim true jika list kosong */
	return (First(L) == Nil);
}

/***	*** PEMBUATAN LIST KOSONG ***	***/
void CreateList (List * L) {
/* I.S. sembarang	*/
/* F.S. Terbentuk list kosong */
	First(*L) = Nil;
}

/***	*** Manajemen Memori ***	***/
address Alokasi (infotype X) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
	/*Kamus Lokal*/
	address P = (address) malloc (1 * sizeof (ElmtList));
	/*Algoritma*/
	info(P) = X;
	next(P) = Nil;
	return P;
}
 
void Dealokasi (address P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
	free(P);
}

/***	*** PENCARIAN SEBUAH ELEMEN LIST ***	***/
address Search (List L, infotype X) {
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
	/*Kamus Lokal*/
	address P = First(L);
	/*Algoritma*/
	while (P != Nil) {
		if (info(P) == X) break;
		else P = next(P);
	}
	return P;
}

boolean FSearch (List L, address P) {
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
	/*Kamus Lokal*/
	address tmp = First(L);
	/*Algoritma*/
	while (tmp != Nil) {
		if (tmp == P) return true; 
		else tmp = next(tmp);
	}
	return false;
}

 address SearchPrec (List L, infotype X, address *Prec) {
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) =P */
/* dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain*/
	/*Kamus Lokal*/
	address P = First(L);
	address found = Search(L,X);
	/*Algoritma*/
	if (found == Nil) {
		(*Prec) = Nil;
		return Nil;
	}
	while (P!=Nil) {
		if (next(P) == found) break;
		else P = next(P);
	}
	(*Prec) = P;
	return P;
}



/***	*** PRIMITIF BERDASARKAN NILAI ***	***/

/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List * L, infotype X) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
	/*Kamus Lokal*/
	address tmp = Alokasi(X);
	/*Algoritma*/
	next(tmp) = First(*L);
	First(*L) = tmp;
}

void InsVLast (List * L, infotype X) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
	/*Kamus Lokal*/
	address tmp = Alokasi(X);
	address tmp2 = First(*L);
	/*Algoritma*/
	if (ListEmpty(*L)) {
		First(*L) = tmp;
	} else {
		while (next(tmp2) != Nil) {
			tmp2 = next(tmp2);
		}
		next(tmp2) = tmp;
	}
}

/*** PENGHAPUSAN ELEMEN ***/

void DelVFirst (List * L, infotype * X) {
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/* 	dan alamat elemen pertama di-dealokasi */
	/*Kamus Lokal*/
	address tmp;
	/*Algoritma*/
	tmp = First(*L);
	(*X) = info(tmp);
	First(*L) = next(tmp);
	Dealokasi(tmp);
}

void DelVLast (List * L, infotype * X) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*	dan alamat elemen terakhir di-dealokasi */
	/*Kamus Lokal*/
	address tmp = First(*L);
	address prec = Nil;
	/*Algoritma*/
	while (next(tmp)!=Nil) {
		prec = tmp;
		tmp = next(tmp);
	}
	*X = info(tmp);
	if (prec == Nil) First(*L) = Nil; 
	else next(prec) = Nil;
	Dealokasi(tmp);
}

/*** *** PRIMITIF BERDASARKAN ALAMAT *** ***/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List * L, address P) {
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
	/*Algoritma*/
	next(P) = First(*L);
	First(*L) = P;
}

void InsertAfter (List * L, address P, address Prec) {
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*	P sudah dialokasi	*/
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
	/*Algoritma*/
	next(P) = next(Prec);
	next(Prec) = P;
}

void InsertLast (List * L, address P) {
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
	/*Kamus Lokal*/
	address tmp = First(*L);
	/*Algoritma*/
	if (First(*L) == Nil) InsertFirst(L, P);
	else while (next(tmp) != Nil) {
		tmp = next(tmp);
	}
	InsertAfter(*L, P, tmp);
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/

void DelFirst (List * L, address * P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
	/*Algoritma*/
	(*P) = First(*L);
	First(*L) = next(First(*L));
}


void DelP (List * L, infotype X) {
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P) =X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P) =X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
	/*Kamus Lokal*/
	address Prec = First(*L);
	address Found = Search(*L, X);
	/*Algoritma*/
	if (Found != Nil) {
		if (First(*L) == Found) {
			DelFirst(L, &Found);
		} else {
			while (next(Prec) != Found) {
				Prec = next(Prec);
			}
			next(Prec) = next(Found);
		}
		Dealokasi(Found);
	}
}

void DelLast (List * L, address * P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan 
	Elemen list berkurang satu (mungkin menjadi kosong) { */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
	/*Kamus Lokal*/
	address Last = First(*L);
	address PrecLast = Nil;
	/*Algoritma*/
	while (next(Last) != Nil) {
		PrecLast = Last;
		Last = next(Last);
	}
	*P = Last;
	if (PrecLast = Nil) First(*L) = Nil;
	else next(PrecLast) = Nil;
}

void DelAfter (List * L, address * Pdel, address Prec) {
/* I.S. List tidak kosong. Prec adalah anggota list
/* F.S. Menghapus Next(Prec): */
/*	Pdel adalah alamat elemen list yang dihapus */
	/*Algoritma*/
	*Pdel = next(Prec);
	next(Prec) = next(*Pdel);
}

/******* PROSES SEMUA ELEMEN LIST ********/

void Printinfo (List L) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
	/*Kamus Lokal*/
	address tmp = First(L);
	/*Algoritma*/
	if (tmp == Nil) printf("list kosong");
	else while (tmp != Nil) {
		printf("%d ", info(tmp));
		tmp = next(tmp);
	}
	printf("\n");
}

int NbElmt(List L) {
/* Mengirimkan banyaknya elemen list
mengirimkan 0 jika list kosong */
	/*Kamus Lokal*/
	address tmp = First(L);
	int count = 0;
	/*Algoritma*/
	while (tmp!= Nil) {
		tmp = next(tmp);
		count++;
	}
	return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L) {
/* Mengirimkan nilai info(P) yang maksimum */
	/*Kamus Lokal*/
	address P = First(L);
	infotype M = info(P);
	/*Algoritma*/
	while (P != Nil) {
		if (M < info(P)) {
			M = info(P);
		}
		P = next(P);
	}
	return M;
}
address AdrMax (List L) {
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
	/*Kamus Lokal*/
	address P = First(L);
	address M = First(L);
	/*Algoritma*/
	while (P!=Nil) {
		if (info(M) < info(P)) {
			M = P;
		}
		P = next(P);
	}
	return M;
}

infotype Min (List L) {
/* Mengirimkan nilai info(P) yang minimum */
	/*Kamus Lokal*/
	address P = First(L);
	infotype M = info(P);
	/*Algoritma*/
	while (P != Nil) {
		if (M > info(P)) {
			M = info(P);
		}
		P = next(P);
	}
	return M;
}

address AdrMin (List L) {
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
	/*Kamus Lokal*/
	address P = First(L);
	address M = First(L);
	/*Algoritma*/
	while (P!=Nil) {
		if (info(M) > info(P)) {
			M = P;
		}
		P = next(P);
	}
	return M;

infotype Average (List L) {
/* Mengirimkan nilai rata-rata info(P) */
	/*Kamus Lokal*/
	infotype sum = 0;
	address P = First(L);
	/*Algoritma*/
	while (P!= Nil) {
		sum += info(P);
		P = next(P);
	}
	return (sum / NbElmt(L));
}

/***	*** PROSES TERHADAP LIST ***	***/
void DelAll (List *L) {
/* Delete semua elemen list dan alamat elemen di-dealokasi */
	/*Kamus Lokal*/
	address P = First(*L);
	address tmp;
	/*Algoritma*/
	while (P!=Nil) {
		tmp = P;
		P = next(P);
		Dealokasi(tmp);
	}
	First(*L) = Nil;
}

void InversList (List *L) {
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
	/*Kamus Lokal*/
	address Prec = Nil, Last;
	address P = First(*L);
	/*Algoritma*/
	while (P!=Nil) {
		Last = P;
		P = next(P);
		next(Last) = Prec;
		Prec = Last; ///////////////////////////////////////////////////////////////////////
	}
	First(*L) = Prec;
}

List FInversList (List L) {
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemen list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
	List R = FCopyList(L);
	InversList(&R);
	return R;
}

void CopyList (List* L1, List * L2) {
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
	First(L2) = First(L1);
}

List FCopyList (List L ) {
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
	List R;
	address akses = First(L);
	address buat;
	First(R) = buat;
	while (akses != Nil) {
		buat = Alokasi(info(akses));
		akses = next(akses);
		buat = next(buat);
	}
	buat = Nil;	
	return R;
}

void CpAlokList (List Lin, List * Lout) {
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
}

void Konkat (List L1, List L2, List * L3) {
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang “baru” */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */

void Konkat1 (List * L1, List * L2, List * L3) {
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2 */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) {*/
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

void PecahList (List *L1, List * L2, List L) {
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) { div 2 */
