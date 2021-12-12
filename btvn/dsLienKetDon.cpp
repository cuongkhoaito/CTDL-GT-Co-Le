#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// xay dung ham in  ds lien ket don
struct NL{
	int dl;
	NL *tiep;
};

NL*Bsung(NL *D, NL *ptu)
{
	NL *tg;
	if ( D==NULL)
		D = ptu;
	else{
		tg = D;
		while(tg->tiep != NULL)
			tg = tg->tiep;
		tg->tiep = ptu;
	}
	return D;
}



 main(){
 	NL *H, *p, *tg;
 	srand((int)time(0));
 	H = NULL;
 	do{
 		p = new NL; 
// 		p->dl =rand()%50; //scanf vao bien p->dl;
 		scanf("%d",&p->dl);
 		p->tiep = NULL;
 		H = Bsung(H,p);
 		
	 }
 	while(rand()%6!=0);
 	//IN duyet
 	tg = H;
 	while (tg!=NULL){
 		printf("%d ",tg->dl);
 		tg= tg->tiep;
	}	
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
