/*  Árvore com multiplos filhos
    22/01/2018


*/

#include <stdio.h>
#include <stdlib.h>

#define T 2

//estrutura da arvore com multiplos filhos
struct estArvoreMultF {
    int valor[2*T-1];
    struct estArvoreMultF *filhos[2*T];
    int qtd_valor;
};


typedef struct estArvoreMultF arvMult;

//Prototipação das funções
arvMult *alocaNo(int n);
void InsereValor(arvMult **raiz,int n);
int BuscaValor (arvMult *no,int n);
void PreOrdem(arvMult *no);
void Ordem(arvMult *no);
void PosOrdem(arvMult *no);




int main(){
    arvMult *raiz;
    raiz = NULL;
    int op,n,aux;
    do{
    puts("Digite a opção:\n1-Inserir\n2-Buscar\n3-Remover\n4-Pré Ordem\n5-Ordem\n6-Pós Ordem\n0-Sair");
    scanf("%d", &op);
    system("clear");
    switch(op){
        case 1:
            puts("Digite um valor");
            scanf("%d", &n);
            InsereValor(&raiz, n);
            break;
        case 2:
            puts("Digite um valor");
            scanf("%d", &n);
            aux = BuscaValor(raiz, n);
            if( aux == 0){
                puts("Valor nao encontrado");
            }
            if( aux == 1){
                puts("Valor encontrado");
            }
            break;
        case 3:
            puts("Digite o valor que deseja remover");
            scanf("%d",&n);
            Remove(&raiz,n);
            break;
        case 4:
            PreOrdem(raiz);
            break;
        case 5:
            Ordem(raiz);
            break;
        case 6:
           PosOrdem(raiz);
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
    novoNo = (arvMult*) malloc(sizeof(arvMult));
    novoNo->qtd_valor = 1;
    novoNo->valor[0] = n;
    for(i=0;i<(2*T);i++){
        novoNo->filhos[i] = NULL;  
    }

    return novoNo;
}

void InsereValor(arvMult **raiz,int n){
    arvMult *novo,*no;
    int i;
    no = *raiz;
    if( (*raiz) == NULL){
        *raiz = alocaNo(n);
        
    } else if((no)->qtd_valor < 2*T -1)  {
        i = (no)->qtd_valor;
        while( ( i > 0) && (n < (no)->valor[i-1]) ) {
            (no)->valor[i] = (no)->valor[i-1];
            i--;
        }
        (no)->valor[i] = n;
        (no)->qtd_valor++;
        
    } else {
        i=0;
        while ( (i < 2*T) && ( (no)->valor[i] < n) ){
            i++;
            
        }
        InsereValor(&(no->filhos[i]), n);
    }

}


int BuscaValor (arvMult *no,int n,i){
    int i;
    i = 0;
    if( (no) != NULL){
        while ( (i < no->qtd_valor) && ( (no)->valor[i] < n) ){
                i++;
        }
        if ( (no)->valor[i] == n){
            return 1;
        }
        BuscaValor(no->filhos[i],n);
        
    } else {
        return 0;
        
    }

}


void PreOrdem(arvMult *no){
    int i;
    i = 0;
    if( no != NULL){
        while( i < (no)->qtd_valor){
            printf("%d ",(no)->valor[i]);
            puts("");
            i++;
        }
        i = 0;
        while( i < (no)->qtd_valor){
            PreOrdem( (no)->filhos[i]);
            i++;
            
        }
    }
    
}
void Ordem(arvMult *no){
    int i;
    i=0;
    if( no != NULL ){
        while ( ( i < (no)->qtd_valor)){
            printf("%d\n",(no)->valor[i]);
            Ordem( (no)->filhos[i]);
            i++;
        }
    Ordem( (no)->filhos[i]);
        
    }
}

void PosOrdem(arvMult *no){
    int i;
    i = 0;
    if( no != NULL){
        while(i < (no)->qtd_valor){
            PosOrdem( (no)->filhos[i]);
            i++;
            
        }
        i = 0;
        while ( i < (no)->qtd_valor){
            printf("%d ",(no)->valor[i]);
            puts("");
            i++;
        }
        
        
    }
    
}


int VerFolhas(arvMult *no){
    int i;
    i = 0;
    while( i < 2*T){
        if( no->filhos[i] != NULL){
         return 0;   
        }
        i++;
        
    }
    return 1;
    
}
/* 1 caso, se o valor estiver num no folha, se for o unico, liberar o no, se nao, organizar.
 * 2 caso o valor esteja num no que tenha filho a esquerda, pegar o maior valor do filho a esquerda e subscrever o valor inicial, e fazer
 * uma chamada recursiva removendo o maior valor do filhos a esquerda.
 * 3 caso, nao tem filhos a esquerda, pegar o primeiro filhos a esquerda buscar o maior valor
*/
int EncontraMaiorVlr( **no){
    if( *no != NULL){
        if( (*no)->filhos[qtd_valor] != NULL){
            EncontraMaiorVlr(&(*no)->filhos[qtd_valor]);
        }
        return ((*no)->valor[qtd_valor-1]);
    }
}

void Remove(arvMult **raiz,int n){  
    int i;
    arvMult *no;
    no = *raiz;
    if( *raiz != NULL){
        i = 0;
        while ( ( pos < (no)->qtd_valor) && (n > (no)->valor[i] ) {
            i++;
        }
        
        if ( ( i == (no)->qtd_valor) || ((no)->valor[i] != n) ) {
            Remove(&(no)->filhos[i],n); 
        } else if ( (no)->valor[i] == n) {
            
            if(VerFolhas(no)) {
                //1 caso - o valor estando numa folha
                if( (no)->qtd_valor == 1) {
                    free(*raiz);
                    (*raiz) = NULL;
                } else {
                    int j;
                    while(j = ((no)->qtd_valor-1); j > i; j--){
                            no->valor[j-1] = no->valor[j];
                    }
                    no->qtd_valor--;
                }
            } else if {
                int novoV;
                if ( (no)->filhos[i] != NULL) {
                    novoV = EncontraMaiorVlr(&(no)->filhos[i]);
                    (no)->valor[i] = novoV;
                    Remove(&(no)->filhos[i],novoV);
                }
            } else {
                int novoV;
                int posFilho;
                posFilho = 0;
                while ( (posFilho <= (no)->qtd_valor) && ((no)->filhos[posFilho] == NULL)) {
                    posFilho++;
                    
                }
                if (posFilho <= (no)->qtd_valor) {
                    novoV = EncontraMaiorVlr( (no)->filhos[posFilho]);
                    Remove( &(no)->filhos[posFilho],novoV);
                    while( i > posFilho){
                        (no)->valor[i] = (no)->valor[i-1];
                        i--;
                        
                    }
                    (no)->valor[posFilho] = novoV;
                    
                }
                
            }
        
        }
    }
}























