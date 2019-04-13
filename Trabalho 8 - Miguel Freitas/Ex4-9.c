
/* 
Estrutura de dados 1 - UFMT
Professor: Ivairton
Miguel Freitas 
Exercício 4-9 (Trabalho 8 - Final)
*/

#include <stdio.h>
#include <stdlib.h>


//protótipos das funções
void inicializaVet(int vet[],int tam);
int funcaoHash(int key,int tam);
void SelectionSort(int *vetCont,int *vetComp,int tam);
void InsereNaTabela(int *vetCont,int *vetComp,int valor,int tam);
int contaElementos(int *vetCont,int tam);
void imprime(int *vetCont,int *vetComp,int tam);
void imprime(int *vetCont,int *vetComp,int tam);




void inicializaVet(int vet[],int tam){
    int i;
    

    for(i=0; i < tam; i++){
        vet[i] = 0;
        //printf("%d\n",vet[i]);
    }
    
};

int funcaoHash(int key,int tam){
    int index;
    index = (key%tam);
    return index;

};
void SelectionSort(int *vetCont,int *vetComp,int tam){
    int i,j,aux,aux1;

    int menorPos;
    for (i = 0; i < tam-1; i++){
        menorPos = i;
        for (j = i+1; j < tam; j++){

            if (vetCont[j] > vetCont[menorPos]){
                menorPos = j;
            }
        }
       
        aux1 = vetComp[i];
        aux = vetCont[i];
        vetComp[i] = vetComp[menorPos];
        vetCont[i] = vetCont[menorPos];
        vetCont[menorPos] = aux;
        vetComp[menorPos] = aux1;
	}
}

void InsereNaTabela(int *vetCont,int *vetComp,int valor,int tam){
    int pos;
    pos = funcaoHash(valor,tam);
    
   	vetComp[pos] = valor; 
	vetCont[pos] = vetCont[pos] + 1;
};

int contaElementos(int *vetCont,int tam){
	int i,cont;
	cont = 0;
	for(i=0; i < tam; i++){
		if(vetCont[i] != 0){
			cont++;
		}
	}
	return cont;
}	
void imprime(int *vetCont,int *vetComp,int tam){
	int i,n;
	FILE *fp;

	n = contaElementos(vetCont,tam);

	fp = fopen("saida4-9.txt","w");
	if( fp == NULL){
		puts("Erro na abertura do arquivo");
	}
	SelectionSort(vetCont,vetComp,tam);
	
	for( i = 0; i < n; i++){
		if(i == 0){
			fprintf(fp,"[ %d (%dx)",vetComp[i],vetCont[i]);	
		} else if( i != n-1){
			fprintf(fp,"; %d (%dx)",vetComp[i],vetCont[i]);
		}else{
			fprintf(fp,"; %d (%dx)]\n",vetComp[i],vetCont[i]);
		}
		
	}
	fclose(fp);
	free(vetComp);
	free(vetCont);
}


int main(){
	int i,a,b,tam,n;

	FILE *arqv;

	//tipoLista *p;
	int *vetCont,*vetValor;

	arqv = fopen("entrada4-9.txt","r");
	if( arqv == NULL){
		puts("Erro na abertura do arquivo");
	}
	fscanf(arqv,"%d",&a);
	fscanf(arqv,"%d",&b);
	tam = (b-a+1);
	/*
	printf("%d\n",a);
	printf("%d\n",b);
	printf("%d-\n",tam);
	*/
	vetCont = (int*) malloc( tam*sizeof(int) );
	vetValor = (int*) malloc( tam*sizeof(int) );

	inicializaVet(vetCont,tam);
	inicializaVet(vetValor,tam);

	while( fscanf(arqv,"%d",&n) != EOF ){

		InsereNaTabela(vetCont,vetValor,n,tam);
	}

	imprime(vetCont,vetValor,tam);

	fclose(arqv);



	return 0;
}