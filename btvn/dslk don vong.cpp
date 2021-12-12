#include <stdio.h>
struct NL{
	int dl;
	NL *tiep;
};

NL *BoSung(NL *D, NL *ptu)
{
	NL *tg;
	if (D==NULL)
		D=ptu;
	else
	{
		tg=D;
		while(tg->tiep!= NULL){
			tg=tg->tiep;
		}
		tg->tiep= ptu;
		
	}
	return D;	
}

void Duyet(NL *D){
	NL *tg;
	tg= D;
	do{
		printf("%d ",tg->dl);
		tg= tg->tiep;
	}while(tg != D);
}

void Tao(NL *&D){
	NL *p;
	int n;
	printf("Nhap so ptu: ");
	scanf("%d", &n);
	for (int i= 1; i<=n; i++ ){
		p = new NL;
		printf("Nhap ptu thu %d: ",i);
		scanf("%d",&p->dl);
		p->tiep = NULL;
		D= BoSung(D, p);
	}
	tg->tiep =D;
}

main()
{
	NL *H;
	int n;
	H=NULL;		
	Tao(H);
	Duyet(H);	
}
