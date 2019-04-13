//Lista ED1 - Ivairton




#include <stdio.h>
#include <stdlib.h>

//#include <shellsort.c>

#define MAX 10




#ifndef _TIPO_LISTA_
#define _TIPO_LISTA_
// definicao de tipos
typedef struct tipoLista{
    int lista[MAX];
    int qtd;
    
    
}tipoLista;
#endif

// opção 1 funfo
void InsereNoInicio(tipoLista *listaVet,int valor){
    int i;
    if((listaVet)->qtd < MAX){
        if((listaVet)->qtd > 0){
            for(i=(listaVet)->qtd;i>0;i--){
                (listaVet)->lista[i] = (listaVet)->lista[i-1];
            }
        }
        (listaVet)->lista[0] = valor;
        (listaVet)->qtd++;
    }else{
        puts("Vetor cheio");
    }
}

//opção 2 funfo
void InsereNoFim(tipoLista *listaVet, int valor){
    int i=0;
    if((listaVet)->qtd < MAX){
        (listaVet)->lista[(listaVet)->qtd] = valor;
        (listaVet)->qtd++;
    }else{
        puts("Lista cheia");
    }
}

// opção 3 funfo
void InserePosicao(tipoLista *listaVet,int pos, int valor){
    int i;
    if((listaVet)->qtd < MAX){
        if(pos < (listaVet)->qtd){
            for(i=(listaVet)->qtd;i > pos; i--){
                (listaVet)->lista[i] = (listaVet)->lista[i-1];
            }
            (listaVet)->lista[pos] = valor;
            (listaVet)->qtd++;
        }else if(pos == (listaVet)->qtd){
                (listaVet)->lista[pos] = valor;
                (listaVet)->qtd++;
        }else{
            puts("Posição invalida");
        }
    }else{
        puts("Lista cheia");
        
    }
}

//opção 4 funfo
void RemoveInicio(tipoLista *listaVet){
    int i;
        if((listaVet)->qtd > 0){
            for(i=0;i<(listaVet)->qtd-1;i++){
                (listaVet)->lista[i] = (listaVet)->lista[i+1]; 
            }
            (listaVet)->qtd--; 
        }else{
            puts("Lista vazia");
        }
}

// opção 5 funfo
void RemoveFim(tipoLista *listaVet){
    if((listaVet)->qtd > 0){
        (listaVet)->lista[(listaVet)->qtd-1] = 0;
        (listaVet)->qtd--;
    }else{
        puts("Lista vazia");
    }
}

// opção 6 funfo
void RemoveEspec(tipoLista *listaVet,int pos){
    int i;
    if((listaVet)->qtd > 0){
        if((listaVet)->lista[pos] != 0){
            for(i=pos;i<(listaVet)->qtd;i++){
                (listaVet)->lista[i] = (listaVet)->lista[i+1];
                
            }
            (listaVet)->qtd--;
            
        }else{
            puts("Posição invalida");
        }
    }else{
        puts("Lista vazia");
    }
    
    
}
//opção 7 funfo
void RemovePorValor(tipoLista *listaVet,int valor){
    int i,controle=0,pos;
    if((listaVet)->qtd > 0){
        for(i=0;i<MAX;i++){
            if((listaVet)->lista[i] == valor){
                pos = i;
                controle = 1;
                i = MAX;
            }
        }
        for(i=pos;i<(listaVet)->qtd-1;i++){
                (listaVet)->lista[i] = (listaVet)->lista[i+1];
                (listaVet)->lista[i+1] = 0;
            }
        (listaVet)->qtd--;
        if(controle == 0){
            puts("Valor nao encontrado");
        }
    }else{
        puts("Lista vazia");
    }
    
}
// opção 8 funfo
int BuscaPos(tipoLista *listaVet, int pos){
    int i;
    if((listaVet)->qtd > 0){
        if(pos < (listaVet)->qtd){
            return (listaVet)->lista[pos];
        }else{
            puts("Posição invalida");
        }
    }else{
        puts("Lista vazia");
    }
}

// opção 9 com custo, mas funfou
int BuscaPorValor(tipoLista *listaVet,int valor){
    int i;
    if((listaVet)->qtd == 0){
        puts("Lista vazia");
        return 0;
    }
    for(i = 0; i < (listaVet)->qtd; i++){
        if((listaVet)->lista[i] == valor){
            return i;
        }
    }
    puts("Valor nao encontrado");
    return 0;
}
    
//opção 10 funfo
void ImprimeLista(tipoLista *listaVet){
    int i;
    for(i=0;i<MAX;i++){
        printf("[%d] ", (listaVet)->lista[i]);
        
    }
    puts("");
    
}
        
    
    

    

int main(){
    int op,valor,i,pos=0,funfa=0;
    tipoLista listaVet;
    //inicializa lista
    listaVet.qtd = 0;
    for(i=0;i<MAX;i++){
        listaVet.lista[i] = 0;
    }
    do{
    puts("Digite a opção:\n1-Ins. no inicio\n2-Ins. no fim\n3-Ins. posição especifica\n4-Rem. no inicio\n5-Rem. Fim\n6-Rem. Especifico.\n7-Rem. por valor\n8-Busca por posição\n9-Busca por valor\n10-Imprime Lista\n11-Ordenar Lista\n0-Sair");
    scanf("%d", &op);
    system("clear");
    switch(op){
        
        case 1:
        case 2:
            puts("Digite um valor: ");
            scanf("%d", &valor);
            if(op == 1)
                InsereNoInicio(&listaVet,valor);
            else
                InsereNoFim(&listaVet,valor);
            break;
        
            /*
            puts("Digite um valor: ");
            scanf("%d",&valor);
            InsereNoFim(&listaVet,valor);
            
            break;
            */
        case 3:
            
            puts("Digite a posição");
            scanf("%d", &pos);
            puts("Digite o valor");
            scanf("%d", &valor);
            InserePosicao(&listaVet,pos,valor);
            
            break;
        case 4:
            
            RemoveInicio(&listaVet);
            break;
        case 5:
            
            RemoveFim(&listaVet);
            break;
        case 6:
            puts("Digite a posição");
            scanf("%d", &pos);
            RemoveEspec(&listaVet,pos);
            break;
        case 7:
            
            puts("Digite valor");
            scanf("%d", &valor);
            RemovePorValor(&listaVet,valor);
            break;
        case 8:
            
            puts("Digite uma posição");
            scanf("%d", &pos);
            valor = BuscaPos(&listaVet,pos);
            printf("%d\n", valor);
            break;
        case 9:
            
            puts("Digite um valor");
            scanf("%*c");
            scanf("%d", &valor);
            scanf("%*c");
            funfa = BuscaPorValor(&listaVet,valor);
            if(funfa != 0){
                printf("%d\n", funfa);
            }
            break;
        case 10:
            
            ImprimeLista(&listaVet);
            break;
       // case 11:
         //   shellsort(&listaVet);
           // break;
        default:
            break;
        
    }
    }while(op != 0); 
    


    return 0;
}
    
    
