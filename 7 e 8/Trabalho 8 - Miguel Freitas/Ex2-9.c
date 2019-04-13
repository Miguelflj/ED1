/* Estrutura de dados 1 - UFMT
Professor: Ivairton
Miguel Freitas 
Exercício 2-9 (Trabalho 8 - Final)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    
    char simb;
    struct stack *prox;
}stack;

//protótipos das funções
void Empilha(stack **pilha, char s);
stack *Desempilha(stack **pilha);


void Empilha(stack **pilha, char s){
    stack *novo;
    novo = (stack*) malloc(sizeof(stack));
    if(novo != NULL){ 
        novo->simb = s;
        novo->prox = *pilha;
        (*pilha) = novo;
    }

}

stack *Desempilha(stack **pilha){
    stack *aux;
    aux = (*pilha);
    if((*pilha) == NULL){
        return NULL;
    } else {
        if((*pilha)->prox == NULL){
            (*pilha) = NULL;
            return aux;
        } else {
            (*pilha) = (*pilha)->prox;
            return aux;
        }
    }
}


int main(){ 
    
    // variavel para receber o conteúdo do arquivo
    char simb;
    
    stack *balan;
    balan = NULL;
    stack *aux;
    FILE *arqv;
    aux = NULL;
    /* variaveis para controle de balanço, variaveis com conteudo binario para controle de balanço verdadeiro ou falso
     *  e variavel de contagem para saber se houve presença do simbolo ou nao
     */
    int contP,boolP;
    
    int contCh, boolCh;
    
    int contColc, boolColc;
    
    int balanP,balanC,balanCh;
    
    contCh = 0;
    boolCh = 1;
   
    
    contP = 0;
    boolP = 1;
   
    
    contColc = 0;
    boolColc = 1;
    
    balanP = 1;
    balanCh = 1;
    balanC = 1;
     
     
    arqv = fopen("ex2.txt","r");
    if(arqv == NULL){
        printf("Erro na abertura do arquivo.\n");
    }
    while( fscanf(arqv,"%c",&simb) != EOF){
        
            if( simb != '\n' ){
                //controla parenteses
                // teste para não alterar um resultado ja negativo
                if( boolP == 1){
                    if( simb == '(' ){
                        contP++;
                        balanP++;
                        
                        Empilha(&balan,'p');
                        
                    } else if( simb == ')' ) {
                        contP++;
                        balanP--;
                        aux = Desempilha(&balan);
                        if( aux != NULL){
                            if( aux->simb == 'p'){
                                    boolP = 1;
                            } else {
                                
                                if( aux->simb == 'c'){
                                    boolColc = 0;
                                } else if( aux->simb == 'l') {
                                    boolCh = 0;
                                    
                                }
                                
                            }
                        } else {
                            boolP = 0;
                        }
                    }
                }
            
            //Controla colchetes
            // teste para não alterar um resultado ja negativo
            if( boolColc == 1){
                if( simb == '[' ){
                    contColc++;
                    balanC++;
                    
                    Empilha(&balan,'c');
                    
                } else if( simb == ']' ) {
                    contColc++;
                    balanC--;
                    aux = Desempilha(&balan);
                    if( aux != NULL){
                        if( aux->simb == 'c'){
                                boolColc = 1;
                        } else {
                            
                            if( aux->simb == 'p'){
                                boolP = 0;
                            } else if( aux->simb == 'l') {
                                boolCh = 0;
                                
                            }
                            
                        }
                    } else {
                        boolColc = 0;
                    }
                }
            }
            
            
            // teste para não alterar um resultado ja negativo
            if( boolCh == 1){
                if( simb == '{' ){
                    contCh++;
                    balanCh++;
                    
                    Empilha(&balan,'l');
                    
                } else if( simb == '}' ) {
                    contCh++;
                    balanCh--;
                    aux = Desempilha(&balan);
                    if( aux != NULL){
                        if( aux->simb == 'l'){
                                boolCh = 1;
                        } else {
                            
                            if( aux->simb == 'c'){
                                boolColc = 0;
                            } else if( aux->simb == 'p') {
                                boolP = 0;
                                
                            }
                            
                        }
                    } else {
                        boolCh = 0;
                    }
                }
            }
            
           
           
        // mostra ao usuario resultado dos testes
        } else {
            printf("Balanceamento de ");
            if( (contP > 0) ) {
                if( boolP == 1 && (balanP == 1) ) {
                    printf("Parênteses=OK, ");
                } else {
                    printf("Parênteses=ERRADO, ");
                }
                
            } else {
                printf("Parênteses=(ND), ");
                
            }
            if( (contCh > 0) ){
                if( boolCh == 1 && (balanCh == 1) ){
                    printf(" Chaves=OK, ");
                } else {
                    printf(" Chaves=ERRADO, ");
                }
                
                
            } else {
                printf(" Chaves=(ND), ");
            }
            if( (contColc > 0) ){
                if( boolColc == 1 && (balanC == 1) ){
                    printf(" Colchetes=OK.");
                } else {
                    printf(" Colchetes=ERRADO.");
                }
            } else {
                printf(" Colchetes=(ND).");
            }
            
            puts("");
            /*
            
            printf("Chaves %d\n",boolCh);
            printf("Colchete %d\n",boolColc);
            printf("Parênteses %d\n",boolP);
            */
            aux = NULL;
            balan = NULL;
            contCh = 0;
            boolCh = 1;

            contP = 0;
            boolP = 1;

            contColc = 0;
            boolColc = 1;
            
            balanP = 1;
            balanCh = 1;
            balanC = 1;
        }
        
    }
        
    fclose(arqv);
    
    return 0;
}