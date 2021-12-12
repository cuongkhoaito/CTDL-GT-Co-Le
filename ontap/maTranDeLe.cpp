#include <stdio.h>
#include <math.h>
#define max 100
// de le  (so le va khong chia het cho ba)
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

// de le
int kiemTraLeKhChia3(int so){
	if((so%2 !=0) && (so%3!= 0)){
		return 1;		
	}
	return 0;	
}


int demLeKhChia3(int a[100][100], int n){
	int d=0;
	for(int i=1; i<=n; i++){		
		for(int j=1; j<=n; j++){
			if(kiemTraLeKhChia3(a[i][j])==1){
				d++;
				printf("%d ",a[i][j]);// xuat de kiem tra 
			}				
		}
	}
	return d;
}


int demLKC3Break(int a[100][100], int n){
	int d=0;
	for(int i=n; i>=1; i--){		
		for(int j=n; j>=1; j--){
			if(kiemTraLeKhChia3(a[i][j])==1){
				d++;
				break;
			}				
		}
	}
	return d;
}

int kiemTraChen(int a[100][100], int n, int cot){		 	// cot thay cho i
	for(int hang=n; hang>=1; hang--){ 						// hang thay cho j
		if(a[cot][hang] %2!=0 && a[cot][hang]%3!=0){
			return a[cot][hang]; 							//nhan dk dung dieu kien tra ve. khong chay tiep
		}
	}
	return 0;
}

int dequy(int a[100][100], int n, int &cot){ // tra ve gia tri cot de chay khong trung cot
	if(kiemTraChen(a,  n, cot) !=0){
		return kiemTraChen(a,  n, cot);
	}
	cot--;
	return  dequy(a,  n, cot);
}

void chenVaoMang(int a[100][100], int n,int ds[],int nm){
	int cot=n+1;
	for(int i=nm;i>=1;i--){
		cot--;
		ds[i]=dequy(a,  n,  cot);
											
//		
//			cot--;
//			if(kiemTraChen(a,  n, cot) !=0){// hang co so du dk chen
//				ds[i]=kiemTraChen(a,  n, cot);
//			}
//			else // hang khong du dk chen
//			while(kiemTraChen(a,  n, cot) !=0){
//				ds[i]=kiemTraChen(a,  n, cot);
//			}
//						
	}
}



void xuatMang(int ds[], int nm){
	printf("\n  ");
	for(int i=1; i<=nm; i++){
		printf("%d ",ds[i]);
		
	}
}

main(){
	int i, j,n,nso, nm;
	int maTran[100][100];
	int *ds;
	printf("Nhap so hang va cot cua ma tran n: ");
	scanf("%d",&n);
	nhapMaTran(maTran,n); 
	in(maTran,n);
	printf("\n\n");
	in(maTran,n);	
	printf(" \n cau 3 xuat le khong chia ba la: %d   ",demLeKhChia3(maTran, n));
	nm= demLKC3Break(maTran, n);
	printf(" co %d so o cuoi le khong chia het cho 3 ",nm);
	ds = new int[ nm+ 1];
	chenVaoMang(maTran,  n, ds, nm);
	xuatMang(ds,  nm);
	
	//printf(" cac so chan chia het cho 5 la: %d",);
	

}






