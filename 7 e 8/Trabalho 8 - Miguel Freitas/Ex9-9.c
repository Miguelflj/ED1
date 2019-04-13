
/*
 Estrutura de dados 1 - UFMT
Professor: Ivairton
Miguel Freitas 
Exercício 9-9 (Trabalho 8 - Final)
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 50

typedef struct ArvDe{
	char resulV[tam];
	char resulAd[tam];
	struct ArvDe *esq;
	struct ArvDe *dir;

}ArvDe;




// no que pergunta a porcentagem pela esquerda da esquerda
ArvDe *nonivelesq2(ArvDe *no,char v[],char ad[]){
	no = (ArvDe*) malloc( sizeof(ArvDe) );
	
	strcpy(no->resulV,v);
	strcpy(no->resulAd,ad);

	no->esq = NULL;
	no->dir = NULL;
	return no;
}


// no que pergunta a porcentagem pela direita da esquerda
ArvDe *noniveldir2(ArvDe *no,char v[],char ad[]){
	no = (ArvDe*) malloc( sizeof(ArvDe) );
	strcpy(no->resulV,v);
	strcpy(no->resulAd,ad);

	no->esq = NULL;
	no->dir = NULL;
	return no;
}



ArvDe *NoNivelesq2_1(ArvDe *no,char v[],char ad[]){
	no = (ArvDe*) malloc( sizeof(ArvDe) );
	strcpy(no->resulV,v);
	strcpy(no->resulAd,ad);

	no->esq = NULL;
	no->dir = NULL;
	return no;
}

ArvDe *NoNiveldir2_1(ArvDe *no,char v[],char ad[]){
	no = (ArvDe*) malloc( sizeof(ArvDe) );
	strcpy(no->resulV,v);
	strcpy(no->resulAd,ad);

	no->esq = NULL;
	no->dir = NULL;
	return no;
}


ArvDe *NoNivelesq1(ArvDe *no,char s[]){
	no = (ArvDe*) malloc( sizeof(ArvDe) );
	strcpy(no->resulV,s);
	no->resulAd[0] = 'x';

	no->esq = nonivelesq2(no->esq,"Você: 12","Advers: 8");
	no->dir = noniveldir2(no->dir,"Você 5","Advers: 10");
	return no;
}



ArvDe *NoNiveldir1(ArvDe *no,char s[]){
	no = (ArvDe*) malloc( sizeof(ArvDe) );
	strcpy(no->resulV,s);
	no->resulAd[0] = 'y'; 
	no->esq = NoNivelesq2_1(no->esq,"Você: 8","Advers: 20");
	no->dir = NoNiveldir2_1(no->dir,"Você: 10","Advers: 2");
	return no;
}



// raiz da arvore
ArvDe *raiz(ArvDe *raiz,char s[]){
	raiz = (ArvDe*) malloc( sizeof(ArvDe) );
	strcpy(raiz->resulV,s);
	raiz->resulAd[0] = 'a';
	raiz->esq = NoNivelesq1(raiz->esq,"Adversário");
	raiz->dir = NoNiveldir1(raiz->dir,"Adversário");
	return raiz;

};

void NavegaArv(ArvDe *no){
	char c;

	if(no->esq != NULL && no->dir != NULL){
		if(no->resulAd[0] == 'x' ){
			NavegaArv(no->dir);
		} else {
			NavegaArv(no->esq);
		}
	} else {
		printf("|%s|\n",no->resulV);
		printf("|%s|\n",no->resulAd);
	}
		

	/*
	if(no->esq != NULL && no->dir != NULL){
		printf("%s: ",no->resulV);
		puts("e ou d");
		scanf("%c",&c);
		scanf("%*c");

		if( c == 'e'){
			NavegaArv(no->esq);
		} else {
			NavegaArv(no->dir);
		}
	} else {
		printf("%s\n",no->resulV);
		printf("%s\n",no->resulAd);

	}
	*/


}
/*
void PreOrdem(ArvDe *no){
	if(no != NULL){
		//printf("%s\n",no->pergunta);
		PreOrdem(no->esq);
		PreOrdem(no->dir);
	}
};
*/
int main(){
	ArvDe *no;
	char c;
	no = raiz(no,"Você");
	puts("Você: e ou d ?");
	scanf("%c",&c);
	if(c == 'e'){
		NavegaArv(no->esq);
	} else {
		NavegaArv(no->dir);
	}

	return 0;
}