
#include <stdio.h>
#include <stdlib.h>

int main(){
    int tam, *vet, i, menor, pos;
    scanf("%d", &tam);
    vet = (int*)(malloc(tam*sizeof(int)));
    for(i=0;i<tam;i++){
        scanf("%d", &vet[i]);
        
    }
    menor = vet[0];
    pos = 0;
    for(i=0;i<tam;i++){
        if(menor > vet[i]){
            menor = vet[i];
            pos = i;

        }


    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", pos);




return 0;
} 