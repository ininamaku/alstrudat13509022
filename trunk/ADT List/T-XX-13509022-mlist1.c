/*
Nama/NIM : Muhammad Adinata/13509022.
Nama file : T-XX-13509022-mlist1.c
Topik : List
Tanggal : 31 Oktober 2010
Deksripsi : Driver list berkait linier
*/

#include <stdio.h>
#include "T-XX-13509022-list1.h"

int main() {
	List L,L1,L2;
	CreateList(&L);
	int n = 1;
	address tmp,tmp2,tmp3;
	while (n > 0) {
		scanf("%d",&n);
		InsVFirst(&L,n);
		if (Search(L, 10) != Nil) printf("10 ada di list\n"); else printf("10 tidak ada di list\n");
		SearchPrec(L,10, &tmp);
		if (tmp != Nil) printf("nilai sebelum 10 adalah %d\n", info(tmp));
		Printinfo(L);
		printf("\n");
	}
	tmp = Alokasi(999);
	tmp2 = Alokasi(-1991);
	tmp3 = Alokasi(10000);
	InsertFirst(&L, tmp);
	Printinfo(L);
	InsertAfter(&L, tmp2, tmp);
	Printinfo(L);
	InsertLast(&L, tmp3);
	Printinfo(L);
	DelFirst(&L,&tmp);
	Printinfo(L);
	printf("%d\n", info(tmp));
	DelP(&L, 10000);
	Printinfo(L);
	DelLast(&L, &tmp);
	Printinfo(L); printf("%d\n", info(tmp));
	DelAfter(&L, &tmp,tmp2);
	Printinfo(L); printf("%d\n", info(tmp));
	printf("%d\n", NbElmt(L));
	printf("%d %d\n", Max(L), info(AdrMax(L)));
	printf("%d %d\n", Min(L), info(AdrMin(L)));
	printf("%lf\n",Average(L));
	CpAlokList(L,&L1);
	DelAll(&L);
	CopyList(&L,&L2);
	Printinfo(L);
	Printinfo(L1);
	Printinfo(L2);
	L = FCopyList(L1);
	Konkat(L,L1,&L2);
	Printinfo(L2);
	Konkat1(&L,&L1,&L2);
	Printinfo(L);
	Printinfo(L1);
	Printinfo(L2);
	DelLast(&L2,&tmp);
	PecahList(&L,&L1,L2);
	Printinfo(L);
	Printinfo(L1);
	Printinfo(L2);
	
	return 0;
}
