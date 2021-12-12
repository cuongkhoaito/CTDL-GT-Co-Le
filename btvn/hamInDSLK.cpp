#include <stdio.h>
#include <time.h>
#include <stdlib.h>
struct NL{
	int dl;
	NL *tiep;
};

NL*Bsung(NL *D, NL *ptu){
	NL *tg;
	if(D==NULL)
		D= ptu;
	else{
		tg = D;
		while(tg->tiep!=NULL){
			tg = tg->tiep;
		}
		tg->tiep =ptu;
	}
	return D;
}
void Tao(NL *&D){
	NL *p;
	int n;
	printf("Nhap so ptu: ");
	scanf("%d", &n);
	for (int i= 1; i<=n; i++ ){
		p = new NL;
		printf("Nhap ptu thu %d: ",i);
		scanf("%d",&p->dl);
		p->tiep = NULL;
		D= Bsung(D, p);
	}
}
void Duyet(NL *D){
	NL *tg;
	while(tg->tiep != NULL){
		printf("%d ",tg->dl);
		tg = tg->tiep;	
	}	
}

main(){
	NL *H;
	//srand((int)time(0));
	H = NULL;
	Tao(H);
	Duyet(H);
}















