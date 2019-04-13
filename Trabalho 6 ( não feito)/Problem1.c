

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct estNo{
    char nome[60];
    int idade;
    struct estNo *prox;
    struct estNo *ant;

};


typedef struct estNo tipoMeliante;


void InsereFim(tipoMeliante **lista,char name[], int n);
void InserePos(tipoMeliante **lista, int pos,char name[], int n);
void ImprimeLista(tipoMeliante *lista);
void removePos(tipoMeliante **lista, int pos);
void RemovePorNome(tipoMeliante **lista, char name[]);
void QuickSort(int vet[],int inicio,int fim);

int main(){
    tipoMeliante *lista,aux;
    lista = NULL;
    char name[60];
    int op,n,pos;
    do{
    puts("Tabela de periculosidade:\n 0 : quanto mais próximo ( mais dumal) \n quanto mais distante de 0 (menos dumal) ");
    puts("Digite a opção:\n1-Inserir sem periculosidade \n2-Inserir através da periculosidade\n3-Remover através do nome\n4-Remover através da periculosidade\n5-Listar por periculosidade\n6-Listar por idade (decrescente)\n0-Sair");
    scanf("%d", &op);
    system("clear");
    switch(op){
        case 1:
            puts("Digite o nome");
            scanf("%s",name);
            puts("Digite a idade");
            scanf("%d",&n);
            InsereFim(&lista,name,n);
            break;
        case 2:
            puts("Digite uma posição:");
            scanf("%d",&pos);
            puts("Digite o nome");
            scanf("%s",name);
            puts("Digite a idade");
            scanf("%d",&n);
            InserePos(&lista,pos,name,n);
            break;
        case 3:
            puts("Digite o nome do meliante");
            scanf("%s",name);
            RemovePorNome(&lista,name);
            break;
        case 4:
            puts("Digite a periculosidade do meliante");
            scanf("%d",&pos);
            removePos(&lista,pos);
            break;
        case 5:
            ImprimeLista(lista);
            break;
        case 6:
            
            break;
        default:
            break;
        
    }
    }while(op != 0);
    
    
    return 0;
}





void InsereFim(tipoMeliante **lista,char name[], int n){
    tipoMeliante *aux;
    tipoMeliante *novo;
    novo = (tipoMeliante*) malloc(sizeof(tipoMeliante));
    if(novo != NULL){

        strcpy(novo->nome, name); 
        novo->idade = n;
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

void InserePos(tipoMeliante **lista, int pos,char name[], int n){
    int cont;
    tipoMeliante *novo, *aux;
    novo = (tipoMeliante*) malloc(sizeof(tipoMeliante));
    if(novo != NULL){
        cont = 0;
        aux = (*lista);

        strcpy(novo->nome, name);
        novo->idade = n;
        novo->prox = NULL;
        novo->ant = NULL;
        while ( (cont < pos) && (aux != NULL)){
            cont++;
            aux = aux->prox;
        }
        if( (cont == pos) && (pos > 0) ){
            if( aux == NULL){
                InsereFim(lista,name,n);
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



void ImprimeLista(tipoMeliante *lista){
    int i=0;
    tipoMeliante *aux;
    if(lista == NULL){
        puts("Lista vazia");
    } else {
        aux = lista;
        while(aux != NULL){
            printf("Nivel de periculosidade: [%d] \n nome: %s \n idade : %d\n",i,aux->nome,aux->idade);
            i++;
            aux = aux->prox;
        }
    }
}


void removePos(tipoMeliante **lista, int pos){
    tipoMeliante *noRemover, novo;
    int cont;
    if((*lista) != NULL) {
        if (pos == 0) {
            if((*lista)->prox == NULL){
                noRemover = (*lista);
                (*lista) = NULL;
                free(noRemover);
            } else {
                noRemover = (*lista);
                (*lista)->prox->ant = NULL;
                (*lista) = (*lista)->prox;
                free(noRemover);
            }   
        } else {
            cont = 0;
            noRemover = (*lista);
            while ( (cont < pos) && (noRemover != NULL) ) {
                noRemover = noRemover->prox;
                cont++;
            }
            
            if( (cont == pos) && (noRemover->prox != NULL ) ) {
                noRemover->ant->prox = noRemover->prox;
                noRemover->prox->ant = noRemover->ant;
                free(noRemover);
            } else if((cont == pos) && (noRemover->prox == NULL)){
                noRemover->ant->prox = NULL;
                free(noRemover);
            }
        }
            
    } else {
        puts("A cidade ta uma belezura");
    }
}



void RemovePorNome(tipoMeliante **lista, char name[]){
    tipoMeliante *aux;

    if( (*lista) != NULL){
        aux = (*lista);
        if( strncmp(name, aux->nome, strlen(name))){
            if((*lista)->prox == NULL){
                (*lista) = NULL;
                free(aux);
            } else {
                (*lista) = (*lista)->prox;
                (*lista)->ant = NULL;
                free(aux);
            }
        }  else {
            while( ((aux->prox) != NULL) && strncmp(name, aux->nome, strlen(name))){
                aux = aux->prox;
            }

            if( (aux->prox != NULL) && (strncmp(name, aux->nome, strlen(name)))){
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                free(aux);

            } else if((strncmp(name, aux->nome, strlen(name))) && (aux->prox == NULL)) {
                aux->ant->prox = NULL;
                free(aux);
                
            }
        }
    } else {
        puts("A cidade ta uma belezura");

    }

}

/*
void QuickSort(int vet[],int inicio,int fim){
    int i,j,pivo,aux;
    i = inicio;
    j = fim;

    pivo = vet[((fim+inicio)/2)];
    
    while ( i <= j){
        
        if (vet[i] > pivo){
            i++;
        }else if( vet[j] < pivo){
            j--;
        }else{
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    
    }
    if(j > inicio){
        QuickSort(vet, 0, j);

    }
    if(i < fim){
        QuickSort(vet,j+1,fim);
    }
}



void ImprimePorIdade(tipoMeliante **lista){
        int *vet,n=0,i=0;
        tipoMeliante *aux;
        if( (*lista) != NULL){
            aux = (*lista);
            while( aux->prox != NULL){
                aux = aux->prox;
                n++;
            }
            vet = (int*) malloc(sizeof(int) * n);
            aux = (*lista);
            
            while( aux->prox != NULL){
                vet[i] = aux->idade;
                i++;
                aux = aux-prox;
            }
            QuickSort(vet,0,n-1);
            for(i=0; i < n; i++){
                    while(( aux->prox != NULL) && {
                        vet[i] = aux->idade;
                        i++;
                        aux = aux-prox;
                    }
                
            }
            
            
            
        } else {
          puts("A cidade ta uma belezura");   
        }
}


*/


