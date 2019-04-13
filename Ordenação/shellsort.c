
/* metodo de ordenação shell sort
 * 
 * 
 * miguel freitas
 * 
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#define TAM 1000

typedef struct lista{
    int vet[TAM];
    
}lista;

int main(){

    FILE *arq;
    int troca = 1,salto;
    lista L;
    salto = TAM/2;
    int i, j, aux;

    arq = fopen("1000-arq1.txt","r");
    i = 0;
    while(fscanf(arq,"%d\n",&aux) != EOF){
        L.vet[i] = aux;
        i++;
    }
    while(troca == 1){
        troca = 0;
        for(i=0; i < TAM; i++){
            if( (salto+i) < TAM){
                if(L.vet[i] > L.vet[i+salto]){
                    aux = L.vet[i];
                    L.vet[i] = L.vet[salto+i];
                    L.vet[salto+i] = aux;
                    troca = 1;
                }
            }
                
        }
        salto = salto/2;
        if(salto%2 ==0 ){
            salto++;
        }else{
            salto = 1;
        }
    }
    for(i = 0 ; i < TAM; i++){
        printf("%d\n",L.vet[i]);
    }
}

