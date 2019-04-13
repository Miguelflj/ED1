
/*
 Estrutura de dados 1 - UFMT
Professor: Ivairton
Miguel Freitas 
Exercício 5-9 (Trabalho 8 - Final)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define tamp 70
#define NTab 150

typedef struct lista{
	char palavra[tamp];
	int qtd;
	struct lista *prox;
}lista;

typedef struct tabHash{
	lista *inicio; 
}tabHash;


//protótipos das funções
int hash(char pl[]);
lista **cria_vet(int n,tabHash *tab);
void insere(tabHash *tabela,char s[]);
int conta_elementos(tabHash *tabela);
int compara(const void *v1, const void* v2);
void imprime(tabHash *tabela,FILE *saida);

int hash(char pl[]){
	int i,soma;
	soma = 0;

	for(i=0; pl[i] != '\0' ; i++){
		soma += ((i+1) * pl[i]);
		//soma += pl[i];
		printf("%c - %d\n",pl[i],pl[i]);
		
	}
	printf("%d\n\n",soma);
	return (soma % NTab);
}	

lista **cria_vet(int n,tabHash *tab){
	int i,j=0;
	lista *p;
	lista **vet;
	vet = (lista**) malloc( n*sizeof(lista*));
	for( i = 0; i < NTab; i++){
		p = tab[i].inicio;
		while(p != NULL){
			vet[j++] = p;
			p = p->prox;

		}
		
	}

	return vet;
}

void insere(tabHash *tabela,char s[]){
	int pos,i;
	lista *aux;
	pos = hash(s);
	aux = tabela[pos].inicio;
	while(aux != NULL){
		if( strcmp(aux->palavra,s) == 0){
			aux->qtd++;
			return;
		}
		aux = aux->prox;
	}

	aux = (lista*)malloc( sizeof(lista) );
	aux->prox = tabela[pos].inicio;
	aux->qtd = 1;
	strcpy(aux->palavra,s);
	tabela[pos].inicio = aux;

}
int conta_elementos(tabHash *tabela){
	int i;
	lista *aux;
	int contT=0;
	for(i = 0; i < NTab; i++){
		aux = tabela[i].inicio;
		while(aux != NULL){
			contT++;
			aux = aux->prox;

		}
	}
	return contT;


}

int compara(const void *v1, const void* v2){

	lista **p1 = (lista**)v1;
	lista **p2 = (lista**)v2;

	if( (*p1)->qtd > (*p2)->qtd ){
		return -1;
	} else if( (*p1)->qtd < (*p2)->qtd ){

		return 1;
	} else {

		return strcmp( (*p1)->palavra,(*p2)->palavra );
	}

}


void imprime(tabHash *tabela,FILE *saida){
	lista *aux,**vet;
	int i,n;

	n = conta_elementos(tabela);
	//printf("teste %d\n",n);
	vet = cria_vet(n,tabela);

	qsort(vet,n,sizeof(lista*),compara);
	
	for( i = n-1; i > -1; i--){
		if(i == n-1){
			fprintf(saida,"[ %s (%dx)",vet[i]->palavra,vet[i]->qtd);	
		} else if( i != 0){
			fprintf(saida,"; %s (%dx)",vet[i]->palavra,vet[i]->qtd);
		}else{
			fprintf(saida,"; %s (%dx)]\n",vet[i]->palavra,vet[i]->qtd);
		}
		
	}
	free(vet);

}
	

int main(){
	tabHash tabP[NTab],tabTotal[NTab];
	char pl[tamp],n;
	int i,k,h;
	
	FILE *saida;

	// arquivo de saida
	saida = fopen("Ex5-9saida.txt","w");
   	if(saida == NULL){
        printf("Erro na abertura do arquivo.\n");
    }

    // inicializa o vetor para o diretório total com nulo
	for(i = 0; i < NTab; i++){

			tabTotal[i].inicio = NULL;
	}


	puts("Digite a quantia de arquvios a serem lidos com a pre-fixo input5-(numero do arquvio): \n");
	puts("Obs.: Na entrada definida pelo programadar já existem três arquivos.\n\n");
	scanf("%d",&h);
	// controla a abertura dos arquivos
	for(k=1; k < h+1; k++){

		char nomearq[1000];

		sprintf(nomearq,"input5-(%d).txt",k);

		// inicializa novamente a cada arquivo aberto
		for(i = 0; i < NTab; i++){

			tabP[i].inicio = NULL;
		}

		FILE *arqv;
		i = 0;
	    //abre arquivo de entrada
	    arqv = fopen(nomearq,"r");

	    if(arqv == NULL){
	        printf("Erro na abertura do arquivo.\n");
	    }

	    while( fscanf(arqv,"%c",&n) != EOF ) {

	    	if( isalpha(n)){
	    		pl[i++] = n;
	    	} else {
	    		pl[i] = '\0';
	    		insere(tabP,pl);
	    		insere(tabTotal,pl);

	    		i = 0;
	    	}

	    }
	    fclose(arqv);
	    fprintf(saida,"Centroíde do arquvivo input5-(%d):\n",k);
	    imprime(tabP,saida);
	    fprintf(saida,"\n");
	}
    
	fprintf(saida,"\n\n");
    fprintf(saida, "Centroíde total\n\n");
    imprime(tabTotal,saida);


    fclose(saida);
	return 0;
}