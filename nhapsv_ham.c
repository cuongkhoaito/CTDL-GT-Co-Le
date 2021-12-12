#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct SINHVIEN {
	char MaSV[15],TenSv[25],Lop[10];
	float dtb;
};

void NHAPSV( SINHVIEN sv[], int n){
	for(int i=1; i<=n; i++){
		printf("Ten SV %d",sv[i]);
		gets(sv[i].TenSV);
	}
}
	
main(){
	int n;
	SINHVIEN *ssv;
	printf("Nhap so sinh vien: ");
	scanf("%d",&n); 
	ssv = new SINHVIEN [n+1];
	NHAPSV(ssv, n);	
}
