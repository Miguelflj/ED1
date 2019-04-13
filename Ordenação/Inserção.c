

#include <stdio.h>
#include <stdlib.h>

/*metodo de ordenação por ordenação em inserção
 * 
 * 
 * miguel freitas
 * 
 */

#define MAX 10

void InsertSort(int vet[]){
    int i, j,valor;
    for(i=1; i < MAX; i++){
        valor = vet[i];
        j = i-1;
        while((j >= 0) && (valor < vet[j])){
                vet[j+1] = vet[j];
                j--;
        }
        
    
        vet[j+1] = valor;
    }
    
}


int main(){
    int i,vet[MAX];
    for(i=0; i<MAX; i++){
        scanf("%d",&vet[i]);
    }
    InsertSort(vet);
    for(i=0; i<MAX; i++){
        printf("[%d]",vet[i]);
    }
    puts("");
    
    
    
    return 0;
}