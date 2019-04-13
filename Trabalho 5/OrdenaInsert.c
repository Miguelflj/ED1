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

void InsertSort(tipoLista *listaVet,long int *vetAux){
    int i, j,valor;
    long int contComp=0,contTroca=0;
    for(i=1; i < (listaVet)->qtd; i++){
        valor = (listaVet)->lista[i];
        j = i-1;
        while((j >= 0) && (valor < (listaVet)->lista[j])){
                contComp++;
                (listaVet)->lista[j+1] = (listaVet)->lista[j];
                j--;
                contTroca++;
        }
        contComp++;
        (listaVet)->lista[j+1] = valor;
    }
    vetAux[0] = contComp;
    vetAux[1] = contTroca;
}







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
    InsertSort(&listaVet,vetAux);
    
    fclose(arqv);

    //nome do arquivo que receberá valores ordenados
    arqv = fopen("nome_arquivo_output(ordenado insert).txt","w");
    if(arqv == NULL){
        printf("Erro na abertura do arquivo.\n");
    }
    for(i=0; i < listaVet.qtd; i++){
         fprintf(arqv,"%d\n", listaVet.lista[i]);
    }
    fprintf(arqv,"Comparações = %ld\n", vetAux[0]);
    fprintf(arqv,"Troca = %ld\n", vetAux[1]);

    fclose(arqv);
    

    return 0;
}

