/* Estrutura de dados 1 - UFMT
Professor: Ivairton
Miguel Freitas 
Exercício 7-9 (Trabalho 8 - Final)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 50

typedef struct ArvDe{

	char pergunta[tam];
	struct ArvDe *esq;
	struct ArvDe *dir;


}ArvDe;

ArvDe *nonivel3(ArvDe *no,char s[]){
	no = (ArvDe*) malloc( sizeof(ArvDe) );
	strcpy(no->pergunta,s);
	no->esq = NULL;
	no->dir = NULL;
	return no;
}


// no que pergunta a porcentagem pela esquerda da esquerda
ArvDe *nonivelesq2(ArvDe *no,char s[]){
	no = (ArvDe*) malloc( sizeof(ArvDe) );
	strcpy(no->pergunta,s);
	no->esq = nonivel3(no->esq,"Aprovação a confirmar");
	no->dir = nonivel3(no->dir,"Prova final");
	return no;
}


// no que pergunta a porcentagem pela direita da esquerda
ArvDe *noniveldir2(ArvDe *no,char s[]){
	no = (ArvDe*) malloc( sizeof(ArvDe) );
	strcpy(no->pergunta,s);
	no->esq = nonivel3(no->esq,"Reprovado");
	no->dir = nonivel3(no->dir,"Reprovado");
	return no;
}


// no que pergunta a porcentagem pela esquerda da direta 
ArvDe *nonivelesq2_1(ArvDe *no,char s[]){
	no = (ArvDe*) malloc( sizeof(ArvDe) );
	strcpy(no->pergunta,s);
	no->esq = nonivel3(no->esq,"Aprovação a confirmar");
	no->dir = nonivel3(no->dir,"Aprovado");
	return no;
}


//no que pergunta a se a nota é menor que 5 pela esquerda
ArvDe *nonivelesq1(ArvDe *no,char s[]){
	no = (ArvDe*) malloc( sizeof(ArvDe) );
	strcpy(no->pergunta,s);
	no->esq = nonivelesq2(no->esq,"Freq >= 75 ");
	no->dir = noniveldir2(no->dir,"Freq >= 75 ");
	return no;
}



ArvDe *noniveldir1(ArvDe *no,char s[]){
	no = (ArvDe*) malloc( sizeof(ArvDe) );
	strcpy(no->pergunta,s);
	no->esq = nonivelesq2_1(no->esq,"Freq >= 75 ");
	no->dir = nonivel3(no->dir,"Furado");
	return no;
}



// raiz da arvore
ArvDe *raiz(ArvDe *raiz, char s[]){
	raiz = (ArvDe*) malloc( sizeof(ArvDe) );
	strcpy(raiz->pergunta,s);
	raiz->esq = nonivelesq1(raiz->esq,"Nota < 5");
	raiz->dir = noniveldir1(raiz->dir,"Nota < 5");
	return raiz;

};

void NavegaArv(ArvDe *no){
	char c;
	printf("%s\n",no->pergunta);
	if(no->esq != NULL && no->dir != NULL){
		puts("s ou n");
		scanf("%c",&c);
		scanf("%*c");
		if( c == 'n'){
			NavegaArv(no->esq);
		} else {
			NavegaArv(no->dir);
		}
	}


}
void PreOrdem(ArvDe *no){
	if(no != NULL){
		printf("%s\n",no->pergunta);
		PreOrdem(no->esq);
		PreOrdem(no->dir);
	}
};

int main(){
	ArvDe *no;
	no = raiz(no,"Nota > 7?");
	NavegaArv(no);
	//PreOrdem(no);
	return 0;
}