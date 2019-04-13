
/*
Estrutura de dados 1 - UFMT
Professor: Ivairton
Miguel Freitas 
Exercício 6-9 (Trabalho 8 - Final)
*/

#include <stdio.h>
#include <stdlib.h>

#define T 2







struct estArvoreMultF {

    int valor[2*T-1];
    struct estArvoreMultF *filhos[2*T];
    int qtd_valor;

};

typedef struct estArvoreMultF arvMult;

// para armazenar os valores por nivel
struct estLista {
    int valor;
    struct estLista *prox;
};


typedef struct estLista tipoLista;


//protótipos das funções
int ContaDados(arvMult *no,int cont);
void InsereValor(arvMult **raiz,int n);
int alturaArv(arvMult *raiz);
arvMult *alocaNo(int n);
void GuardaNivel(arvMult *raiz, int nivel, int nivelPassagem,tipoLista **L);
void ImprimeNiveis(arvMult *raiz, int nivel, int nivelPassagem);
void InsereInicio(tipoLista **lista, int n);

int main(){
	arvMult *no;
	no = NULL;
	int n,dados,alt,*vet;

	tipoLista *L;
	L = NULL;

    FILE *arqv;
    

    arqv = fopen("Ex6.txt","rt");
    if(arqv == NULL){
        printf("Erro na abertura do arquivo.\n");
    }

    while( fscanf(arqv,"%d",&n) != EOF){
    	//printf("%d\n",n);
    	InsereValor(&no, n);
    	
    }
    fclose(arqv);




    int op,nivel;

    do{
    	puts("Digite uma opção:");
    	puts("1-Qtd dados na struct\n2-Altura Arvore\n3-Imprime por niveis\n4-Imprime nivel especifico(retornando)\n0-Sair");
    	scanf("%d",&op);
    	system("clear");
    	switch(op){
	    	case 1:
	    		dados = ContaDados(no,0);
	    		printf("Quantia de dados: %d\n\n",dados);
	    		break;
	    	case 2:
	    		alt = alturaArv(no);
	    		printf("Altura estrutura: %d\n\n",alt);
	    		break;
	    	case 3:
	    		ImprimeNiveis(no,0,0);
	    		break;
	    	case 4:
	    		puts("Digite o nivel que deseja imprimir");
	    		scanf("%d",&nivel);
			    GuardaNivel(no,nivel,0,&L);
			    printf("Nivel: ");
			    while( L != NULL){

	    		printf("[%d] ",L->valor);
	    		L = L->prox;
			    }
			    puts("");
			    L = NULL;
	    		break;
	    	default:
	    		break;
    	}

    }while(op != 0);
    

    

    
    

   
    

	return 0;
}




arvMult *alocaNo(int n) {
    int i;
    arvMult *novoNo;
    novoNo = (arvMult*) malloc( sizeof(arvMult) );
    novoNo->qtd_valor = 1;
    novoNo->valor[0] = n;
    for(i = 0; i < (2*T); i++){
        novoNo->filhos[i] = NULL;  
    }

    return novoNo;
}


void InsereValor(arvMult **raiz,int n){
    arvMult *no;
    int i;
    no = *raiz;
    if( (*raiz) == NULL){
        (*raiz) = alocaNo(n);
        //puts("Alocou\n");
    } else if( (no)->qtd_valor < (2*T -1) )   {

        i = (no)->qtd_valor;
        while( ( i > 0) && (n < (no)->valor[i-1]) ) {
            (no)->valor[i] = (no)->valor[i-1];
            i--;
        }
        //puts("Ordenou e guardo\n");
        (no)->valor[i] = n;
        (no)->qtd_valor++;
        
    } else {
        i=0;
        while ( (i < 2*T-1) && ( n > (no)->valor[i] ) ){
            i++;
            
        }
        //puts("Achou posição valida e fez a chamada recursiva\n");
        InsereValor(&(no)->filhos[i], n);
    }

}


// para fazer o contagem o main deve passar 0 como parâmetro

int ContaDados(arvMult *no,int cont){
    int i;
    i=0;
    if( no != NULL ){
        while ( ( i < (no)->qtd_valor)){
            cont = ContaDados( (no)->filhos[i],cont); + cont;
            i++;
            cont++;
        }
    cont = ContaDados( (no)->filhos[i],cont); + cont;
        
    }
    return cont;
}


// valido apenas para T = 2;
int alturaArv(arvMult *raiz){
    if( raiz == NULL){
    	return -1;
    } else {
        int a=0, b=0,c=0, d=0;
        a = alturaArv(raiz->filhos[0]);
        b = alturaArv(raiz->filhos[1]);
        c = alturaArv(raiz->filhos[2]);
        d = alturaArv(raiz->filhos[3]);


        if(	a > b && a > c && a > d ) {
            return a+1;
        } else if (b > c && b > a && b > d){
            return b+1;
        } else if ( c > d && c > a && c > b){
        	return c+1;
        } else {
        	return d+1;
        }
    }
    
    
}

// em pos ordem
void ImprimeNiveis(arvMult *raiz, int nivel, int nivelPassagem){
    arvMult *aux;
    aux = raiz;
    int i;
    if(raiz != NULL){
                ImprimeNiveis(aux->filhos[0],nivel+1,nivelPassagem+1);
                ImprimeNiveis(aux->filhos[1],nivel+1, nivelPassagem+1);
                ImprimeNiveis(aux->filhos[2],nivel+1, nivelPassagem+1);
                ImprimeNiveis(aux->filhos[3],nivel+1, nivelPassagem+1);
                
                if(nivel == nivelPassagem){
                	for(i=0; i < aux->qtd_valor; i++){
                    	printf("%d° nivel  = [%d]\n",nivel,aux->valor[i]);
                    }
                }
    } else {
    }
}

void InsereInicio(tipoLista **lista, int n){
    tipoLista *novo;
    novo = (tipoLista*) malloc(sizeof(tipoLista));
    if(novo != NULL){ 
        novo->valor = n;
        novo->prox = *lista;
        (*lista) = novo;
    }

}



void GuardaNivel(arvMult *raiz, int nivel, int nivelPassagem,tipoLista **L){
    arvMult *aux;
    aux = raiz;
    int i;
    if(raiz != NULL){
                GuardaNivel(aux->filhos[0],nivel,nivelPassagem+1,L);
                GuardaNivel(aux->filhos[1],nivel, nivelPassagem+1,L);
                GuardaNivel(aux->filhos[2],nivel, nivelPassagem+1,L);
                GuardaNivel(aux->filhos[3],nivel, nivelPassagem+1,L);
                
                if(nivel == nivelPassagem){
                	for(i=0; i < aux->qtd_valor; i++){

                		InsereInicio(L,aux->valor[i]);
                    	
                    }
                }
               
    } else {
    }
}