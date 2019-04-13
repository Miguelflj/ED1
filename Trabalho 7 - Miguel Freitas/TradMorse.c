/*Trabalho 7 - Árvore
 * Estrutura de dados - 2017/2 - Professor: Ivairton 
 * Miguel Freitas e Vinícius Magno
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArvT {
    char l;
    char codMorse[10];
    struct ArvT *esq;
    struct ArvT *dir;
}ArvT;

ArvT *ConstroiArvore(ArvT *raiz,char codigoL[],int tam,char l,int pos);
void PreOrdem(ArvT *raiz);
void Traduz(ArvT **raiz,char codigoMor[],int pos,int tam);

int main(){
    char codigoL[10],simb,letra;
    int cont;
    ArvT *raiz;
    
    //alocamento do raizamento que num tem nada dentro
    raiz = (ArvT*) malloc(sizeof (ArvT) );
    raiz->esq = NULL;
    raiz->dir = NULL;
    raiz->l = '*';
    FILE *arqv;
    arqv = fopen("LoadTabMorse.txt","r");
    if(arqv == NULL){
        printf("Erro na abertura do arquivo.\n");
    }
    
    cont = 0;
    while( fscanf(arqv,"%c", &simb) != EOF){
        if(simb == ' '){
            fscanf(arqv,"%c", &letra);
            raiz = ConstroiArvore(raiz,codigoL,cont,letra,0);
            cont = 0;
        } else if (simb != '\n') {
            codigoL[cont++] =  simb;
            
        }
    }
    fclose(arqv);
    
    int op,i;
    char codigoMor[10],cod;
    do{
        puts("Digite a opção:\n1-Impressão em Pré Ordem\n2-Tradução\n0-Sair");
        scanf("%d", &op);
        system("clear");
        switch(op){
            case 1:
                  PreOrdem(raiz);
                break;
            case 2:
                cont = 0;
                arqv = fopen("InputMorse.txt","r");
                if(arqv == NULL){
                    printf("Erro na abertura do arquivo.\n");
                }
                while( fscanf(arqv,"%c", &cod) != EOF){
                        
                        if( ( cod  != ' ') && (cod != '/') && (cod != '\n') ){
                            codigoMor[cont++] = cod;
                        } else if (cod == '/'){
                            printf(" ");
                        } else if ( (cod == ' ') || (cod == '\n') ) {
                            Traduz(&raiz,codigoMor,0,cont);
                            cont = 0;
                        }
                        if( cod == '\n') {
                                puts(" ");
                        }
                }
                

                break;
            default:
                break;
                
        }
        
    }while(op != 0);
    
    
    
    return 0;
}

//caminha alocando nos ate a posição refente ao codigo morse
// obs: o * é usando para marcar os nos que não foram tiveram letras guardadas
ArvT *ConstroiArvore(ArvT *raiz,char codigoL[],int tam,char l,int pos){
    if( raiz == NULL){
        raiz = (ArvT*) malloc(sizeof(ArvT) );
        raiz->esq = NULL;
        raiz->dir = NULL;
        raiz->l = '*';
    }
    if(pos < tam){
        if( codigoL[pos] == '.'){
            raiz->esq = ConstroiArvore(raiz->esq,codigoL,tam,l,pos+1);
        } else {
            raiz->dir = ConstroiArvore(raiz->dir,codigoL,tam,l,pos+1);
        }
    } else {
        if(raiz->l == '*'){
            raiz->l = l;
            codigoL[pos] = '\0';
            strcpy(raiz->codMorse,codigoL);
        } else {
                puts("Erro no arquivo de load da arvore");
                printf("%c\n",l);
        }
    
    }
    return raiz;
}


// imprime arvore estruturada
void PreOrdem(ArvT *raiz){
    if(raiz != NULL){
        if(raiz->l != '*'){
            printf("%s %c\n",raiz->codMorse,raiz->l);
        }
        
        PreOrdem(raiz->esq);
        PreOrdem(raiz->dir);
    }
}    



// Função que caminha ateh o no referente a letra que deseja traduzir
void Traduz(ArvT **raiz,char codigoMor[],int pos, int tam){
    ArvT *no;
    no = *raiz;
    if ( pos < tam){
        if( codigoMor[pos] == '.'){
            Traduz(&(no)->esq,codigoMor,pos+1,tam);
        } else if ( codigoMor[pos] == '-') {
            Traduz(&(no)->dir,codigoMor,pos+1,tam);
        }
    } else {
        if(no->l != '*'){
            printf("%c",no->l);
        }
        
    }

} 
    
    
    
