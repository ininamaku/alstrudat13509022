/*
Nama/NIM : Reinhard Denis Najogie/13509097
Nama file : T-08-13509097-stackd.c
Topik : ADT
Tanggal : 21 Oktober 2010
Deksripsi : ADT Stack dengan alokasi memori dinamis
*/

#include <stdio.h>
#include <stdlib.h>
#include "T-08-13509097-stackd.h"
#define Nil 0

void CreateEmpty(Stack *S, int Size)
{
	(*S).T = (int*)malloc(Size*sizeof(int));
	(*S).Size = Size;
	(*S).TOP = 0;
	int i;
	for(i = 0; i <= Size; i++)
		(*S).T[i] = Nil;
}

void Destruct(Stack *S)
{
	(*S).TOP = 0;
	free(&(*S));
}

boolean IsEmpty(Stack S)
{
	if (S.TOP == Nil)
		return true;
	return false;
}

boolean IsFull(Stack S)
{
	if (S.TOP == S.Size)
		return true;
	return false;
}

void Push(Stack *S, infotype X)
{
	(*S).TOP++;
	(*S).T[(*S).TOP] = X;
}

void Pop(Stack *S, infotype X)
{
	(*S).T[(*S).TOP] = Nil;
	(*S).TOP--;
}
