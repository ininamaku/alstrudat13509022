/* file  : mainkar.c  */ 
/* driver mesinkar1.*/ 

/* Menuliskan isi pita ke layar  */ 
#include "mesinkar1.h" 
#include "boolean.h"
#include <stdio.h>
/* Kamus global  */ 

extern char CC; 
int main() 

{/* Kamus lokal  */ 

/* ALgoritma  : menuliskan isi pita  */ 
	printf("awal pita  \n"); 
	START(); 
	while  (!EOP())  { 
		printf("%c",CC); 
		ADV  (); 
	} 
	printf  ("\n... akhir, Bye  \n"); 
	return  0; 
} 
