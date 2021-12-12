#include <stdio.h>
#include <string.h>
//#include <conio.h>
//#include <stdlib.h>
 struct SINHVIEN {
	char MaSV[15],TenSV[25],Lop[10];
	float dtb;
};

void NHAPSV( SINHVIEN sv[], int n){
	for(int i=1; i<=n; i++){
		fflush(stdin);
		printf("Ten SV %d: ",i);
		gets(sv[i].TenSV);
		printf("Ma sinh vien: ");
		gets(sv[i].MaSV);
		printf("Lop: ");
		gets(sv[i].Lop);
		printf("Diem trung binh : ");
		scanf("%f",&sv[i].dtb);
	}
}	
void IN(SINHVIEN sv[], int n){
	
	for (int i=1; i<=n; i++){
		printf("%25s|%15s|10s|%0.2f\n",sv[i].TenSV,sv[i].MaSV,sv[i].Lop,sv[i].dtb);
	}
}

void TIM_MSV(SINHVIEN sv[], int n) {
	char msv[15];
	int dem=0;
	printf("Nhap ma sinh vien tim kiem : ");
	scanf("%s",msv);
	for(int i=1; i<=n; i++){
		if(strcmp(msv,sv[i].MaSV) == 0){
			dem++;
		}							
	}
	if(dem!=0)
		printf("Co sinh vien trong danh sach ");
	else
		printf("Khong co ");
}
main(){
	int n;
	SINHVIEN *ssv;
	printf("Nhap so sinh vien: ");
	scanf("%d",&n); 
	ssv = new SINHVIEN[n+1];	
	NHAPSV(ssv, n);	
//	IN(ssv,  n);
	TIM_MSV(ssv, n);
}
