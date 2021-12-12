#include <stdio.h>
int i;
void Nhap(int a[], int n){
	for( i=1; i<=n; i++){
		printf("Nhap phan tu thu %d: ",i);
		scanf("%d",&a[i]);
	}
}
void In(int a[], int n){
	for( i=1; i<=n; i++){
		printf(" %d ",a[i]);
	}
}
int KtraTangGiam(int a[], int n){
	int dt=0, dg=0;
	i=0;
//	for(i=1; i<=n; i++){
//		if(a[i]<=a[i+1])
//			dt++;
//		if(a[i]>=a[i+1])
//			dg++;
//	}
	while((dt==0 && i<n-1) || (dg==0 && i<n-1)){// toi i<n-1 or i=n-2
		i++;								// vi dong tren i=n-1, xuong gap i++ tang lai thanh n, nen de dk i<n-1, de cong 1 thanh i<n hay i<=n-1
		if(a[i]<=a[i+1])
			dt++;
		if(a[i]>=a[i+1])
			dg++;
	};
	if(dt==n-1)
		return 1;
	if(dg==n-1)
		return -1;
	return 0;	
}
main(){
	int *ds, n;
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	ds = new int[n+1];
	Nhap(ds, n);
	In(ds, n);
	if(KtraTangGiam(ds, n)==1)
		printf("Tang ");
	if(KtraTangGiam(ds, n)==-1)
		printf("Giam ");
	if(KtraTangGiam(ds, n)==0)
		printf(" Khong tang giam OK");
}
