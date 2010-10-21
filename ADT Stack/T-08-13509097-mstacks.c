/*
Nama/NIM : Reinhard Denis Najogie/13509097
Nama file : T-08-13509097-stacks.c
Topik : ADT
Tanggal : 21 Oktober 2010
Deksripsi : ADT Stack
*/

#include <stdio.h>
#include <string.h>
#include "T-08-13509097-stacks.h"

void PrintStack(Stack S)
{
	int i;
	for(i = 1; i <= S.TOP; i++)
		printf("Stack[%d] = %d\n",i,S.T[i]);
}

int main()
{
	int d;
	char pilihan;
	Stack S;

	CreateEmpty(&S);
	printf("%d %d\n",S.TOP,S.T[S.TOP]);
	PrintStack(S);
	while (!IsFull(S))
	{
		scanf("%c %d",&pilihan,&d);
		if (pilihan =='p')
			Pop(&S,d);
		else if (pilihan == 'h') 
			Push(&S,d);
		PrintStack(S); printf("%d\n",S.TOP);
	}	
		
	return 0;
}


