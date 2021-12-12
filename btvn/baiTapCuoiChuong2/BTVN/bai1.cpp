#include<stdio.h>
struct Node
{
	int dulieu;
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
		while(p!=NULL  && p->dulieu!=0)
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
Node *TaoFIFO(Node *H_d9)

{
	Node *tg;
	do
	{
		tg=new(Node);
		scanf("%d", &tg->dulieu);
		tg->tiep=NULL;
		H_d9=BoSungSau(H_d9, tg);
	}while(tg->dulieu!=0);
	return H_d9;
}	

main()
{
	Node *D_d9;
	D_d9=NULL;
	D_d9=TaoFIFO(D_d9);
	printf("\nDanh sach FiFo:\n");
	InDS(D_d9);	
}

