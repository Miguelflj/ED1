

#include <stdio.h>
#include <stdlib.h>

struct estFila {
    int valor;
    struct estFila *prox;

};

typedef struct estFila tipoFila;



void InsereInicio(tipoFila **fila, int n);

void RemoveFim(tipoFila **fila);

tipoFila *PrimeiroElemento(tipoFila *fila);

void ImprimeFila(tipoFila *fila);

int Quantidade(tipoFila *fila);

int main(){
    tipoFila *fila,*aux;
    fila = NULL;
    int op,n;
    
    do{
        puts("Digite a opção:\n1-Inserção\n2-Remoção\n3-Primeiro elemento\n4-Quantidade de Ele.\n5-Imprimir fila\n0-Sair");
        scanf("%d", &op);
        system("clear");
        switch(op){
            case 1:
                puts("Digite um valor");
                scanf("%d",&n);
                InsereInicio(&fila,n);
                break;
            case 2:
                RemoveFim(&fila);
                break;
            case 3:
                aux = PrimeiroElemento(fila);
                if(aux == NULL){
                    puts("Fila vazia");
                } else {
                    printf("%d\n", aux->valor);
                }
                break;
            case 4:
                n = Quantidade(fila);
                printf("%d nó(s)\n",n);
                break;
            case 5:
                ImprimeFila(fila);
                break;
            default:
                break;
                
        }
        
    }while(op != 0);

    return 0;
}

void InsereInicio(tipoFila **fila, int n){
    tipoFila *novo;
    novo = (tipoFila*) malloc(sizeof(tipoFila));
    if(novo != NULL){ 
        novo->valor = n;
        novo->prox = (*fila);
        (*fila) = novo;
    }

}

void RemoveFim(tipoFila **fila){
    tipoFila *aux,*auxAnt;
        aux = *fila;
        if((*fila) == NULL){
            puts("Fila vazia");
        } else {
            if((*fila)->prox == NULL){
                (*fila) = NULL;
                free(aux);
                
            } else {
                while(aux->prox != NULL){
                    auxAnt = aux;
                    aux = aux->prox;
                }
                auxAnt->prox = NULL;
                free(aux);
            }
        }
}

tipoFila *PrimeiroElemento(tipoFila *fila){
    tipoFila *aux;
    if(fila == NULL){
        return NULL;
    } else { 
        aux = fila;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        return aux;
    }
    

}

int Quantidade(tipoFila *fila){
    tipoFila *aux;
    int cont = 0;
    aux = fila;
    while(aux != NULL){
            aux = aux->prox;
            cont++;
    }
    return cont;
}

void ImprimeFila(tipoFila *fila){
    int i;
    tipoFila *aux;
    if(fila == NULL){
        puts("Fila vazia");
    } else {
        aux = fila;
        while(aux != NULL){
            printf("pos=%d / valor= %d\n",i,aux->valor);
            i++;
            aux = aux->prox;
        }
        puts("Bank");
    }
}






