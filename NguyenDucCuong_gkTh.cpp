#include <stdio.h>
#include <math.h>
#define max 100
void nhapMaTran(int a[100][100], int n){
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




int ktnt(int n){
 	if(n<2)
    	return 0;
	if(n>=2){
	    if(n==2)
	       return 1;
	      else   {
	       for(int i=2;i<=sqrt(n);i++)
	         {
	          if(n%i==0)
	             return 0;
	         }
	      }
	      return 1;
	   }
}

void xoaSNT(int a[100][100], int n){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(ktnt(a[i][j])==1){
				a[i][j]= NULL;	
				break;
			}			
		}
	}
}

void NhapDS(int ds[], int ns){
	for(int i=1; i<=ns; i++){
		printf("bs[%d]",&i);
		scanf("%d",&ds[i]);
	}	
}

void boSung(int a[100][100], int n){
	int ds[100];
//	for(int i=n+1; i<=n+1; i++){
//		for(int j=1; j<=n; j++){
//			a[i][j]= ds[j];
//		}
//	}
//	
//	for(int i=1; i<=n+1; i++){
//		for(int j=1; j<=n; j++){
//			printf("%d  ",a[i][j]);
//		}
//		printf("\n");
//	} 
//
	fflush(stdin);
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%d",&ds[i]);
	for(j=1;j<=n;j++)
		a[n+1][j] = ds[j];
		
	for(i=1;i<=n+1;i++) {
		for(j=1;j<=n;j++) 
			printf(" %d",a[i][j]);
		printf("\n");
	}
}



main(){
	int i, j,n,nso;
	int maTran[100][100],ds[100];
	printf("Nhap so hang va cot cua ma tran n: ");
	scanf("%d",&n);
	nhapMaTran(maTran,n);
	in(maTran,n);
	xoaSNT(maTran,  n);
	printf("\n\n");
	in(maTran,n);	
	 boSung(maTran,  n);
//	printf("So phan tu cua day so: ");
//	scanf("%d",&nso);
//	NhapDS(ds, n);
	
//	boSung(maTran, n,ds);
		
//	int i,j;
//	for(i=1;i<=n;i++)
//		scanf("%d",&ds[i]);
//	for(j=1;j<=n;j++)
//		maTran[n+1][j] = ds[j];
//		
//	for(i=1;i<=n+1;i++) {
//		for(j=1;j<=n;j++)
//			printf(" %d",maTran[i][j]);
//		printf("\n");
//	}	
//		

}




