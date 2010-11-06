/*
Nama/NIM : Muhammad Adinata/13509022.
Nama file : T-XX-13509022-mlist1.c
Topik : List
Tanggal : 31 Oktober 2010
Deksripsi : Driver list berkait linier
*/

#include <stdio.h>
#include "T-XX-13509022-list1.h"
#define DEBUG printf("OK\n")
int main() {
	List L;
	CreateList(&L);
	int n;
	address tmp;
	while (1) {
		scanf("%d",&n);
		InsVFirst(&L,n);
		if (Search(L, 10) != Nil) printf("10 ada di list\n"); else printf("10 tidak ada di list\n");
		DEBUG;
		SearchPrec(L,10, &tmp);
		if (tmp != Nil) printf("nilai sebelum 10 adalah %d\n", info(tmp));
		scanf("%d",&n);
		InsVFirst(&L,n);
		tmp = First(L);
		DelVLast(&L,&n);
		while (tmp!=Nil) {
			printf("%d ",info(tmp));
			tmp = next(tmp);
		}
		printf("\n");
	}
	return 0;
}
