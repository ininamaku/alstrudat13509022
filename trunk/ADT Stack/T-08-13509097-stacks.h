/*
Nama/NIM : Reinhard Denis Najogie/13509097
Nama file : T-08-13509097-stacks.h
Topik : ADT
Tanggal : 19 Oktober 2010
Deksripsi : ADT Stack
*/

#include "boolean.h"
#ifndef stacks_h
#define stacks_h
#define Nil 0
#define MaxEl 10

typedef int infotype;
typedef int address;

typedef struct
{
	infotype T[MaxEl+1];
	address TOP;
} Stack;

void CreateEmpty(Stack *S);
boolean IsEmpty(Stack S);
boolean IsFull(Stack S);
void Push(Stack *S, infotype X);
void Pop(Stack *S, infotype X);
#endif
