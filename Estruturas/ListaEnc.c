/* insere fim 
    insere posicao
    busca por posição/valor

remove inicio 
remove fim 
remove valor
remove posicao
*/

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
        novo->prox = NULL;

        if( (*lista) == NULL ){
            *lista = novo;
        } else {
            aux = *lista;
            while( aux->prox != NULL){
                aux = aux->prox;
            }   
            aux->prox = novo;
        }
    }
}
// funfando beleuza
void InsereInicio(tipoLista **lista, int n){
    tipoLista *novo;
    novo = (tipoLista*) malloc(sizeof(tipoLista));
    if(novo != NULL){ 
        novo->valor = n;
        novo->prox = *lista;
        (*lista) = novo;
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
    while(aux != NULL){
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
    while(aux != NULL){
        if(aux->valor == vlr){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}
//funfa com muito esforço
void RemoveInicio(tipoLista **lista){
    tipoLista *aux;
    aux = (*lista);
    if((*lista) == NULL){
        puts("Lista vazia");
    } else {
        if((*lista)->prox == NULL){
            (*lista) = NULL;
            free(aux);
        } else {
            (*lista) = (*lista)->prox;
            free(aux);
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
            if((*lista)->prox == NULL){
                (*lista) = NULL;
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

//funfa
void ImprimeLista(tipoLista *lista){
    int i;
    tipoLista *aux;
    if(lista == NULL){
        puts("Lista vazia");
    } else {
        aux = lista;
        while(aux != NULL){
            printf("pos=%d / valor= %d\n",i,aux->valor);
            i++;
            aux = aux->prox;
        }
    }
}


tipoLista removePos(tipoLista **lista, int pos){
    tipoLista *aux, *noRemover, noCopia;
    int cont;
    
    if (pos == 0) {
        noRemover = (*lista);
        noCopia = *noRemover;
        (*lista) = (*lista)->prox;
        free(noRemover);
        return noCopia;
    } else {
        cont = 0;
        noRemover = (*lista);
        while ( (cont < pos) && (noRemover != NULL) ) {
            aux = noRemover;
            noRemover = noRemover->prox;
            cont++;
        }
        
        if( (cont == pos) && (noRemover != NULL ) ) {
            noCopia = *noRemover;
            aux->prox = noRemover->prox;
            free(noRemover);
            noRemover = NULL;
            return noCopia;
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
            *aux = removePos(&lista,pos);
            if( aux == NULL){
                puts("posição invalida");   
            } else {
                printf("%d\n",aux->valor);
            }
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
            break;
        default:
            break;
        
    }
    }while(op != 0); 
    
    return 0;
}


















