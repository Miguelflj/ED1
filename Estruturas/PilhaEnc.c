
#include <stdio.h>
#include <stdlib.h>

struct estPilha {
    int valor;
    struct estPilha *prox;

};

typedef struct estPilha tipoPilha;


void Empilha(tipoPilha **pilha, int n);

tipoPilha *Desempilha(tipoPilha **pilha);

void ImprimePilha(tipoPilha *pilha);


int main(){
    tipoPilha *pilha, *aux;
    pilha = NULL;
    int op, n;
    do{
        puts("Digite a opção:\n1-Empilhar\n2-Desempilha\n3-Topo\n4-Imprime\n0-Sair");
        scanf("%d",&op);
        system("clear");
        switch(op){
            case 1:
                puts("Digite um valor:");
                scanf("%d", &n);
                Empilha(&pilha,n);
                break;
            case 2:
                aux = Desempilha(&pilha);
                if( aux == NULL){
                    puts("Pilha vazia");
                } else {
                    printf("%d\n",aux->valor);
                    free(aux);
                }
                break;
            case 3:
                if(pilha == NULL){
                    puts("Pilha vazia");
                } else {
                    printf("Topo: %d\n", pilha->valor);
                }
                break;
            case 4:
                ImprimePilha(pilha);
                break;
            default:
                break;
            
        }
    }while(op != 0);



    return 0;
}


void Empilha(tipoPilha **pilha, int n){
    tipoPilha *novo;
    novo = (tipoPilha*) malloc(sizeof(tipoPilha));
    if(novo != NULL){ 
        novo->valor = n;
        novo->prox = *pilha;
        (*pilha) = novo;
    }

}

tipoPilha *Desempilha(tipoPilha **pilha){
    tipoPilha *aux;
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

void ImprimePilha(tipoPilha *pilha){
    int i;
    tipoPilha *aux;
    if(pilha == NULL){
        puts("Pilha vazia");
    } else {
        aux = pilha;
        while(aux != NULL){
            printf("pos=%d / valor= %d\n",i,aux->valor);
            i++;
            aux = aux->prox;
        }
    }
}



