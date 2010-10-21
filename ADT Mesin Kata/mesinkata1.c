#ifndef MESINKATA_C 
#define MESINKATA_C
#include "mesinkata1.h"
#include "boolean.h"
#include <stdio.h>

boolean EndKata;
Kata CKata;
extern char CC;

void Ignore_Blank(void)
/*  Mengabaikan  satu  atau  beberapa  BLANK  */ 
/*  I.S.  :  CC  sembarang  */ 
/*  F.S.  :  CC  =  BLANK  atau  CC  =  MARK  */ 
{	
	while (CC == BLANK) {
		ADV();
	}
}

void  STARTKATA(void)
/*  I.S.  :  CC  sembarang  */ 
/*  F.S.  :  EndKata  =  true,  dan  CC  =  Mark;  */ 
/*	atau  EndKata  =  false,  CKata  adalah  kata  yang  sudah  diakuisisi,
	CC  karakter  pertama  sesudah  karakter  terakhir  kata  */ 
{
	/* Kamus Lokal */
	// Algoritma
	START();
	Ignore_Blank();
	
	if (EOP() || CC == BLANK ) {
		EndKata = true;
	} else {
		SalinKata();
	}
}
	
void ADVKATA (void)
/*  I.S.  :  EndKata  =  false;  CC  adalah  karakter  sesudah  karakter  terakhir 
	dari  kata  yg  sudah  diakuisisi  */ 
/*  F.S.  :  Jika  CC  =  MARK,  maka  EndKata  =  true atau  EndKata  =  false,  
	CKata  adalah  kata  terakhir  yang  sudah  diakuisisi; 
	CC  karakter  pertama  sesudah  karakter  terakhir  kata  */ 
{
	//algoritma	
	Ignore_Blank();
	if (!EOP()) {
		SalinKata();
	} else {
		EndKata = true;
	}
}

void  SalinKata (void)
/*  Mengakuisisi  kata,  menyimpan  dalam  CKata  */ 
/*  I.S.  :  CC  adalah  karakter  pertama  dari  kata  */ 
/*  F.S.  :  CKata  berisi  kata  yang  sudah  diakuisisi,  jika  karakternya  melebihi 
	NMax,  sisa  "kata"  dibuang;  CC  =  BLANK  atau  CC  =  MARK;  CC  adalah karakter  sesudah  karakter  terakhir  yang  diakuisisi  */ 
{
	//kamus lokal
	int i =0;
	
	//algoritma
	while (CC != BLANK && !EOP()) {
		CKata.TabKata[i++] = CC;
		ADV();
	}
	CKata.length = i;		
	
	if (CC == EOP() && i<NMax) {
		EndKata = true;
	} else {
		EndKata = false;
	}	
}

	
/*  *****  Operasi  Lain  *****  */   

boolean IsKataSama  (Kata K1, Kata  K2 )
/*  Mengembalikan  true  jika  K1  =  K2;  dua  kata  dikatakan  sama  jika  panjangnya  sama  dan 
	urutan  karakter  yang  menyusun  kata  juga  sama  */ 	
{	
	int i=0;
	if (K1.length == K2.length) {
		while (i<K1.length) {
			if (K1.TabKata[i] != K2.TabKata[i]) return false;
			i++;
		}
	} else return false;
	return true;
}

#endif
