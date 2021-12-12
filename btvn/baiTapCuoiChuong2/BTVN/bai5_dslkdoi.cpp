#include<stdio.h>
#include<string.h>
//#include <stdlib.h> 
// fifo danh sach lien ket doi
struct SinhVien
{
	char maSV[13], tenSV[50], lop[4];
	float dtb;
};
struct Node
{
	SinhVien dulieu;
	Node *tiep, *truoc;
};
//Node *H_d9, *E_d9;
void InDSSV_D_dungDau(Node *&H_d9)
{
	Node *tg;
	tg=H_d9;
	if(tg==NULL)
		printf("Danh sach NULL");                         
	else	
	{
		while(tg!=NULL)
		{
			printf("\t\t%15s| %25s| %10s| %10.2f\n", tg->dulieu.maSV, tg->dulieu.tenSV, tg->dulieu.lop, tg->dulieu.dtb);
			tg=tg->tiep;
		}
	}	
}
void InDSSV_D_dungCuoi(Node *&E_d9)
{
	Node *tg;
	tg=E_d9;
	if(tg==NULL)
		printf("Danh sach NULL");
	else	
	{
		while(tg!=NULL)
		{
			printf("\t\t%15s| %25s| %10s| %10.2f\n", tg->dulieu.maSV, tg->dulieu.tenSV, tg->dulieu.lop, tg->dulieu.dtb);
			tg=tg->truoc;
		}
	}	
}
void BoSungSau(Node *&H_d9, Node *&E_d9, Node *ptu)
{
	if(H_d9==NULL)
	{
		H_d9=ptu;
		E_d9=ptu;
	}	
	else
	{
		E_d9->tiep=ptu; // 
		ptu->truoc=E_d9;
		E_d9=ptu;		// tra ve duoi, nhay ve duoi
						//
	}	
}
void NhapSV(Node *&H_d9, Node *&E_d9, int n)
{
	int i;
	Node *ptu;
	H_d9=NULL;
	E_d9=NULL;
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
		BoSungSau(H_d9, E_d9, ptu);
	}	
	H_d9->truoc=NULL;
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



Node *CHEN(Node *D, Node *p)// chen day da sap xep
{
	Node *tg, *trc;
	tg = D;
	while (tg != NULL && tg->dulieu.dtb < p->dulieu.dtb)
	{
		trc = tg;
		tg = tg->tiep;
	}
	if (tg == D)
		D = p;
	else 
		trc->tiep = p;
	p->tiep = tg;
	return D;	
}

void TachDSSV(Node *D,Node *&D1, Node *&D2)
{ 
	Node *tg1, *tg2;
	if(D == NULL)
	{
		D1 = NULL;
		D2 = NULL;
	}
	else  
	{
		tg1 = D;
   		while(tg1 != NULL)
		{
   			tg2 = new Node;
   			tg2->dulieu = tg1->dulieu;
       		tg2->tiep = NULL;
       		if(tg2->dulieu.dtb < 5)
       			D1 = CHEN(D1,tg2);
       		else
       			D2 = CHEN(D2,tg2);
			tg1=tg1->tiep;
 		}
 	}
}

/*
void SapXepSV(Node *&H_d9)
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
void TachDSSV(Node *&H_d9,  Node *&H1_d9, Node *&H2_d9)
{
	Node *tg, *p, *E1_d1, *E2_d2;
	tg=H_d9;
	E1_d1=NULL; 
	E2_d2=NULL;
	while (tg!=NULL)
	{
		p= new Node;
		p->dulieu=tg->dulieu;
		p->tiep=NULL;

		
		if (tg->dulieu.dtb <5)
		{	
			BoSungSau(H1_d9, E1_d1, p);
			p->tiep=NULL;
			H1_d9->truoc=NULL;
		}		
		else 
		{	
			BoSungSau(H2_d9, E2_d2, p); // null
			p->tiep=NULL;
			H2_d9->truoc=NULL;
		}	
		tg=tg->tiep;
	}
	SapXepSV(H1_d9);
	SapXepSV(H2_d9);								
}
*/
main()
{
	Node *D_d9, *C_d9, *D1_d9, *D2_d9;
	int so;
	char lop[4];
	D1_d9=NULL;
	D2_d9=NULL;
	printf("Nhap so sinh vien: ");
	scanf("%d", &so);
	printf("_____________________________***_____________________________");
	NhapSV(D_d9, C_d9, so);
	printf("\n\t\tDanh sach sinh vien khi dung o dau la:\n");
	InDSSV_D_dungDau(D_d9);
	printf("\n\t\tDanh sach sinh vien khi dung o cuoi la:\n");
	InDSSV_D_dungCuoi(C_d9);
	printf("\n-------------------------------------------------------------\n");
	fflush(stdin);
	printf("\nNhap lop can xoa: \n");
	gets(lop);
	while(TimKiemSV(D_d9, lop)!=NULL)
		D_d9=XoaSV(D_d9, lop);
	printf("\nDanh sach sinh vien sau khi xoa la: \n");
	InDSSV_D_dungDau(D_d9);
	TachDSSV(D_d9,  D1_d9, D2_d9);
	printf("\nDanh sach sinh vien co DTB<5 la:\n");
	InDSSV_D_dungDau(D1_d9);
	printf("\nDanh sach sinh vien co DTB>=5 la:\n");
	InDSSV_D_dungDau(D2_d9);
}

