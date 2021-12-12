#include <stdio.h>
#include <string.h>
int i;
struct SINHVIEN{
	char ten[50],msv[15], lop[10];
	float dtb;
};
void Nhap(SINHVIEN sv[], int n){
	for( i=1; i<=n; i++){
		printf("Ho ten SV thu %d: ",i);
		fflush(stdin);
		gets(sv[i].ten);
		printf("Ma sinh vien: ");
		gets(sv[i].msv);
		printf("Lop: ");
		gets(sv[i].lop);
		printf("Diem trung binh: ");
		scanf("%f",&sv[i].dtb);		
	}
}
void In(SINHVIEN sv[], int n){
		printf("\n%24s|%20s|%10s|%s","Ho ten","Ma sinh vien","Lop","DTB");
	for( i=1; i<=n; i++){
		printf("\n%25s|%20s|%10s|%0.2f",sv[i].ten,sv[i].msv,sv[i].lop,sv[i].dtb);
	}
}
int TimLop(SINHVIEN sv[], int n, char tlop[]){
	for(i=1; i<=n; i++){
		if(strcmp(tlop,sv[i].lop)==0)
			return i;
	}
	return 0;
}
// Xóa-- nhap vao lop can xoa-> xoa cac sv trong lop do
void Xoalop(SINHVIEN sv[], int &n, char xlop[]){// note: &n
	//&n tham chieu de n-- no luu lai, ra khoi ham no van luu lai
	int vt;
	while(TimLop( sv, n, xlop)!=0){
		vt=TimLop( sv, n, xlop);
		for(i=vt; i<=n-1; i++){
			sv[i]=sv[i+1];
		}
		n--;
	}
}

void SapXepDTB(SINHVIEN sv[], int &n){
	SINHVIEN tg;
	int j;
	for(i=1; i<=n-1; i++){
		for(j=i+1; j<=n;j++){
			if(sv[i].dtb>sv[j].dtb)
			{
				tg=sv[i];
				sv[i]=sv[j];
				sv[j]= tg;
			}
		}
	}
}
int TimVtriDiemDSX(SINHVIEN sv[], int n,SINHVIEN chen){
	int d=0;
	for(i=1; i<=n; i++){
		if(chen.dtb > sv[i].dtb)
			d++;
		if(d==n)
			return n+1;
	}
	for(i=1; i<=n; i++){
		if(chen.dtb < sv[i].dtb)
			return i;
			
	}
	return 1;
}

// chen dau vao phai la co ds chen, nhu vay la sai
//void ChenInfo(SINHVIEN sv[], int &n){
//	int vt;
//	SINHVIEN chen[1];
//	printf("\nNhap ten sinh vien muon chen: ");
//	fflush(stdin);
//	gets(chen[1].ten);
//	printf("Ma sinh vien: ");
//	gets(chen[1].msv);
//	printf("Lop: ");
//	gets(chen[1].lop);
//	printf("Diem trung binh: ");
//	scanf("%f",&chen[1].dtb);
//	vt=TimVtriDiemDSX(sv, n, chen);
//	for(i=n; i>=vt; i--){
//		sv[i+1]=sv[i];
//	}
//	sv[vt]=chen[1];
//	n++;
//}
SINHVIEN NHAP_CHEN(SINHVIEN &chen){
	printf("\nNhap ten sinh vien muon chen: ");
	fflush(stdin);
	gets(chen.ten);
	printf("Ma sinh vien: ");
	gets(chen.msv);
	printf("Lop: ");
	gets(chen.lop);
	printf("Diem trung binh: ");
	scanf("%f",&chen.dtb);
	return chen;
}
void ChenInfo(SINHVIEN sv[], int &n, SINHVIEN chen){ //  &n de luu gia tri so ptu chen tang them
	int vt=TimVtriDiemDSX(sv, n, chen);
	for(i=n; i>=vt; i--){
		sv[i+1]=sv[i];
	}
	sv[vt]=chen;
	n++;
}
//int KtraSX_DTB(SINHVIEN sv[], int n){
//	int dt=0, dg=0;
//	for(i=1; i<=n-1; i++){
//		if(sv[i].dtb<=sv[i+1].dtb)
//			dt++;
//		if(sv[i].dtb>=sv[i+1].dtb)
//			dg++;
//	}
//	if(dt==n-1)
//		return 1;
//	if(dg==n-1)
//		return -1;
//	else
//		return 0;
//}

int KtraSX_DTB(SINHVIEN sv[], int n){
	int dt=0, dg=0;
	if(dt==0 || dg==0){
		for(i=1; i<=n-1; i++){
			if(sv[i].dtb<sv[i+1].dtb)
				dt++;
			if(sv[i].dtb>sv[i+1].dtb)
				dg++;
		}
		if(dt==n-1)
			return 1;
		if(dg==n-1)
			return -1;
	};
	return 0;
}
int main(){
	int n;
	SINHVIEN *ds,chen;
	char tim[10],xoa[10];
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	ds = new SINHVIEN[n+1];
	Nhap( ds, n);
	In(ds ,  n);
	SapXepDTB(ds, n);
	printf("\nSau khi sap xep\n");
	In(ds, n);
//	chen info
	NHAP_CHEN(chen);
	ChenInfo(ds, n,chen);
	In(ds, n);
	if(KtraSX_DTB(ds, n)==1)
		printf("\nDS da sap xep tang theo DTB ");
	if(KtraSX_DTB(ds, n)==-1)
		printf("\nDS da sap xep giam theo DTB");
	if(KtraSX_DTB(ds, n)==0)
		printf("\nDs chua sap theo DTB");
	return 0;
}

