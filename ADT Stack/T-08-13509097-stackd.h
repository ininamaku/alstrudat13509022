/*
Nama/NIM : Reinhard Denis Najogie/13509097
Nama file : T-08-13509097-stackd.h
Topik : ADT
Tanggal : 21 Oktober 2010
Deksripsi : ADT Stack dengan alokasi memori dinamis
*/

#include "boolean.h"
#ifndef stackd_h
#define stackd_h
#define Nil 0
typedef int infotype;
typedef int address;
typedef struct
{
	infotype *T;
	address TOP;
	int Size;
} Stack;
void CreateEmpty(Stack *S, int Size);
void Destruct(Stack *S);
boolean IsEmpty(Stack S);
boolean IsFull(Stack S);
void Push(Stack *S, infotype X);
void Pop(Stack *S, infotype X);
#endif
