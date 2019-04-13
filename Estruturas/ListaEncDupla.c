

#include <stdio.h>
#include <stdlib.h>



struct estNo{

    int valor;
    struct estNo *prox;
    struct estNo *ant;

};


typedef struct estNo tipoNo;

void InsereInicio(tipoNo **lista, int n);
void InsereFim(tipoNo **lista, int n);
void RemoveInicio(tipoNo **lista);
void InserePos(tipoNo **lista, int pos, int n);
void RemoveFim(tipoNo **lista);
void ImprimeLista(tipoNo *lista);
tipoNo removePos(tipoNo **lista, int pos);

int main(){
    tipoNo *lista,aux;
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
            aux = removePos(&lista,pos);
            if( (aux.valor == -1)){
                puts("posição invalida");   
            } else {
                printf("%d\n",aux.valor);
            }
            break;
        /*case 8:
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
            */
        case 10:
            ImprimeLista(lista);
        default:
            break;
        
    }
    }while(op != 0);
    
    
    return 0;
}



void InsereInicio(tipoNo **lista, int n){
    tipoNo *novo;
    novo = (tipoNo*) malloc(sizeof(tipoNo));
    if(novo != NULL){
        novo->prox = NULL;
        novo->valor = n;
        novo->ant = NULL;
        if((*lista) != NULL){  
            novo->prox = *lista;
            (*lista)->ant = novo;
            (*lista) = novo;
        } else {
             *lista = novo;
        }

    }
}

void InsereFim(tipoNo **lista, int n){
    tipoNo *aux;
    tipoNo *novo;
    novo = (tipoNo*) malloc(sizeof(tipoNo));
    if(novo != NULL){

        novo->valor = n;
        novo->prox = NULL;
        novo->ant = NULL;

        if( (*lista) == NULL ){
            *lista = novo;
        } else {
            aux = *lista;
            while( aux->prox != NULL){
                aux = aux->prox;
            }   
            aux->prox = novo;
            novo->ant = aux;
        }
    }
}

void InserePos(tipoNo **lista, int pos, int n){
    int cont;
    tipoNo *novo, *aux;
    novo = (tipoNo*) malloc(sizeof(tipoNo));
    if(novo != NULL){
        cont = 0;
        aux = (*lista);
        novo->valor = n;
        novo->prox = NULL;
        novo->ant = NULL;
        while ( (cont < pos) && (aux != NULL)){
            cont++;
            aux = aux->prox;
        }
        if( (cont == pos) && (pos > 0) ){
            if( aux == NULL){
                InsereFim(lista,n);
            } else {
                aux->ant->prox = novo;
                novo->prox = aux;
                novo->ant = aux->ant;
                aux->ant = novo;
            }
        } else if (pos == 0) {
            if((*lista) == NULL){
                novo->prox = (*lista);
                (*lista) = novo;
            } else {
                novo->prox = (*lista);
                (*lista)->ant = novo;
                (*lista) = novo;
            }
        }
    }
}


void RemoveInicio(tipoNo **lista){
    tipoNo *aux;
    aux = (*lista);
    if((*lista) == NULL){
        puts("Lista vazia");
    } else {
        if((*lista)->prox == NULL){
            (*lista) = NULL;
            free(aux);
        } else {
            (*lista) = (*lista)->prox;
            (*lista)->ant = NULL;
            free(aux);
        }
    }
}


void RemoveFim(tipoNo **lista){
    tipoNo *aux,*auxAnt;
        aux = *lista;
        if((*lista) == NULL){
            puts("Lista vazia");
        } else {
            if((*lista)->prox == NULL){
                (*lista) = NULL;
                free(aux);
                
            } else {
                while(aux->prox != NULL){
                    aux = aux->prox;
                }
                aux->ant->prox = NULL;
                free(aux);
            }
        }
}

void ImprimeLista(tipoNo *lista){
    int i=0;
    tipoNo *aux;
    if(lista == NULL){
        puts("Lista vazia");
    } else {
        aux = lista;
        while(aux != NULL){
            printf("pos[%d] / valor= [%d]\n",i,aux->valor);
            i++;
            aux = aux->prox;
        }
    }
}


tipoNo removePos(tipoNo **lista, int pos){
    tipoNo *noRemover, noCopia, novo;
    int cont;
    novo.valor = -1;
    if((*lista) != NULL) {
        if (pos == 0) {
            if((*lista)->prox == NULL){
                noRemover = (*lista);
                noCopia = *noRemover;
                (*lista) = NULL;
                free(noRemover);
                return noCopia;
            } else {
                noRemover = (*lista);
                noCopia = *noRemover;
                (*lista)->prox->ant = NULL;
                (*lista) = (*lista)->prox;
                free(noRemover);
                return noCopia;
            }   
        } else {
            cont = 0;
            noRemover = (*lista);
            while ( (cont < pos) && (noRemover != NULL) ) {
                noRemover = noRemover->prox;
                cont++;
            }
            
            if( (cont == pos) && (noRemover->prox != NULL ) ) {
                noCopia = *noRemover;
                noRemover->ant->prox = noRemover->prox;
                noRemover->prox->ant = noRemover->ant;
                free(noRemover);
                noRemover = NULL;
                return noCopia;
            } else if((cont == pos) && (noRemover->prox == NULL)){
                noCopia = *noRemover;
                noRemover->ant->prox = NULL;
                free(noRemover);
                noRemover = NULL;
                return noCopia;
            }
        }
            
    } else {
        return novo;
    }
    return novo;
}