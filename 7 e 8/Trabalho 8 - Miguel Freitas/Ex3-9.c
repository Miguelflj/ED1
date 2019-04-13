
/* 
Estrutura de dados 1 - UFMT
Professor: Ivairton
Miguel Freitas 
Exercício 3-9 (Trabalho 8 - Final)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tlista {
	char nome[20];
	int idade;
}Tlista;

//protótipos das funções
int InsereInicio(Tlista *lista,int idade,char nome[],int tam,int qtd);
void QuickSort(Tlista *alunos,int inicio,int fim);



int InsereInicio(Tlista *lista,int idade,char nome[],int tam,int qtd){
    int i;
    if(qtd < tam){
        if(qtd > 0){
            for(i=qtd;i > 0;i--){
            	lista[i] = lista[i-1];
            }
        }
        lista[0].idade =  idade;
        strcpy( lista[0].nome,nome);

        return qtd+1;
    }else{
        puts("Vetor cheio");

    }
}

// ordenando de forma crescente  caso médio O(nlogn)
void QuickSort(Tlista *alunos,int inicio,int fim){
    int i,j;
    
    int pivo,pos;

    Tlista aux;

    i = inicio;
    j = fim;
    pos = (((fim+inicio)/2));
    pivo = alunos[pos].idade;
    
    while ( i <= j){
        if (  (alunos[i].idade) < pivo){
            i++;
        }else if( (alunos[j].idade) > pivo){
            j--;
        }else{
            aux = alunos[i];
            alunos[i] = alunos[j];
            alunos[j] = aux;
            i++;
            j--;
        }
    
    }
    if(j > inicio){
        QuickSort(alunos,inicio, j);

    }
    if(i < fim){
        QuickSort(alunos,j+1,fim);
    }
    
};




int main(){
	Tlista *alunosV;
	Tlista *alunosN;
	char nome[20],l;
	int idade,i;
	int contC,contF;

	// conta alunos do colegial
	contC = 0;

	// conta alunos do fundamental
	contF = 0;
	FILE *arqv;
	arqv = fopen("Entrada3-9.txt","rt");

    if(arqv == NULL){
        printf("Erro na abertura do arquivo.\n");
    }
   
    while ( fscanf(arqv,"%c",&l) != EOF){	
    	if( l != '\n'){
    		if( l == ' '){
    			fscanf(arqv,"%d",&idade);
    			if( idade < 17){	
    				contF++;
    			} else {
    				contC++;
    			}

    		}


    	}
    }
 	fclose(arqv);

 	alunosN = (Tlista*) malloc(contF * sizeof(Tlista) );
    
 	alunosV = (Tlista*) malloc(contC * sizeof(Tlista) );

 	int qtdF=0,qtdC=0;
 	arqv = fopen("Entrada3-9.txt","rt");
    if(arqv == NULL){
        printf("Erro na abertura do arquivo.\n");
    }
    i = 0;

    while( fscanf(arqv,"%c",&l) != EOF){
    	if( l != '\n'){
	    	if( l != ' '){
	    		nome[i++] = l;
	    	} else {
	    		nome[i] = '\0';
	    		fscanf(arqv,"%d",&idade);
	    		if(idade < 17){
	    			qtdF = InsereInicio(alunosN,idade,nome,contF,qtdF);
	    			i = 0;
	    		} else {
	    			qtdC = InsereInicio(alunosV,idade,nome,contC,qtdC);
	    			i = 0;
	    		}
	    	}
	    }
	    	
    }
    int tam,j;
    QuickSort(alunosN,0,qtdF-1);

    QuickSort(alunosV,0,qtdC-1);

    if(qtdC > qtdF){
    	tam = qtdC;
    } else {
    	tam = qtdF;
    }

    j = qtdC-1;

    /* Para evitar baderna durante a viagem, quando há divergencia da quantia de alunos do fundamental e colegial o algoritmo
    senta os estudantes de mesma escolaridade separados
    
    */

    // arquivo de saida
    arqv = fopen("Onibus.txt","w");
    if(arqv == NULL){
        printf("Erro na abertura do arquivo.\n");
    }
    fprintf(arqv, "(Motorista: Carlão do volante solto , idade: 42) \n" );
    fprintf(arqv,"\n");
   	for(i = 0 ;  i  < tam ; i++){
   		if( i < qtdF){
   			fprintf(arqv,"(nome: %s , idade: %d)  ",alunosN[i].nome,alunosN[i].idade);
   		}
   		if( j > -1){
   			fprintf(arqv,"(nome: %s , idade: %d)  ",alunosV[j].nome,alunosV[j].idade);
   			j--;
   		}
   		fprintf(arqv,"\n");

   	} 


    fclose(arqv);




	return 0;
}