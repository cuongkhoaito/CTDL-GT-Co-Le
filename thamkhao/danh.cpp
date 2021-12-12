#include <stdio.h>
#include <string.h>
struct DanhSach{
    char mon[30];
    char gv[5];
    int tc; 
};
void NHAP( DanhSach ds[], int n){
	for(int i=1; i<=n; i++){
		fflush(stdin);
		printf("Ten mon hoc %d: ",i);
		gets(ds[i].mon);
		printf("So tin chi: ");
		scanf("%d",&ds[i].tc);
		fflush(stdin);
		printf("Ten giao vien: ");
		gets(ds[i].gv);		
	}
}	
int  TIM(DanhSach ds[], int n) {
	for(int i=1; i<=n; i++){
		if(strcmp("Cau truc du lieu",ds[i].mon) == 0){
			return i;
		}							
	}
	return 0;
}

void IN(DanhSach ds[], int n){
	for (int i=1; i<=n; i++)
	if((TIM(ds, n))==i){
		printf("Ten mon hoc %s: \n",ds[i].mon);
		printf("So tin chi %s : \n",ds[i].tc);
		printf("Ten giao vien %d: \n",ds[i].gv);		
	}
}

main(){
	int n;
	DanhSach *ds;
	printf("Nhap so mon hoc: ");
	scanf("%d",&n); 
	ds = new DanhSach[n+1];	
	NHAP(ds, n);
	IN(ds,  n);

}
