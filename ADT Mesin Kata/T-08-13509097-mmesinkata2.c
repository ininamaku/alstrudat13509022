/* file  : mainkar.c  */ 
/* driver mesinkar2.*/ 

/* Menuliskan isi pita ke layar  */ 
#include "mesinkar1.h" 
#include "T-08-13509097-mesinkata2.h" 
#include "boolean.h"
#include <stdio.h>
/* Kamus global  */ 

extern char CC; 
extern Kata CKata;
extern boolean EndKata;
Kata coba;

int main() 

{/* Kamus lokal  */ 

/* ALgoritma  : menuliskan isi pita  */ 
	int i;
	printf("awal pita  \n"); 
	STARTKATA();
	do{
		for (i = 0; i<CKata.length; i++) printf("%c",CKata.TabKata[i]);
		printf("\n");
		ADVKATA();
	} while (CKata.length != 0); 
	coba = CKata;
	if (IsKataSama(coba,CKata)) printf("sama\n"); else printf("ga sama\n");
	printf  ("\n... akhir, Bye  \n"); 
	return  0; 
} 
