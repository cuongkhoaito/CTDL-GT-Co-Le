#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct Node
{
	char dulieu;	
	Node *tiep;
};
void InDS(Node *H_d9)
{
	Node *p;
	if(H_d9==NULL)
		printf("Danh sach NULL");
	else	
	{
		p=H_d9;
		while(p!=NULL)
		{
			printf("%c-", p->dulieu);
			printf("%d\t", p->dulieu);
			p=p->tiep;
		}	
	}	
}
Node *BoSungSau(Node *H_d9, Node *ptu)
{
	Node *tg;
	if(H_d9==NULL)
		H_d9=ptu;
	else
	{
		tg=H_d9;
		while(tg->tiep!=NULL)
			tg=tg->tiep;
		tg->tiep=ptu;		
	}
	return H_d9;		
}
Node *TaoFIFO(Node *H_d9, int n)

{
	Node *tg;
	char dl[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	do
	{
		tg=new(Node);
		tg->dulieu = dl[rand()% sizeof(dl)];
		printf("%c \t", tg->dulieu);
		tg->tiep=NULL;
		H_d9=BoSungSau(H_d9, tg);
	}while(rand()%n!=0);
	return H_d9;
}	
main()
{
	Node *D_d9;
	int so;
	srand((char)time(NULL));
	printf("Nhap so phan tu can random: ");
	scanf("%d", &so);
	D_d9=NULL;
	D_d9=TaoFIFO(D_d9, so);
	printf("\nDanh sach random:\n");
	InDS(D_d9);	
}
