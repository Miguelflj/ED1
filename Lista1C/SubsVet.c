


#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main(){
    int vet[TAM], i;
    for(i=0;i<TAM;i++){
        scanf("%d", &vet[i]);
        if(vet[i] <= 0){
            vet[i] = 1 ;
        }

    }
    for(i=0;i<TAM;i++){
        printf("X[%d] = %d\n", i, vet[i]);




    }
    
    return 0;
    
}