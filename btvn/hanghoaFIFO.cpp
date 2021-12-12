#include <stdio.h>
#include <string.h>
// nhap dslk don theo FIFOs vao truoc ra truoc
struct	HANGHOA{
	char mahh[10];
	char ten[100];
	int sl;
};
struct NL{
	HANGHOA dl;
	NL *tiep;
};


NL *BOSUNG(NL *d, NL *ptu)
{
	NL *tg;
	if (d==NULL)
		d=ptu;
	else{
		tg=d;
		while(tg->tiep!= NULL)
			tg=tg->tiep;
		tg->tiep= ptu;	
	}
	return d;	
}


void Nhap(NL *&d, int n)
{
	NL *p;
	int i;
	for(i=1; i<=n; i++){
		p=new NL;
		fflush(stdin);
		printf(" Nhap ma hang hoa %d: ", i);
		gets(p->dl.mahh);
		fflush(stdin);
		printf(" Ten hang hoa %d: ", i);
		gets(p->dl.ten);
		printf(" So luong hh %d: ", i);
		scanf("%d", &p->dl.sl);
		p->tiep = NULL;
		d=BOSUNG(d,p);
	}
}

void INDS(NL *d)
{
		NL *tg;
		tg=d;
		while(tg!= NULL){
			printf ("%25s | %25s| %d\n", tg->dl.mahh, tg->dl.ten, tg->dl.sl);
			tg= tg->tiep;
		}
}


main()
{
	NL *h;
	int n;
	printf (" Nhap vao so luong hang hoa: ");
	scanf ("%d",&n);
	h=NULL;
	Nhap(h, n);
	INDS(h);
	
}
