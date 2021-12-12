#include<stdio.h>
struct DaThuc
{
	int coSo, heSo;
};
struct Node
{
	DaThuc dulieu;
	Node *tiep;
};
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
Node *NhapDT(Node *H_d9, int n)
{
	int i;
	Node *ptu;
	for(i=1; i<=n; i++)
	{
		ptu=new Node;
		printf("\nNhap don thuc thu %d: \n", i);
		printf("\nHe so: ");
		scanf("%d", &ptu->dulieu.heSo);
		printf("\nSo mu: ");
		scanf("%d", &ptu->dulieu.coSo);
		printf("\n---------------------------------------------------------\n");
		ptu->tiep=NULL;
		H_d9=BoSungSau(H_d9, ptu);
	}	
	return H_d9;
}
void InDT(Node *H_d9)
{
	Node *tg;
	if(H_d9==NULL)
		printf("Danh sach NULL");
	else	
	{
		tg=H_d9;
		while(tg!=NULL)
		{
			printf("%dx^%d+ ", tg->dulieu.heSo, tg->dulieu.coSo);
			tg=tg->tiep;
		}
	}	
}
void InCoSoChan(Node *H_d9)
{
	Node *tg;
	if (H_d9==NULL)
		printf("Danh sach NULL ");
	else 
	{
		tg=H_d9;
		while (tg!=NULL)
		{
			if (tg->dulieu.heSo%2==0)
				printf("%dx^%d ", tg->dulieu.heSo, tg->dulieu.coSo);
			tg=tg->tiep;
		}			
	}	
}
main()
{
	Node *D_d9;
	int n;
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	D_d9=NULL;
	D_d9=NhapDT(D_d9, n);
	InDT(D_d9);
	printf("\n phan tu co co so chan : \n");
	InCoSoChan(D_d9);
}
