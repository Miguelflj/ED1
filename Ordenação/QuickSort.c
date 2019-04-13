#include <stdio.h>
#include <stdlib.h>


void QuickSort(int vet[],int inicio,int fim){
    int i,j,pivo,aux;
    i = inicio;
    j = fim;

    pivo = vet[((fim+inicio)/2)];
    
    while ( i <= j){
        
        if (vet[i] < pivo){
            i++;
        }else if( vet[j] > pivo){
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


int main(){
    int vet[10],i;
    for(i=0; i < 10; i++){
            scanf("%d",&vet[i]);
        
    }
    QuickSort(vet, 0,9);
    for(i=0; i < 10; i++){
        printf("[%d]",vet[i]);
    }
    puts("");
    
    return 0;
}