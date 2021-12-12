#include<stdio.h>
#include<string.h>
#include <stdlib.h>
struct SinhVien
{
	char maSV[13], tenSV[50], lop[4];
	float dtb;
};
struct Node
{
	SinhVien dulieu;
	Node *tiep;
};
void InDSSV(Node *H_d9)
{
	Node *tg;
	if(H_d9==NULL)
		printf("Danh sach NULL");
	else	
	{
		tg=H_d9;
		while(tg!=NULL)
		{
			printf("\t\t%15s| %25s| %10s| %10.2f\n", tg->dulieu.maSV, tg->dulieu.tenSV, tg->dulieu.lop, tg->dulieu.dtb);
			tg=tg->tiep;
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
Node *NhapSV(Node *H_d9, int n)
{
	int i;
	Node *ptu;
	for(i=1; i<=n; i++)
	{
		fflush(stdin);
		ptu=new Node;
		printf("\nNhap thong tin sinh vien thu %d: \n", i);
		printf("\nNhap ma sinh vien: ");
		gets(ptu->dulieu.maSV);
		printf("Ten sinh vien: ");
		gets(ptu->dulieu.tenSV);
		printf("Lop: ");
		gets(ptu->dulieu.lop);
		fflush(stdin);
		printf("Diem trung binh: ");
		scanf("%f", &ptu->dulieu.dtb);
		printf("\n---------------------------------------------------------\n");
		ptu->tiep=NULL;
		H_d9=BoSungSau(H_d9, ptu);
	}	
	return H_d9;
}	
Node *TimKiemSV(Node *H_d9, char lop[])
{
	Node *tg;
	tg = H_d9;
	while (tg!=NULL)
	{
		if (strcmpi(tg->dulieu.lop, lop) == 0)
			return tg;
		tg = tg->tiep;
	}
	return NULL;
}
Node *XoaSV(Node *H_d9, char lop[])
{
	Node *tg, *p;
	p = TimKiemSV(H_d9, lop);
	if (p==H_d9)
	{
		H_d9 = H_d9->tiep;
		p->tiep = NULL;
	}
	else
	{
		tg = H_d9;
		while (tg->tiep!= p)
			tg = tg->tiep;
		tg->tiep = p->tiep;
		p->tiep = NULL;
	}
	return H_d9;
}
void SapXepSV(Node *H_d9)
{
	Node *tg, *p;
 	p = H_d9;
 	float temp;
 	while(p->tiep!=NULL){
 		tg=p->tiep;
 	while(tg!=NULL){
 			if (p->dulieu.dtb > tg->dulieu.dtb){
 				temp = p->dulieu.dtb;
 				p->dulieu.dtb = tg->dulieu.dtb;
 				tg->dulieu.dtb = temp;
			}
			tg = tg->tiep;
		}
		p=p->tiep;
	}
}
void TachDSSV(Node *H_d9, Node *&H1_d9, Node *&H2_d9)
{
	Node *tg, *p;
	tg=H_d9;
	while (tg!=NULL)
	{
		p= new Node;
		p->dulieu=tg->dulieu;
		p->tiep=NULL;
		
		if (tg->dulieu.dtb <5)	
			H1_d9=BoSungSau(H1_d9, p);	
		else 
			H2_d9=BoSungSau(H2_d9, p);	
		tg=tg->tiep;
	}
	SapXepSV(H1_d9);
	SapXepSV(H2_d9);								
}
main()
{
	Node *D_d9, *D1_d9, *D2_d9;
	int so;
	char lop[4];
	D_d9=NULL;
	D1_d9=NULL;
	D2_d9=NULL;
	printf("Nhap so sinh vien: ");
	scanf("%d", &so);
	printf("_____________________________***_____________________________");
	D_d9=NhapSV(D_d9,so);
	printf("\n\t\tDanh sach sinh vien sau khi nhap la:\n");
	InDSSV(D_d9);
	printf("\n-------------------------------------------------------------\n");
	fflush(stdin);
	printf("\nNhap lop can xoa: \n");
	gets(lop);
	while(TimKiemSV(D_d9, lop)!=NULL)
		D_d9=XoaSV(D_d9, lop);
	printf("\nDanh sach sinh vien sau khi xoa la: \n");
	InDSSV(D_d9);
	TachDSSV(D_d9, D1_d9, D2_d9);
	printf("\nDanh sach sinh vien co DTB<5 la:\n");
	InDSSV(D1_d9);
	printf("\nDanh sach sinh vien co DTB>=5 la:\n");
	InDSSV(D2_d9);
}

