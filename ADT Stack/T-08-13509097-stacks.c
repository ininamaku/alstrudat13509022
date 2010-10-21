/*
Nama/NIM : Reinhard Denis Najogie/13509097
Nama file : T-08-13509097-stacks.c
Topik : ADT
Tanggal : 21 Oktober 2010
Deksripsi : ADT Stack
*/

#include <stdio.h>
#include "T-08-13509097-stacks.h"
#define Nil 0

void CreateEmpty(Stack *S)
{
	(*S).TOP = 0;
	int i;
	for(i=0; i <= MaxEl; i++)
		(*S).T[i] = Nil;
}

boolean IsEmpty(Stack S)
{
	if (S.TOP == Nil)
		return true;
	return false;
}

boolean IsFull(Stack S)
{
	if (S.TOP == MaxEl)
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
