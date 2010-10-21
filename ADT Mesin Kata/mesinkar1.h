#define MESINKAR1_H 
#include "boolean.h" 
#ifndef MARK 

#define MARK '.' 
#endif 

void START(void); 
/*I.S. sembarang  */ 
/*F.S. CC adalah karakter pertama pita  */ 
/*	Jika CC==MARK, EOP menyala  (true)  */
/*	Jika CC  != MARK, EOP padam  (false)  */


void ADV(void); /*I.S. CC  != MARK  */ 
/*F.S. CC adalah karakter berikutnya dari CC pada I.S.  */ 
/*	Jika CC==MARK, EOP menyala  (true)  */

boolean EOP(void); 
/* true jika CC  == MARK  */ 


