#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct Node
{
	int dulieu;
	Node *tiep;
};
void MangRd(int a[],int n)
{
	int i, j, dsach;
	for (i=1;i<=n;i++)
	{
		dsach=1;
		while (dsach==1)
		{
			dsach=0;
			a[i]=1+rand()%n;  // sinh so trong doan tu 1->n
			for (j=1;j<i;j++)
			{
				if (a[i]==a[j]) 
					dsach=1;
			}
		}
	}
} 
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

Node *TaoFIFO(Node *H_d9, int n, int a[])

{
	Node *tg;
	int dem, i;
	dem=1;
	for (i=1;i<=n;i++)
	{
		tg=new(Node);
		tg->dulieu = a[dem];
		dem++;
		tg->tiep=NULL;
		H_d9=BoSungSau(H_d9, tg);
	}
		return H_d9;			
}	

main()
{
	Node *D_d9;
	int n, *ds;
	srand((int)time(0));
	printf("Nhap so: ");
	scanf("%d", &n);
	ds=new int[n+1];
	MangRd(ds, n);
	D_d9=NULL;
	D_d9=TaoFIFO(D_d9, n, ds);
	printf("\nDanh sach lien ket sau khi nhap la:\n");
	InDS(D_d9);	
}

