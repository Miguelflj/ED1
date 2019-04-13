
#include <stdio.h>
#include <stdlib.h>
#define TAM 1000


typedef struct lista{
    int vet[TAM];
    
}lista;


int main(){
    long int menorPos, contComp=0,contTroca=0,aux;
    int i,j;
    int vetAux[TAM];
    for (i = 0; i < TAM-1; i++){
        menorPos = i;
        for (j = i+1; j < MAX; j++){
            contComp++;
            if (L.vet[j] < L.vet[menorPos]){
                menorPos = j;
            }
        
        
        }
        contTroca++;
        aux = L.vet[i];
        L.vet[i] = L.vet[menorPos];
        L.vet[menorPos] = aux;
    }
    vetAux[0] = contComp;
    vetAux[1] = contTroca;

    return 0;
}