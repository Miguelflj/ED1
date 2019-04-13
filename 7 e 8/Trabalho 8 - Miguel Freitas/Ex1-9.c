
/*
 Estrutura de dados 1 - UFMT
Professor: Ivairton
Miguel Freitas 
Exercício 1-9 (Trabalho 8 - Final)
*/




#include <stdio.h>
#include <stdlib.h>

typedef struct stackP{
    char l;
    struct stackP *prox;

}stackP;

//protótipos das funções
void Empilha(stackP **pilha, char letra);
stackP *Desempilha(stackP **pilha);

void Empilha(stackP **pilha, char letra){
    stackP *novo;
    novo = (stackP*) malloc(sizeof(stackP));
    if(novo != NULL){ 
        novo->l = letra;
        novo->prox = *pilha;
        (*pilha) = novo;
    }

}



stackP *Desempilha(stackP **pilha){
    stackP *aux;
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

    stackP *P,*aux;
    P = NULL;
    
    char simb,pali[100],vetL[50];
    int cont,i;
    int  bool, contLe,avisoInd;
    
    FILE *arqv;
    //abre o arquivo
    arqv = fopen("ex1Pali.txt","r");
    if(arqv == NULL){
        printf("Erro na abertura do arquivo.\n");
    }
    
    cont = 0;
    contLe = 0;
    avisoInd = 1;

    // realiza a leitura dos caracters dentro do arquivo
    while( fscanf(arqv,"%c", &simb) != EOF){


        if( simb != '\n'){
            //guarda caracters até o espaço
            if( simb != ' '){
                pali[cont++] = simb;
            }
        } else {

            // empilhando os caracters na estrutura
            for( i = 0; i < cont ; i++) {
                Empilha(&P,pali[i]);
                
            }
            
            for( i = 0 ; i < cont; i++){
                aux = Desempilha(&P);
                if( aux->l == pali[i] ){
                    if( (aux->l == '*') && (pali[i] == '*') ){
                        // caso de indeterminação
                        bool = 0;
                        cont = 0;
                        avisoInd = 0;
                    } else {
                        // ainda definindo como palindrome
                        bool = 1;
                    }
                    
                } else {
                    
                    if( (aux->l != '*')  && (pali[i] == '*') ){
                        // ainda palindrome e de possivel definiçao
                        
                        /* como a logica usada observa toda a frase novamente, se
                         * não usado essa tecnica de olhar somente metade nesses casos
                         * ocorre repetição de letras como coringas, fazendo o teste inverso
                         */
                        
                        if( i <= (cont/2) ){
                            bool = 1;
                            vetL[contLe++] = aux->l;
                        }
                            
                               
                    } else if ( (aux->l == '*') && (pali[i] != '*' ) ) {

                        if( i <= (cont/2) ){
                            bool = 1;
                            vetL[contLe++] = pali[i];
                        }
                        
                    } else {
                        bool = 0;
                        cont = 0;
                        
                    }
                    
                }
                
            }
            
            if(bool == 1){
                if(contLe > 0){
                    for(i = 0; i < contLe ; i++){
                        if(i == 0){
                            printf("É palíndrome - Letra(s): %c",vetL[i]);
                        } else{
                            printf(", %c",vetL[i]);
                        }
                        
                    }
                    puts("");
                } else {
                    puts("É palíndrome");
                }
                
            } else {
                if( avisoInd == 0){
                    puts("Indefinido (Impossível determinar letras)");
                    avisoInd = 1;
                } else {
                    puts("Não é palíndrome");
                }
            
            }
            cont = 0;
            contLe = 0;

        }
    
    }
    fclose(arqv);
    return 0;
}
