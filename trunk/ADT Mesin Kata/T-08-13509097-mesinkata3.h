#define mesinkata2_H
#ifndef BLANK 

#define BLANK ' ' 
#endif
#include "mesinkar1.h"
#include "boolean.h"

#define NMax 50

typedef struct {
	char TabKata[NMax];
	int length;
}Kata;
/*  TabKata  adalah  tempat  penampung/container  kata, 
	Length  menyatakan  panjangnya  kata  */ 
	
/*  *****  Definisi  State  Mesin  Kata  *****  */

 //CKata  :  Kata

/*  *****  Primitif-Primitif  Mesin  Kata  *****  */ 
/*  kata  yang  sudah  diakuisisi  dan  akan  diproses  */ 
	

void Ignore_Blank(void);

/*  Mengabaikan  satu  atau  beberapa  BLANK  */ 
/*  I.S.  :  CC  sembarang  */ 
/*  F.S.  :  CC  ?  BLANK  atau  CC  =  MARK  */ 

void INITAKSES(void);
/*	Mengabaikan satu atau beberapa BLANK pada awal pita */
/*	I.S.	: CC sembarang
	F.S.	: CC = MARK; atau CC = karakter pertama dari kata yang akan diakuisisi */

	
void ADVKATA (void);
/*  I.S.  :  EndKata  =  false;  CC  adalah  karakter  sesudah  karakter  terakhir 
	dari  kata  yg  sudah  diakuisisi  */ 
/*  F.S.  :  Jika  CC  =  MARK,  maka  EndKata  =  true atau  EndKata  =  false,  
	CKata  adalah  kata  terakhir  yang  sudah  diakuisisi; 
	CC  karakter  pertama  sesudah  karakter  terakhir  kata  */ 

void  SalinKata (void);

/*  Mengakuisisi  kata,  menyimpan  dalam  CKata  */ /*  I.S.  :  CC  adalah  karakter  pertama  dari  kata  */ 
/*  F.S.  :  CKata  berisi  kata  yang  sudah  diakuisisi,  jika  karakternya  melebihi 
	NMax,  sisa  "kata"  dibuang;  CC  =  BLANK  atau  CC  =  MARK;  CC  adalah karakter  sesudah  karakter  terakhir  yang  diakuisisi  */ 
	
/*  *****  Operasi  Lain  *****  */   

boolean IsKataSama  (Kata K1, Kata  K2 );
/*  Mengembalikan  true  jika  K1  =  K2;  dua  kata  dikatakan  sama  jika  panjangnya  sama  dan 
	urutan  karakter  yang  menyusun  kata  juga  sama  */ 	


