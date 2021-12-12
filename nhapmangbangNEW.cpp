#include <stdio.h>
void NhapMang(float a[], int n){
	for(int i=1; i<=n; i++){
		printf("Nhap gia tri a %d: ",i);
		scanf("%f",&a[i]);
	}
}
void Xuat(float a[], int n){
	for(int i=1; i<=n; i++){
		printf("a:= %f \n",a[i]);
	}
}

main(){
	int n;
	char *tk;
	float *ds;
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	ds = new float[n+1];
	
	NhapMang(ds, n);
	 Xuat(ds, n);
}
