/*
Nama/NIM : Reinhard Denis Najogie/13509097
Nama file : T-08-13509097-mstackd.c
Topik : ADT
Tanggal : 21 Oktober 2010
Deksripsi : ADT Stack dengan alokasi memori dinamis
*/

#include <stdio.h>
#include <string.h>
#include "T-08-13509097-stackd.h"

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
	
	CreateEmpty(&S,3);
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
	Destruct(&S);
	Push(&S,1);
	PrintStack(S);	
	return 0;
}


