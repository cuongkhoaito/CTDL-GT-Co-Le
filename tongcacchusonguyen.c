#include <stdio.h>
int TONGCS(int n){
    if (n==1)
        return 1;
    else {
        return TONGCS(n/10)+n%10;
    }
}

int main(){
    int n;
    printf("Nhap chu so can tinh: ");
    scanf("%d",&n);
    printf("Tong cua %d la: %d",n, TONGCS( n));

}