#include <stdio.h>
struct NL{
	int dl;
	NL *tiep;
};

NL*Bsung(NL *D, NL *ptu){
	NL *tg;
	if(D==NULL)
		D=ptu;
	else{
		tg= D;
		while(tg->tiep!=NULL)
			tg = tg->tiep;
		tg->tiep = ptu;
	}
	return D;
}

void Duyet(NL *D){
	while(D!=NULL){
		printf("%d ",D->dl);	
		D= D->tiep;	
	}	
}

void Tao(NL *&D){
	NL *p;
	int n;
	printf("So ptu NODE: ");
	scanf("%d",&n);
	
	for(int i= 1; i<=n; i++){
		p = new NL;
		printf("Nhap ptu thu %d: ",i);
		scanf("%d",&p->dl);
		p->tiep = NULL;
		D = Bsung(D,p);
	}
}

main(){
	int n;
	NL *H, *p,*tg;
	H = NULL;
	Tao(H);
	Duyet(H);
	
}








