/* file  : mainkar.c  */ 
/* driver mesinkar2.*/ 

/* Menuliskan isi pita ke layar  */ 
#include "mesinkar1.h" 
#include "mesinkata3.h" 
#include "boolean.h"
#include <stdio.h>
/* Kamus global  */ 

extern char CC; 
extern Kata CKata;
extern boolean EndKata;
Kata KataWHILE;
int NWHILE;

int main() 

{/* Kamus lokal  */ 

/* ALgoritma  : menuliskan isi pita  */ 
	KataWHILE.TabKata[0] = 'W';
	KataWHILE.TabKata[1] = 'H';
	KataWHILE.TabKata[2] = 'I';
	KataWHILE.TabKata[3] = 'L';
	KataWHILE.TabKata[4] = 'E';
	KataWHILE.length = 5;
	
	INITAKSES();
	/*
	int i;
	do{
		for (i = 0; i<CKata.length; i++) printf("%c",CKata.TabKata[i]);
		printf("\n");
		ADVKATA();
	} while (CKata.length != 0); 
	*/
	NWHILE = 0;
	while (!EOP()) {
		ADVKATA();
		if (IsKataSama(KataWHILE, CKata)) NWHILE +=1;
	}
	printf("%d\n", NWHILE);
	return  0; 
} 
