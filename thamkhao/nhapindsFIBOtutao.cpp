#include <stdio.h>
struct NHANVIEN {
	char Hoten[100];
	int CMND;
	char Chucvu[100];
	int SDT;
	char Diachi[100];
};
struct NL{
	NHANVIEN dl;
	NL *tiep;
};

NL *BOSUNG(NL *d, NL *ptu)
{
	NL *tg;
	if (d==NULL)
		d=ptu;
	else
	{
		tg=d;
		while(tg->tiep!= NULL)
			tg=tg->tiep;
		tg->tiep= ptu;	
	}
	return d;	
}
void INDS(NL *d, NL *ptu)
{
		NL *tg;
		tg=d;
		while(tg!= NULL)
		{
		printf ("%25d | %25s | %20s | %30s | %d\n", tg->dl.CMND, tg->dl.Hoten, tg->dl.Chucvu, tg->dl.Diachi, tg->dl.SDT);
		tg= tg->tiep;
		}
}

void Nhap(NL *&d, int n)
{
	NL *p;
	int i;
	for(i=1; i<=n; i++)
	{
		p=new NL;
		fflush(stdin);
		printf("\nNhap CMND : ", i);
		scanf("%d", &p->dl.CMND);
		fflush(stdin);
		printf("\nNhap ho ten nv: ", i);
		scanf("%s", &p->dl.Hoten);
		printf("\nNhap chuc vu : ", i);
		scanf("%s", &p->dl.Chucvu);
		printf("\nNhap dia chi : ", i);
		scanf("%s", &p->dl.Diachi);
		printf("\nNhap SDT : ", i);
		scanf("%d", &p->dl.SDT);
		p->tiep = NULL;
		d=BOSUNG(d,p);
	}
}
main()
{
	NL *h,*p;
	int N;
	
	printf (" Nhap vao so luong phan tu :");
	scanf ("%d",&N);
	h=NULL;
	Nhap(h, N);
	INDS(h,p);
	
}
