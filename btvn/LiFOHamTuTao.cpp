#include<stdio.h>
//fifo la vao sau ra truoc
struct VEXE
{
	char mve[5], tennhaxe[20];
	int gia;
};
typedef struct VEXE vx;
struct NL
{	
	vx dl;
	NL *tiep;
};
NL *BSUNG(NL *D, NL *pt)
{
	NL *tg;
	if(D==NULL)
		D = pt;
	else
	{
		tg = D;
		while(tg->tiep !=NULL) // fifo vao truoc ra truoc
			tg = tg->tiep;
		tg->tiep = pt;
	}		
	return D;	
}
void NHAP_DS(NL *&D,int ptu)
{
	NL *p;
	for(int i=1; i<=ptu; i++)
	{
		p = new NL;
		fflush(stdin);
		printf("Nhap ma ve thu %d: ",i);
		gets(p->dl.mve);
		printf("Nhap ten nha xe %d: ",i);
		gets(p->dl.tennhaxe);
		printf("Gia ve: ");
		scanf("%d",&p->dl.gia);
		p->tiep = NULL;
		D = BSUNG(D, p);
	}
}
void IN_DS(NL *D)
{
	NL *tg;
	tg = D;
	while(tg!=NULL)
	{
		printf("\n%10s|%25s|%10d",tg->dl.mve, tg->dl.tennhaxe, tg->dl.gia);
		tg = tg->tiep;	
	}
}
main()
{
	NL *H;
	int n;
	printf("Nhap bao nhieu phan tu: ");
	scanf("%d",&n);
	H = NULL;
	NHAP_DS(H,n);
	IN_DS(H);
}
