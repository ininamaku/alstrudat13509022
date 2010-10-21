/* file  : mainkar.c  */ 
/* driver mesinkar1.*/ 

/* Menuliskan isi pita ke layar  */ 
#include "mesinkar1.h" 
#include "mesinkata1.h" 
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
	printf("awal pita  \n"); 
	STARTKATA();
	coba = CKata;
	int i =0;
	while (!EndKata) {
		for (i = 0; i<CKata.length; i++) printf("%c",CKata.TabKata[i]);
		printf("\n");
		ADVKATA();
	}
	if (IsKataSama(coba,CKata)) printf("sama\n"); else printf("ga sama\n");
	printf  ("\n... akhir, Bye  \n"); 
	return  0; 
} 
