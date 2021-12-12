#include <stdio.h>
#define max 100
void nhapMaTran(int a[max][max], int n){
//	int a[cot][hang];
// n hang 
// m cot
	for( int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			printf("Nhap a[%d][%d]: ",i,j);
			scanf("%d",&a[i][j]);			
		}
	}
}

void in(int a[max][max], int n){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
}


int kiemTraChanChia5(int so){
	if((so%2 ==0) && (so%5 == 0)){
		return 1;
	}
	return 0;
}

int demChanChia5(int a[max][max], int n){
	int d=0;
	for(int i=1; i<=n; i++){		
		for(int j=1; j<=n; j++){
			if(kiemTraChanChia5(a[i][j])==1){
				d++;
			}				
		}
	}
	return d;
}


void nhapMang(int a[max][max], int c[], int n){
	for(int i=1; i<=n; i++){		
		for(int j=1; j<=n; j++){
			if(kiemTraChanChia5(a[i][j])==1){
				c[i]=a[i][j];
			}
			else
				c[i]=0;	
					
		}
		printf("%d",c[i]);
	}
}

void inMang(int c[], int n){
	for(int i=1; i<=n; i++){
		printf("%d",c[i]);
	}
}


main(){
	int n,g=0,m;
	int maTran[max][max];
	int *c;

	printf("Nhap so hang n: ");
	scanf("%d",&n);
		c = new int[n+1];
	nhapMaTran(maTran,n);
	in(maTran,n);
	g=demChanChia5(maTran, n);
	printf("so phan tu chan trong ma tran la: %d",g);
	// tao mang dong 1 chieu
	
	nhapMang(maTran, c,  n);
	
	
	
	
	
	
	
	
}












