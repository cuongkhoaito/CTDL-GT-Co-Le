#include <stdio.h>
#include <string.h>
// nhap dslk don theo lIFO vao truoc ra truoc
// in theo dieu kien 
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
		ptu->tiep =d;
		d= ptu;	
	}
	return d;	
}


void nhap(NL *&d, int n)
{
	NL *p;
	int i;
	for(i=1; i<=n; i++)
	{
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

void inDS(NL *d)
{
		NL *tg;
		tg=d;
		while(tg!= NULL){
			printf ("%25s | %25s| %d\n", tg->dl.mahh, tg->dl.ten, tg->dl.sl);
			tg= tg->tiep;
		}
}

NL *timKiem(NL *d, char mahang[]){
	NL *tg;
	tg =d;
	while(tg!=NULL){
		if(strcmp(tg->dl.mahh,mahang)==0){
			return tg;
		}
		tg=tg->tiep;
	}
	return tg;
}

// im ham tim kiem tai tg->tiep  do
void inTheoDK(NL *d, char mahang[]){
	NL *tg=d;
	tg=timKiem(d,mahang);
	if (timKiem(d,mahang)!=NULL)
		printf ("%25s | %25s| %d\n", tg->dl.mahh, tg->dl.ten, tg->dl.sl);
	else
		printf("Khong co trong ds");
}

main()
{
	NL *h,*p;
	int N;
	char timMHH[10];
	printf (" Nhap vao so luong hang hoa: ");
	scanf ("%d",&N);
	h=NULL;
	nhap(h, N);
	inDS(h);
	printf("Nhap ma hang hoa muon tim: ");
	fflush(stdin);
	scanf("%s",&timMHH);
	inTheoDK(h, timMHH);
	
	
	
	
}
