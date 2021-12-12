#include<stdio.h>
int TongCS_Chan(int n){
	int tam;
	tam= n%10;
	if (n==0)
		return tam;
	if(tam%2==0)
		return TongCS_Chan(n/10)+tam;
	else
		return TongCS_Chan(n/10);
}

int main(){
	int n;
	printf("Nhap chu so : ");
	scanf("%d",&n);
	printf("Tong cac chu so chan la: %d",TongCS_Chan(n));
	
}
