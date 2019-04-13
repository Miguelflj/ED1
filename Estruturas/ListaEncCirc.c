#include <stdio.h>
#include <stdlib.h>


//controla os nós da lista
struct estLista {
    int valor;
    struct estLista *prox;
};


typedef struct estLista tipoLista;







// funfando perfect
void InsereFim(tipoLista **lista, int n){
    tipoLista *aux;
    tipoLista *novo;
    novo = (tipoLista*) malloc(sizeof(tipoLista));
    if(novo != NULL){

        novo->valor = n;
       

        if( (*lista) == NULL ){
             novo->prox = novo;
            *lista = novo;
            
        } else {
            
            novo->prox = (*lista);
            aux = *lista;
            
            while( aux->prox != (*lista)){
                aux = aux->prox;
            }   
            
            aux->prox = novo;
           
            
            (*lista) = novo;
        }
    }
}



// funfando beleuza
void InsereInicio(tipoLista **lista, int n){
    tipoLista *novo,*aux;
    novo = (tipoLista*) malloc(sizeof(tipoLista));
    aux = (*lista);
    if(novo != NULL){ 
        
        if((*lista) == NULL){
            novo->valor = n;
            novo->prox = novo;
            (*lista) = novo;
        } else {
            novo->valor = n;
            novo->prox = (*lista);
            
            while( aux->prox != (*lista) ){
                    aux = aux->prox;
            }
            aux->prox = novo;
            (*lista) = novo;
        }
    }

}
//nao ta funfando
void InserePos(tipoLista **lista, int pos, int n){
    int cont;
    tipoLista *novo, *aux, *auxAnt;
    novo = (tipoLista*) malloc(sizeof(tipoLista));
    if(novo != NULL){
        cont = 0;
        aux = (*lista);
        novo->valor = n;
        while ( (cont < pos) && (aux != NULL)){
            cont++;
            auxAnt = aux;
            aux = aux->prox;
        }
        if( (cont == pos) && (pos > 0) ){
            novo->prox = aux;
            auxAnt->prox = novo;
        } else if (pos == 0) {
            novo->prox = (*lista);
            (*lista) = novo;
        }
    }
}

//rapaz.. funfa quando quer(midira, funfa sim)
tipoLista *BuscaPos(tipoLista *lista,int pos){
    int cont = 0;
    tipoLista *aux;
    aux = lista;
    while(aux != (lista)){
        if(cont == pos){
            return aux;
        }
        aux = aux->prox;
        cont++;
    }
    return NULL;
}

//igual a de cima so que diferente
tipoLista *BuscaValor(tipoLista *lista,int vlr){
    tipoLista *aux;
    aux = lista;
    while(aux != (lista)){
        if(aux->valor == vlr){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}
//funfa com muito esforço
void RemoveInicio(tipoLista **lista){
    tipoLista *noRemover,*aux;
    aux = (*lista);
    noRemover = (*lista);
    if((*lista) == NULL){
        puts("Lista vazia");
    } else {
        if((*lista)->prox == (*lista)){
            (*lista) = NULL;
            free(noRemover);
        } else {
            while( aux->prox != (*lista)){
                    aux = aux->prox;
            }
            aux->prox = (*lista)->prox;
            (*lista) = (*lista)->prox;
            free(noRemover);
        }
    }
}
//funfou depois de muita peia
void RemoveFim(tipoLista **lista){
    tipoLista *aux,*auxAnt;
        aux = *lista;
        if((*lista) == NULL){
            puts("Lista vazia");
        } else {
            if((*lista)->prox == (*lista)){
                (*lista) = NULL;
                free(aux);
                
            } else {
                while(aux->prox != (*lista)){
                    auxAnt = aux;
                    aux = aux->prox;
                }
                auxAnt->prox = (*lista);
                free(aux);
            }
        }
}

//funfa
void ImprimeLista(tipoLista *lista){
    int i;
    tipoLista *aux;
    if(lista == NULL){
        puts("Lista vazia");
    } else {
        aux = lista;
        
        while(aux->prox != lista){
           printf("/ valor= %d / [%ld]    [%ld]\n",aux->valor,aux->prox, aux);
            i++;
            aux = aux->prox;
        }
        printf("/ valor= %d / [%ld]    [%ld]\n",aux->valor,aux->prox, aux);
    }
}


void removePos(tipoLista **lista, int pos){
    tipoLista *aux, *noRemover;
    int cont;
    if( (*lista) != NULL){
        if (pos == 0) {
           RemoveInicio(lista);
        } else {
            cont = 0;
            noRemover = (*lista);
            while ( (cont < pos) && (noRemover != NULL) ) {
                aux = noRemover;
                noRemover = noRemover->prox;
                cont++;
            }
            
            if( (cont == pos) && (noRemover != NULL ) ) {
                aux->prox = noRemover->prox;
                free(noRemover);
                noRemover = NULL;
            }
            
        }
    }
}


int main(){
    tipoLista *lista,*aux;
    lista = NULL;
    int op,n,pos;
    do{
    puts("Digite a opção:\n1-Ins. no inicio\n2-Ins. no fim\n3-Ins. posição especifica\n4-Rem. no inicio\n5-Rem. Fim\n6-Rem. Especifico.\n7-Rem. por valor\n8-Busca por posição\n9-Busca por valor\n10-Imprime Lista\n0-Sair");
    scanf("%d", &op);
    system("clear");
    switch(op){
        case 1:
            puts("Digite um valor");
            scanf("%d",&n);
            InsereInicio(&lista,n);
            break;
        case 2:
            puts("Digite um valor");
            scanf("%d",&n);
            InsereFim(&lista,n);
            break;
        case 3:
            puts("Digite a posicao");
            scanf("%d",&pos);
            puts("Digte o valor");
            scanf("%d",&n);
            InserePos(&lista,pos,n);
            break;
        case 4:
            RemoveInicio(&lista);
            break;
        case 5:
            RemoveFim(&lista);
            break;
        case 6:
            puts("digite a posicao a ser removida");
            scanf("%d",&pos);
            removePos(&lista,pos);
            
            break;
        case 8:
            puts("Digite uma posição");
            scanf("%d",&pos);
            aux = BuscaPos(lista,pos);
            printf("%d\n",aux->valor);
            break;
        case 9:
            puts("Digite um valor");
            scanf("%d",&n);
            aux = BuscaValor(lista,n);
            if( aux == NULL){
                puts("valor invalido");
            } else {
                printf("%d\n",aux->valor);
            }
            break;
        case 10:
            ImprimeLista(lista);
        default:
            break;
        
    }
    }while(op != 0); 
    
    return 0;
}
