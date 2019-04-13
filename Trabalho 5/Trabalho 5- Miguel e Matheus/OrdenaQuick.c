/*  UFMT - Ciencia da Computação
 * Estrutura de Dados 1
 * Professor Ivairton
 * 
 * Trabalho 5 - Metodos de ordenação ( 27 nov 2017)
 */



#include <stdio.h>
#include <stdlib.h>

// MAX recebe valor de acordo com a quantidade de valores do arquivo de entrada.
#define MAX 1000


typedef struct tipoLista{
    int lista[MAX];
    int qtd;
    
}tipoLista;



void QuickSort(tipoLista *listaVet,int inicio,int fim,long int *vetAux){
    int i,j;
    
    int aux, pivo,pos;
    long int contComp=0, contTroca=0;
    i = inicio;
    j = fim;
    pos = (((fim+inicio)/2));
    pivo = (listaVet)->lista[pos];
    
    while ( i <= j){
            contComp++;
        if (((listaVet)->lista[i]) < pivo){
            i++;
            contComp++;
        }else if( ((listaVet)->lista[j]) > pivo){
            j--;
        }else{
            contTroca++;
            aux = (listaVet)->lista[i];
            (listaVet)->lista[i] = (listaVet)->lista[j];
            (listaVet)->lista[j] = aux;
            i++;
            j--;
        }
    
    }
    if(j > inicio){
        QuickSort(listaVet,inicio, j,vetAux);

    }
    if(i < fim){
        QuickSort(listaVet,j+1,fim,vetAux);
    }
    vetAux[0] = contComp;
    vetAux[1] = contTroca;
};





int main(){
    tipoLista listaVet;
    listaVet.qtd = 0;
    int n;
    long int vetAux[2];
    int i;
    FILE *arqv;
    //recebe nome de arquivo com valores desordenados
    // ex.: 1000-arq1.txt 
    arqv = fopen("nome_arquivo_input.txt","rt");
    if(arqv == NULL){
        printf("Erro na abertura do arquivo.\n");
    }
    i=0;
    while( fscanf(arqv,"%d",&n) != EOF){
        listaVet.lista[i++] = n;
        listaVet.qtd++;

    }
    
    fclose(arqv);
    
    QuickSort(&listaVet, 0 ,MAX-1,vetAux);
    ////nome do arquivo que receberá valores ordenado
    arqv = fopen("nome_arquivo_output(ordenado QuickSort).txt","w");
    if(arqv == NULL){
        printf("Erro na abertura do arquivo.\n");
    }
    for(i=0; i < MAX; i++){
         fprintf(arqv,"%d\n", listaVet.lista[i]);
    }
    fprintf(arqv,"Comparações = %ld\n", vetAux[0]);
    fprintf(arqv,"Troca = %ld\n", vetAux[1]);

    fclose(arqv);
    

    return 0;
}