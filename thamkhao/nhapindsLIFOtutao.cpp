#include <stdio.h>
#include<string.h>
struct NHANVIEN {
	char Hoten[100];
	char CMND[10];
	char Chucvu[100];
	char SDT[10];
	char Diachi[100];
};
struct NL{
	NHANVIEN dl;
	NL *tiep;
};

NL *BOSUNG(NL *d, NL *ptu)
{
	if (d==NULL)
		d=ptu;
	else
	{
		ptu->tiep= d;
		d=ptu;
	}
	return d;	
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




void INDS(NL *d)
{
		NL *tg;
		if(d==NULL)
			printf ("Danh sach NULL");
		else	
		{
			tg=d;
			while(tg!= NULL)
			{
				printf ("%20d | %15s | %15s | %20s | %0.9d\n", tg->dl.CMND, tg->dl.Hoten, tg->dl.Chucvu, tg->dl.Diachi, tg->dl.SDT);
				tg= tg->tiep;
			}
		}
}


void TIMKIEM (NL *d, NL *ptu, char cvu[])
{
	NL *tg;
	if(d==NULL)
			printf ("Danh sach NULL");
		else	
		{
			tg=d;
			while(tg!= NULL)
			{
				if(strcmp(cvu,tg->dl.Chucvu)==0)
					printf ("%20d | %15s | %15s | %20s | %0.9d\n", tg->dl.CMND, tg->dl.Hoten, tg->dl.Chucvu, tg->dl.Diachi, tg->dl.SDT);
				tg= tg->tiep;
			}
		}	
}


main()
{
	NL *h,*p;
	char CV[200];
	int N;
	printf (" Nhap vao so luong phan tu :");
	scanf ("%d",&N);
	h=NULL;
	Nhap(h, N);
	INDS(h);
	printf("\nNhap chuc vu can tim : ");
	scanf("%s", &CV);
	TIMKIEM (h,p,CV);
	
	
}
